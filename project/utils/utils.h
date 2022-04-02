#ifndef PROJECT_UTILS_UTILS_H_
#define PROJECT_UTILS_UTILS_H_
char *create_random_text(unsigned int *seed, int len);
char **create_username_list(int n);
void free_username_list(char **A, int n);
int random_in_borders(unsigned int *seed, int min, int max);
#endif  //  PROJECT_UTILS_UTILS_H_
