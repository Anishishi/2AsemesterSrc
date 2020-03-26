#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 10000

double get_max(double *);
double get_min(double *);
double get_mean(double *);
double get_stdev(double *);
int main() {
    FILE *fp;
    fp=fopen("namelist.txt", "r");
    if (fp==NULL) {
        printf("Failed to open the file\n");
        return 1;
    }
    double age[N], height[N], weight[N];
    int i=0;
    while (fscanf(fp, "%*[^,], %lf, %lf, %lf\n", age+i, height+i, weight+i) != EOF) {
        i++;
    }
    fclose(fp);
    printf("Age : (max, min, mean, stdev) = (%lf, %lf, %lf, %lf)\n", get_max(age), get_min(age), get_mean(age), get_stdev(age));
    printf("Height : (max, min, mean, stdev) = (%lf, %lf, %lf, %lf)\n", get_max(height), get_min(height), get_mean(height), get_stdev(height));
    printf("Weight : (max, min, mean, stdev) = (%lf, %lf, %lf, %lf)\n", get_max(weight), get_min(weight), get_mean(weight), get_stdev(weight));
    return 0;
}
double get_max(double *s) {
    double max = s[0];
    for (int i=1; i<N; i++) {
        if (s[i]>max) {
            max=s[i];
        }
    }
    return max;
}
double get_min(double *s) {
    double min = s[0];
    for (int i=1; i<N; i++) {
        if (s[i]<min) {
            min=s[i];
        }
    }
    return min;
}
double get_mean(double *s) {
    double sum=0;
    for (int i=0; i<N; i++) {
        sum+=s[i];
    }
    return sum/N;
}
double get_stdev(double *s) {
    double sum=0;
    double average=get_mean(s);
    for (int i=0; i<N; i++) {
        sum+=(s[i]-average)*(s[i]-average);
    }
    return sqrt(sum/N);
}