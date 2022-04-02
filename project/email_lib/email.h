#ifndef PROJECT_EMAIL_LIB_EMAIL_H_
#define PROJECT_EMAIL_LIB_EMAIL_H_
struct tm;
struct email {
  char *sender;
  int recievers_amount;
  char **recievers;
  char *header;
  char *body;
  struct tm *time;
};

struct email create_random_email(unsigned int *seed, char **user_list, int size,
                                 struct tm *date1, struct tm *date2);
void free_email(struct email a);
char *find_biggest_sender(struct email *email_array, char **user_array,
                          int user_array_size, int email_array_size,
                          struct tm *date1, struct tm *date2);
#endif  // PROJECT_EMAIL_LIB_EMAIL_H_
