#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

/* 莉雁屓縺ｮ險ｭ螳壹ｒ讒矩菴薙〒險倩ｿｰ*/
struct condition
{
  int width; 
  int height;
  double G; // gravity constant
};
  
struct star
{
  double m;   // mass
  double x;   // position_x
  double y;   // position_y
  double vx;  // velocity_x
  double vy;  // velocity_y
};

struct star stars[] = {
  { 1.0, -20.0, 0.0 , 0.0,  0.0},
  { 0.5,  30.0, 0.0 , -0.5, 0.0},//簡単のため物体は2として、y座標の運動を無視できるような値設定にした。
};

const int nstars = sizeof(stars) / sizeof(struct star);

void plot_stars(FILE *fp, const double t,struct condition cond)
{
  int width = cond.width;
  int height = cond.height;
  char space[width][height];
  
  memset(space, ' ', sizeof(space));
  for (int i = 0; i < nstars; i++) {
    const int x = width  / 2 + stars[i].x;
    const int y = height / 2 + stars[i].y;
    if (x < 0 || x >= width)  continue;
    if (y < 0 || y >= height) continue;
    if (stars[i].m != 0) {
      char c = (stars[i].m >= 1.0)?'O':'o'; // 雉ｪ驥上′螟ｧ縺阪＞蝣ｴ蜷医�陦ｨ遉ｺ繧貞､峨∴繧
      space[x][y] = c;
    }
  }
  fprintf(fp, "----------\n");
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++)
      fputc(space[x][y], fp);
    fputc('\n', fp);
  }
  fflush(fp);

  printf("t = %5.1f", t);
  for (int i = 0; i < nstars; i++) 
    printf(", stars[%d] = (%7.2f, %7.2f)", i, stars[i].x, stars[i].y);
  printf("\n");
}

void update_velocities(const double dt,struct condition cond)
/* 星の速度を更新する  */
{
  int i, j;
  for (i = 0; i < nstars; i++) {
    double ax = 0;
    double ay = 0;
    for (j = 0; j < nstars; j++) {
        if (i != j) {
            double ax_x = pow(stars[j].x-stars[i].x, 2.0);
            double ay_y = pow(stars[j].y-stars[i].y, 2.0);
            double distance = sqrt (ax_x + ay_y);
            ax += cond.G * stars[j].m * (stars[j].x-stars[i].x) / pow(distance, 3.0);
            ay += cond.G * stars[j].m * (stars[j].y-stars[i].y) / pow(distance, 3.0);
        }
    }
    stars[i].vx += ax * dt;
    stars[i].vy += ay * dt;
  }
}

void update_positions(const double dt)
{
  for (int i = 0; i < nstars; i++) {
    stars[i].x += stars[i].vx * dt;
    stars[i].y += stars[i].vy * dt;
  }
  for (int i = 0; i < nstars; i++) {
    for (int j = 0; j < nstars; j++) {
      if (i != j) {
        double ax_x = pow(stars[j].x-stars[i].x, 2.0);
        double ay_y = pow(stars[j].y-stars[i].y, 2.0);
        double distance = sqrt (ax_x + ay_y);
        if (distance < 1.0) { //融合を考慮
          double fusion_vx = (stars[i].vx*stars[i].m + stars[j].vx*stars[j].m) / (stars[i].m + stars[j].m);
          double fusion_vy = (stars[i].vy*stars[i].m + stars[j].vy*stars[j].m) / (stars[i].m + stars[j].m);
          stars[i].vx = fusion_vx;
          stars[i].vy = fusion_vy;
          stars[i].m += stars[j].m;
          stars[j].m = 0;
          stars[j].vx = 0;
          stars[j].vy = 0;
        }
      }
    }
  }
}

int main(int argc, char *argv[])
{
  const char *filename = "space.txt";
  FILE *fp;
  if ((fp = fopen(filename, "a")) == NULL) {
    fprintf(stderr, "error: cannot open %s.\n", filename);
    return 1;
  }
  double dt;
  if (argc==2) {
    dt = atof (argv[1]);
  } else {
    dt = 1.0;
  }
  const double stop_time = 400;

  struct condition cond;
  cond.height = 40;
  cond.width = 75;
  cond.G = 1.0;

  double t = 0.;
  for (int i = 0; t <= stop_time; i++) {
    t = i * dt;
    update_velocities(dt,cond);
    update_positions(dt);
    if (i % 10 == 0) {
      plot_stars(fp, t, cond);
      sleep(1); //デフォルトはusleep(200 * 1000);
    }
  }

  fclose(fp);

  return 0;
}