//課題2
//動的計画法(DP)による解の探索
//概要：
//全体の結果を求める前に小さな部分集合の答えを求めていき、その答えを用いてさらにでかい集合での解の決定に用いる。
//それを繰り返し、最終的な答えをもとめる。(漸化式のようなもの)
//詳しい説明は適宜コードの中に書いた
//標準入力:品物数と最大積載量を指定する
//出力:最適解

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int max_items = 1000;

typedef struct itemset
{
  int number;
  double *value;
  double *weight;
} Itemset;

Itemset *init_itemset(char *fname, const double W);//itemsetを初期化してそのポインタを返す関数
void free_itemset(Itemset *list);
void print_itemset(const Itemset *list);// Itemsetの内容を標準出力に表示する関数
double solve(const Itemset *list, double capacity);

int main(int argc, char **argv)
{
  /* 引数処理: ユーザ入力が正しくない場合は使い方を標準エラーに表示して終了 */
  if (argc != 3){
    fprintf(stderr, "usage: %s <the name of binaryfile><max capacity (double)>\n",argv[0]);
    exit(1);
  }
  const double W = atof(argv[2]);

  //バイナリファイルの読み込みと初期化
  char *fname = argv[1];
  Itemset *items = init_itemset(fname, W);
  print_itemset(items);

  // ソルバーで解く
  double total = solve(items, W);

  // 表示する
  printf("----\nbest solution:\n");
  printf("value: %4.1f\n",total);

  return 0;
}


//構造体によるitemsetの初期化
Itemset *init_itemset(char *fname ,const double W)
{
  FILE *fp;
  printf("%s", fname);
  if ((fp = fopen(fname, "rb")) == NULL) {
        printf("%sのオープンに失敗\n", fname);
        exit(EXIT_FAILURE);
  }
  int number;
  fread(&number, 1, 4, fp);

  Itemset *list = (Itemset*)malloc(sizeof(Itemset));
  list->number = number;

  list->value = (double*)malloc(sizeof(double)*number);
  list->weight = (double*)malloc(sizeof(double)*number);

  fread(list->value, number, sizeof(double), fp);
  fread(list->weight, number, sizeof(double), fp);
  fclose(fp);

  printf("max capacity: W = %.f, # of items: %d\n",W, number);
  
  return list;
}

//itemsetのfree関数
void free_itemset(Itemset *list)
{
  free(list->value);
  free(list->weight);
  free(list);
}

//表示関数
void print_itemset(const Itemset *list)
{
  int n = list->number;
  for(int i = 0 ; i < n ; i++){
    printf("v[%d] = %4.1f, w[%d] = %4.1f\n", i, list->value[i], i, list->weight[i]);
  }
  printf("----\n");
}

//ソルバーによって最適解を返す
double solve(const Itemset *list,  double capacity)
{
  //品物の数がmax_number, 最大積載量がmax_capacity, dp_value[i][j]は品物数i重量制限jの時の最適解(価値)
  int max_number = list->number;
  int max_capacity = capacity;
  double dp[max_number+1][max_capacity+1];

  int i,j;
  for(i=0; i<=max_number; i++){//①iまたはjが0の時dp_valueは0(ここでは全部を0で初期化)
    for(j=0; j<=max_capacity ; j++){
      dp[i][j]=0;
    }
  }
  printf("DPtable(表内の数値は見やすい数値で表示している)\n |w ");
  printf("   0 ");
  for(i=1; i<=max_capacity; i++){
    printf("%4.0d ",i);
  }
  printf("\n");
  printf("-+-------------------------");
  printf("\nv|\n");
  for(i=0 ;i<=max_number ;i++){
    printf("%d|  ",i);
    for(j=0 ;j<=max_capacity; j++){
      if (i != 0 && j != 0){//②i,jが共に0でない時、tempはすべて候補値
        if (list->weight[i-1]>j){//(1)i番目の荷物が重量制限より重い時
          dp[i][j] = dp[i-1][j];
        } else {//(2)i番目の荷物が重量制限より軽い時(a)i番目を入れない(b)i番目を入れる
          double temp1 = dp[i-1][j];
          int sub = j - list->weight[i-1];
          double temp2 = dp[i-1][sub] + list->value[i-1];
          if (temp1 < temp2){
            dp[i][j] = temp2;
          } else {
            dp[i][j] = temp1;
          }
        }
      }
      printf("%4.0f ", dp[i][j]);
    }
    printf("\n");
  }
  return dp[max_number][max_capacity];
}

// i番目まで(1〜i番)の荷物を使って、重量制限をjとした時の最適解をここに格納すること