#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "email_lib/email.h"
#include "utils/utils.h"

#define EMAIL_NUMBER 1000000
#define USER_NUMBER 10000

int main() {
  unsigned int seed = time(NULL);
  char **users_list = create_username_list(USER_NUMBER);
  struct email *email_array = malloc(EMAIL_NUMBER * sizeof(struct email));

   struct tm *x1 = malloc(sizeof(struct tm));
  struct tm *x2 = malloc(sizeof(struct tm));
  x1->tm_year = 30;
  x2->tm_year = 50;
  // mktime(x1);
  // mktime(x2);
  // printf("%s \n", asctime(x1));
  // printf("%s \n", asctime(x2));

  for (int i = 0; i < EMAIL_NUMBER; i++) {
    email_array[i] =
        create_random_email(&seed, users_list, USER_NUMBER, x1, x2);
  }

  find_biggest_sender(email_array, users_list, USER_NUMBER, EMAIL_NUMBER, x1,
                      x2);

  for (int i = 0; i < EMAIL_NUMBER; i++) {
    free_email(email_array[i]);
  }
  free(email_array);
  free_username_list(users_list, USER_NUMBER);

  free(x1);
  free(x2);
  return 0;
}
