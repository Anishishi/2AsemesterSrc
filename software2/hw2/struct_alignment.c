#include <stdio.h>
int *a;
int *b;
struct student
{
  int id;
  char name[100];
  int age;
  double height;
  double weight;
};

struct tagged_student1
{
  int id;
  char name[100];
  int age;
  double height;
  double weight;
  char tag;
};

struct tagged_student2
{
  char tag;
  int id;
  char name[100];
  int age;
  double height;
  double weight;
};

int main (int argc, char**argv)
{
  struct student s;
  struct tagged_student1 s1;
  struct tagged_student2 s2;
  printf("s.id : %p, %ld\n", &(s.id), sizeof(s.id));
  printf("s.name[100] : %p, %ld\n", &(s.name), sizeof(s.name));
  printf("s.age : %p, %ld\n", &(s.age), sizeof(s.age));
  printf("s.height : %p, %ld\n", &(s.height), sizeof(s.height));
  printf("s.weight : %p, %ld\n", &(s.weight), sizeof(s.weight));
  printf("total : %ld\n\n", sizeof(s));

  printf("s1.id : %p, %ld\n", &(s1.id), sizeof(s1.id));
  printf("s1.name[100] : %p, %ld\n", &(s1.name), sizeof(s1.name));
  printf("s1.age : %p, %ld\n", &(s1.age), sizeof(s1.age));
  printf("s1.height : %p, %ld\n", &(s1.height), sizeof(s1.height));
  printf("s1.weight : %p, %ld\n", &(s1.weight), sizeof(s1.weight));
  printf("s1.tag : %p, %ld\n", &(s1.tag), sizeof(s1.tag));
  printf("total : %ld\n\n", sizeof(s1));

  printf("s2.tag : %p, %ld\n", &(s2.tag), sizeof(s2.tag));
  printf("s2.id : %p, %ld\n", &(s2.id), sizeof(s2.id));
  printf("s2.name[100] : %p, %ld\n", &(s2.name), sizeof(s2.name));
  printf("s2.age : %p, %ld\n", &(s2.age), sizeof(s2.age));
  printf("s2.height : %p, %ld\n", &(s2.height), sizeof(s2.height));
  printf("s2.weight : %p, %ld\n", &(s2.weight), sizeof(s2.weight));
  printf("total : %ld\n\n", sizeof(s2));

  printf("答えはコードの中に記述しました。\n");
  /* 答え
  構造体ごとでその構造体の中の各変数のメモリの取られ方が変わってくる。初めから数えてint型は4の倍数ごとにchar型100個分は100の倍数ごとに
  double型は8の倍数ごとになるように一つ前のメモリが多く取られることがある。例えば、s1においてageまででは108ビット取られているが、
  次がdouble型が確保されるので8の倍数になるように112ビット取られなければならない。そこでageのあとに空白が定義されてつじつまが合う。
  これはs1の時も同じでageのあとに4ビット取られる。またs1のtagでは8バイト領域へのアライメントであるためその後に7バイト確保される。
  s2ではidの前が4の倍数である必要があるのでtagは4ビット確保される。 */
  return 0;
}