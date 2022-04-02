#include "email.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "../utils/utils.h"

#define HEADER_LENGTH 5
#define BODY_LENGTH 5
#define MAX_RECIEVERS 3

struct email create_random_email(unsigned int* seed, char** user_list, int size,
                                 struct tm* date1, struct tm* date2) {
  struct email a;

  // time_t t1=mktime(date1);
  // time_t t2=mktime(date2);
  // time_t s_time = rand_r(seed)%(t2-t1)+t2;
  time_t s_time = rand_r(seed);

  struct tm* time = malloc(sizeof(struct tm));
  int recievers_amount = 1 + rand_r(seed) % (MAX_RECIEVERS - 1);
  a.sender = user_list[rand_r(seed) % size];

  a.recievers_amount = recievers_amount;
  a.recievers = (char**)malloc(sizeof(char*) * recievers_amount);
  for (int i = 0; i < recievers_amount; i++) {
    a.recievers[i] = user_list[rand_r(seed) % size];
  }
  a.header = create_random_text(seed, HEADER_LENGTH);
  a.body = create_random_text(seed, BODY_LENGTH);
  localtime_r(&s_time, time);
  a.time = time;
  return a;
}

void free_email(struct email a) {
  free(a.recievers);
  free(a.time);
  free(a.header);
  free(a.body);
}

char* find_biggest_sender(struct email* email_array, char** user_array,
                          int user_array_size, int email_array_size,
                          struct tm* date1, struct tm* date2) {
  int* user_email_count = malloc(user_array_size * sizeof(int));
  for (int j = 0; j < user_array_size; j++) {
    user_email_count[j] = 0;
  }

  for (int i = 0; i < email_array_size; i++) {
    for (int j = 0; j < user_array_size; j++) {
      if (!strcmp(email_array[i].sender, user_array[j])) user_email_count[j]++;
    }
  }
  int max = 0;
  char* max_user;
  for (int j = 0; j < user_array_size; j++) {
    if (user_email_count[j] > max) {
      max = user_email_count[j];
      max_user = user_array[j];
    }
    // printf("%s %d\n", user_array[j], user_email_count[j]);
  }
  printf("User with maximum (%d)emails is %s\n", max, max_user);
  free(user_email_count);
  return max_user;
}
