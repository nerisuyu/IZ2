#include <gtest/gtest.h>

extern "C" {
    #include "email.h"
    #include "utils.h"
}



TEST(Utils, RandomTextTest) {
    unsigned int seed=0;
    ASSERT_EQ(3,strlen(create_random_text(&seed,4)));
}

TEST(Utils, usernamelist){
    char** a=create_username_list(10000);
    ASSERT_EQ(3,strlen(a[0]));
    free_username_list(a,10000);
}

