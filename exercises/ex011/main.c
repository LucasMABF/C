#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *retstr(){
    char str[] = "Bye, world!";
    printf("&%d: %d: %s\n", &str, str, str);
    return str;
}

char *retSTR(){
    char* STR = "Bye, world!";
    printf("&%d: %d: %s\n", &STR, STR, STR);
    return STR;
}

char * retmSTR(){
    char* mSTR = malloc(12);
    strcpy(mSTR, "Hey, world!");
    printf("&%d: %d: %s\n", &mSTR, mSTR, mSTR);

    return mSTR;
    
}

int main(int argc, char **argv){

    char str[] = "Hello, world!";
    char* STR = "Hello, world!";
    printf("&%d: %d: %s\n", &str, str, str);
    printf("&%d: %d: %s\n", &STR, STR, STR);
    
    str[0] = 'A';
    STR = "ABC"; // STR[0] doesn't work, read only memory
    printf("&%d: %d: %s\n", &str, str, str);
    printf("&%d: %d: %s\n", &STR, STR, STR);

    char *str1 = retstr();
    printf("&%d: %d: %s\n", &str1, str1, str1);

    char *STR1 = retSTR();
    printf("&%d: %d: %s\n", &STR1, STR1, STR1);

    char *mSTR = retmSTR();
    printf("&%d: %d: %s\n", &mSTR, mSTR, mSTR);
    mSTR[0] = 'B';
    printf("&%d: %d: %s\n", &mSTR, mSTR, mSTR);
    mSTR = realloc(mSTR, 14);
    mSTR[9] = 0;
    mSTR[11] = '!';
    mSTR[12] = '!';
    mSTR[13] = 0;
    printf("&%d: %d: %s\n", &mSTR, mSTR, mSTR);

    free(mSTR);

    char location[9];
    printf("location: ");
    fgets(location, 9, stdin);
    int loc = atoi(location);

    printf("string in location: %s\n", loc);

    return 0;
}
