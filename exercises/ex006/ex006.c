#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * hello(char *name){
    char *greeting;

    greeting = malloc(100);
    greeting[0] = '\0';
    strcat(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!\n");

    return greeting;
}

int main(int argc, char **argv){
    char name[20];
    printf("Enter your name: ");
    fgets(name, 20, stdin);
    int len = strlen(name);
    if(name[len - 1] == '\n'){
        name[len - 1] = '\0';
    }
    rewind(stdin);
    char *greet = hello(name);
    printf(greet);

    return 0;
}
