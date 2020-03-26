//巡回セールスマン問題の山登り法での実装
//答えは以下の通りになる
//order of cities = 6 0 12 10 8 5 14 1 19 16 4 13 15 3 11 17 2 18 7 9
//total distance = 188.00

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>

// const による定数定義
const int width = 70;
const int height = 40;
const int max_cities = 1000;


// 町の構造体（今回は2次元座標）を定義
typedef struct
{
  int x;
  int y;
} City;

// 整数最大値をとる関数
int max(const int a, const int b)
{
  return (a > b) ? a : b;
}

// 以下は実装が長くなるのでプロトタイプ宣言
// draw_line: 町の間を線で結ぶ
// draw_route: routeでの巡回順を元に移動経路を線で結ぶ
// plot_cities: 描画する
// distance: 2地点間の距離を計算
// solove(): 巡回問題をといて距離を返す/ 引数route に巡回順を格納

void draw_line(char **map, City a, City b);
void draw_route(char **map, City *city, int n, const int *route);
void plot_cities(FILE* fp, char **map, City *city, int n, const int *route);
void rewrite(int *route, int *sub_route, int n);
double distance( City *city, int n, int *route);
double solve(City *city, int n, int *route);


int main(int argc, char**argv)
{
  FILE *fp = stdout; // とりあえず描画先は標準出力としておく
  if (argc != 2){
    fprintf(stderr, "Usage: %s <the number of cities>\n", argv[0]);
    exit(1);
  }
  const int n = atoi(argv[1]);
  assert( n > 1 && n <= max_cities); // さすがに都市数1000は厳しいので

  City *city = (City*) malloc(n * sizeof(City));
  char **map = (char**) malloc(width * sizeof(char*));
  char *tmp = (char*)malloc(width*height*sizeof(char));
  for (int i = 0 ; i < width ; i++)
    map[i] = tmp + i * height;

  /* 町の座標をランダムに割り当て */
  for (int i = 0 ; i < n ; i++){
    city[i].x = rand() % (width - 5);
    city[i].y = rand() % height;
  }
  // 町の初期配置を表示
  plot_cities(fp, map, city, n, NULL);
  sleep(1);

  // 訪れる順序を記録する配列を設定
  int *route = (int*)calloc(n, sizeof(int));

  const double d = solve(city, n, route);
  printf("order of cities =");
  for (int i=0; i<n; i++) {
    printf(" %d", route[i]);
  }
  printf("\ntotal distance = %f\n", d);
  plot_cities(fp, map, city, n, route);

  // 動的確保した環境ではfreeをする
  free(route);
  free(map[0]);
  free(map);
  free(city);
  
  return 0;
}

// 繋がっている都市間に線を引く
void draw_line(char **map, City a, City b)
{
  const int n = max(abs(a.x - b.x), abs(a.y - b.y));
  for (int i = 1 ; i <= n ; i++){
    const int x = a.x + i * (b.x - a.x) / n;
    const int y = a.y + i * (b.y - a.y) / n;
    if (map[x][y] == ' ') map[x][y] = '*';
  }
}

void draw_route(char **map, City *city, int n, const int *route)
{
  if (route == NULL) return;

  for (int i = 0; i < n; i++) {
    const int c0 = route[i];
    const int c1 = route[(i+1)%n];// n は 0に戻る必要あり
    draw_line(map, city[c0], city[c1]);
  }
}

void plot_cities(FILE *fp, char **map, City *city, int n, const int *route)
{
  fprintf(fp, "----------\n");

  memset(map[0], ' ', width * height); // グローバルで定義されたconst を使用

  // 町のみ番号付きでプロットする
  for (int i = 0; i < n; i++) {
    char buf[100];
    sprintf(buf, "C_%d", i);
    for (int j = 0; j < strlen(buf); j++) {
      const int x = city[i].x + j;
      const int y = city[i].y;
      map[x][y] = buf[j];
    }
  }

  draw_route(map, city, n, route);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      const char c = map[x][y];
      fputc(c, fp);
    }
    fputc('\n', fp);
  }
  fflush(fp);
}

void rewrite(int *route, int *sub_route, int n) {
  for (int i=0; i<n; i++) {
    sub_route[i]=route[i];
  }
}

double distance(City *city, int n, int *route)
{
  int sum_d = 0;
  for (int i=0; i<n-1; i++) {
    double dx = city[route[i]].x - city[route[i+1]].x;
    double dy = city[route[i]].y - city[route[i+1]].y;
    sum_d += sqrt(dx * dx + dy * dy);
  }
  double dx = city[route[n-1]].x - city[route[0]].x;
  double dy = city[route[n-1]].y - city[route[0]].y;
  sum_d += sqrt(dx * dx + dy * dy);
  return sum_d;
}

double solve(City *city, int n , int *route)
{
  route[0] = 0; // 循環した結果を避けるため、常に0番目からスタート

  // 訪れる順序を一時的に記録する配列を設定(中身は都市の番号で配列の左から順に回っていく)
  int *pre_route = (int*)calloc(n, sizeof(int));

  //山登りプログラムを実装する
  //一旦、初期解を決める。
  for (int i=0; i<n; i++) {
    route[i]=i;
  }
  rewrite(route, pre_route, n);
  int sign = 1;
  int pre_dist, dist;
  
  while (sign==1) {
    sign=0;
    for (int i=0; i<n-1; i++) {
      for (int j=i+1; j<n; j++){
        int t = pre_route[i];
        route[i] = pre_route[j];
        route[j] = t;
        pre_dist = distance(city, n, pre_route);
        dist = distance(city, n, route);
        if (dist<pre_dist) {
          rewrite(route, pre_route, n);
          sign=1;
        } else {
          rewrite(pre_route, route, n);
        }
      }
    }
  }
  if (pre_dist<dist) {
    dist=pre_dist;
  }
  return dist;
}
