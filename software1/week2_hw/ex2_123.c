#include <stdio.h>

#define IN        1
#define OUT       0
#define MAXLEN    25
#define MAXNWORD  23000

int get_max( int array[], int N ) {
    int i;
    int max = array[0];
    for (i = 0; i <= N-1; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}

double get_average( int array[], int N) {
    int i;
    double sum, average;
    sum = 0;
    for (i = 0; i <= N-1; i++) {
        sum += array[i];
    }
    average = sum / N;
    return average;
}

double get_variance( int array[], int N) {
    int i;
    double sum = 0;
    double average = get_average(array, N);
    double vari;
    for (i = 0; i <= N-1; i++) {
        sum = sum + (array[i] - average) *  (array[i] - average);
    }
    vari = sum / N;
    return vari;
}

int main(void)
{
  int c, nl, nw, nc, state;
  int i;
  int word_initial, word_final, len;
  int word_length[MAXLEN];
  int numbers[MAXNWORD];

  for( i = 0 ; i < MAXLEN ; ++i ) {
    word_length[i] = 0;
  }
  for( i = 0 ; i < MAXNWORD ; ++i ) {
    numbers[i] = 0;
  }

  state = OUT;
  nl = nw = nc = 0;
  while( ( c = getchar() ) != EOF ) {
    ++nc;

    if( c == ' ' || c == '\n' || c == '\t' ) {
      if( state == IN ) {
  word_final = nc;
 len = word_final - word_initial;
 ++word_length[len];

 numbers[nw] = (nl+1)*len;
 // printf( "nw = %d, nl = %d, len = %d, numbers = %d\n", nw, nl, len, numbers[nw] );
 ++nw;
      }
      state = OUT;
    }
    else if( state == OUT ) {
      state = IN;
      word_initial = nc;
    }

    if( c == '\n' ) {
      ++nl;
    }
  }

  printf( "#line = %d #word = %d #character = %d\n", nl, nw, nc );
  printf( "max = %d, avg = %.3f, var = %.3f\n", get_max( numbers, nw ),
   get_average( numbers, nw ), get_variance( numbers, nw ) );

  return 0;
}