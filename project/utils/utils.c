#include "utils.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALTHABET_SIZE 23

char *create_random_text(unsigned int *seed, int len) {
  int i;
  char *s = (char *)malloc(len * (sizeof(char)));
  for (i = 0; i < len - 1; i++) s[i] = 'a' + rand_r(seed) % 30;
  s[i] = '\0';
  return s;
}

char **create_username_list(int n) {
  int length =
      ceil(log(n) / log(ALTHABET_SIZE));  //   минимальное количество букв для
                                          //   описания n уникальных юзернеймов

  char **A = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++)
    A[i] = (char *)malloc(length * (sizeof(char) + 1));

  for (int i = 0; i < n; i++) {
    char *a = A[i];
    for (int j = 0; j < length; j++) {
      *a = 'a' + ((int)(i / pow(ALTHABET_SIZE, j)) % ALTHABET_SIZE);
      a++;
    }
    *a = '\0';
  }

  return A;
}

void free_username_list(char **A, int n) {
  for (int i = 0; i < n; i++) {
    free(A[i]);
  }
  free(A);
}
