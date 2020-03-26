#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "encode.h"


// 各シンボルの数を数える為に
//このソースファイルでのみ有効なstatic な配列を設定
// 数を数える為に、1byteの上限+1で設定しておく
#define NSYMBOLS 256+1
static int num=0;
static int symbol_count[NSYMBOLS];
static int sym_code[NSYMBOLS];
static int symbols[NSYMBOLS];

typedef struct node
{
  int symbol;
  int count;
  struct node *left;
  struct node *right;
} Node;

static void count_symbols(const char *filename)
{
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "error: cannot open %s\n", filename);
    exit(1);
  }
  
  for (int i = 0; i < NSYMBOLS; i++) {
    symbol_count[i] = 0;
  }
  // 1Byteずつ読み込み、カウントする。ここを埋める。
  char tmp;
  while(fread(&tmp, sizeof(char), 1, fp) > 0)
  {
    int num_tmp=tmp;
    symbol_count[num_tmp]+=1;
  }

  // ファイル終端のみ特殊 (256) をカウント
  // 必ずしも必要ではないが
  symbol_count[NSYMBOLS-1]++; // End of File
  /*デバック用
  for (int i=0; i<NSYMBOLS; i++){
    printf("%c : %d\n", i, symbol_count[i]);
  }
  */

  fclose(fp);
}

static Node *pop_min(int *n, Node *nodep[])
{
  // Find the node with the smallest count
  // カウントが最小のノードを見つけてくる
  int argmin = 0;
  for (int i = 0; i < *n; i++) {
    if (nodep[i]->count < nodep[argmin]->count) {
      argmin = i;
    }
  }

  Node *node_min = nodep[argmin];

  // Remove the node pointer from nodep[]
  // 見つかったノード以降の配列を前につめていく
  for (int i = argmin; i < (*n) - 1; i++) {
    nodep[i] = nodep[i + 1];
  }
  // 合計ノード数を一つ減らす
  (*n)--;

  return node_min;
}

static Node *build_tree()
{
  int n = 0;
  Node *nodep[NSYMBOLS];

  for (int i = 0; i < NSYMBOLS; i++) {
    if (symbol_count[i] == 0) continue;
    nodep[n] = malloc(sizeof(Node));
    nodep[n]->symbol = i;
    nodep[n]->count  = symbol_count[i];
    nodep[n]->left   = NULL;
    nodep[n]->right  = NULL;
    symbols[n]=i;
    n++;
  }

  const int dummy = -1;//ダミー用のsymbolの割り当て、なんでも良い
  while (n >= 2) {
    Node *node1 = pop_min(&n, nodep);
    Node *node2 = pop_min(&n, nodep);

    // Create a new node
    // 選ばれた2つのノードを元に統合ノードを新規作成
    // 作成したノードはnodep にどうすればよいか?
    nodep[n] = malloc(sizeof(Node));
    nodep[n]->symbol = dummy;
    nodep[n]->count = node1->count + node2->count;
    nodep[n]->left = node1;
    nodep[n]->right = node2;
    n++;
  }
  //printf("%d\n", nodep[0]->right->right->right->count);
  return nodep[0];
}

// Perform depth-first traversal of the tree
// 深さ優先で木を走査する
static void traverse_tree(const int depth, const Node *np, int lr)//left:0, right:1
{
  if (lr==0){
    sym_code[depth-1]=0;
  }else if (lr==1){
    sym_code[depth-1]=1;
  }

  assert(depth < NSYMBOLS);

  if (np->left == NULL && np->right == NULL){
    if (symbols[num]==256){
      return;
    }
    printf("%d:", symbols[num]);
    num++;
    for (int i=0; i<depth;i++){
      printf("%d", sym_code[i]);
    }
    printf("\n");
    return;
  }

  traverse_tree(depth + 1, np->left, 0);
  traverse_tree(depth + 1, np->right, 1);
  
}

// この関数のみ外部 (main) で使用される (staticがついていない)
int encode(const char *filename)
{
  count_symbols(filename);
  Node *root = build_tree();
  traverse_tree(0, root, -1);

  return 1;
}
