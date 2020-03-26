#include <stdio.h>
#include <stdlib.h>
struct monomial {
    int c;
    int n;
};
struct monomial * construct_monomial(int c, int n) {
    struct monomial *p1;
    p1=(struct monomial*)malloc(sizeof(struct monomial));
    //c,nの確保
    p1->c=(int)malloc(sizeof(int));
    p1->n=(int)malloc(sizeof(int));
    p1->c=c;
    p1->n=n;
    return p1;
}
void diff_monomial (struct monomial *m) {
    m->c=m->c*m->n;
    m->n=m->n-1;
}
void print_monomial(struct monomial *m) {
    printf("%d*x^%d\n", m->c, m->n);
}
int main() {
    struct monomial *m1;
    m1=construct_monomial(-4, 10);
    print_monomial(m1);
    diff_monomial(m1);
    print_monomial(m1);
    return 0;
}