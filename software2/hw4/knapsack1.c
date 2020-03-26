//バイナリファイルから読み込むプログラム
//標準入力からファイルとバックの最大積載量を指定して最適解を表示する。

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 個数の上限はあらかじめ定めておく
const int max_items = 1000;

// 以下は構造体の定義と関数のプロトタイプ宣言

// 構造体 itemset
// number分の価値value と 重さweight を格納しておく
// データをポインタで定義しており、mallocする必要あり
typedef struct itemset
{
  int number;
  double *value;
  double *weight;
} Itemset;

// 関数のプロトサイプ宣言

// Itemset *init_itemset(int, int);
//
// itemsetを初期化し、そのポインタを返す関数
// 引数:
//  品物の個数: number (int)
//  乱数シード: seed (int) // 品物の値をランダムにする
// 返り値:
//  確保されたItemset へのポインタ
Itemset *init_itemset(char *fname, const double W);

void free_itemset(Itemset *list);

// void print_itemset(const Itemset *list)
//
// Itemsetの内容を標準出力に表示する関数
void print_itemset(const Itemset *list);

// double solve()
//
// ソルバー関数: 指定された設定でナップサック問題をとく [現状、未完成]
// 引数:
//   品物のリスト: Itemset *list
//   ナップサックの容量: capacity (double)
//   実際にナップサックに入れた品物を記録するフラグ: flags (int*)
// 返り値:
//   最適時の価値の総和を返す
//
// * 引数のflags の中身が書き換わり、最適なflags になる [ようにする]
double solve(const Itemset *list, double capacity, int *flags);

// double search()
//
// 探索関数: 指定されたindex以降の組み合わせで、最適な価値の総和を返す
//  再帰的に実行する
// 引数:
//  指定index : index (int)
//  品物リスト: list (Itemset*)
//  ナップサックの容量: capacity (double)
//  実際にナップサックに入れた品物を記録するフラグ: flags (int*)
//  途中までの価値と重さ (ポインタではない点に注意): sum_v, sum_w
// 返り値:
//   最適時の価値の総和を返す
double search(int index, const Itemset *list, double capacity, int *flags, double sum_v, double sum_w);

// main関数
// プログラム使用例: ./knapsack 10 20
//  10個の品物を設定し、キャパ20 でナップサック問題をとく
int main (int argc, char**argv)
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

  // 品物を入れたかどうかを記録するフラグ配列
  int *flags = (int*)calloc(items->number, sizeof(int));

  // ソルバーで解く
  double total = solve(items, W, flags);

  // 表示する
  printf("----\nbest solution:\n");
  printf("value: %4.1f\n",total);

  return 0;
}

// 構造体をポインタで確保するお作法を確認してみよう
Itemset *init_itemset(char *fname,const double W)
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

// itemset の free関数
void free_itemset(Itemset *list)
{
  free(list->value);
  free(list->weight);
  free(list);
}

// 表示関数
void print_itemset(const Itemset *list)
{
  int n = list->number;
  for(int i = 0 ; i < n ; i++){
    printf("v[%d] = %4.1f, w[%d] = %4.1f\n", i, list->value[i], i, list->weight[i]);
  }
  printf("----\n");
}

// ソルバーは search を index = 0 で呼び出すだけ
double solve(const Itemset *list,  double capacity, int *flags)
{
  return search(0,list,capacity,flags, 0., 0.);
}

// 再帰的な探索関数
double search(int index, const Itemset *list, double capacity, int *flags, double sum_v, double sum_w)
{
  int max_index = list->number;
  assert(index >= 0 && sum_v >= 0 && sum_w >= 0);
  // 必ず再帰の停止条件を明記する (最初が望ましい)
  if (index == max_index){
    for (int i = 0 ; i < max_index ; i++){
      printf("%d", flags[i]);
    }
    printf(", total_value = %5.1f, total_weight = %5.1f\n", sum_v, sum_w);
    return sum_v;
  }

  // 以下は再帰の更新式: 現在のindex の品物を使う1 or 使わない0で分岐し、index をインクリメントして再帰的にsearch() を実行する
  
  flags[index] = 0;
  const double v0 = search(index+1, list, capacity, flags, sum_v, sum_w);

  flags[index] = 1;
  double v1 = v0;
  if (sum_w + list->weight[index] <= capacity) {
    v1 = search(index+1, list, capacity, flags, sum_v + list->value[index], sum_w + list->weight[index]);
  }

  // 使った場合の結果と使わなかった場合の結果を比較して返す
  return (v0 > v1) ? v0 : v1;
}




/*課題1は初めに品物数int、次に価値が品物数分double、その後重さが品物数分doubleで表される。
freadして品物数に応じてfreadする。*/