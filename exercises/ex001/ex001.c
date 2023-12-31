#include <stdio.h>

int main(int argc, char **argv){
    int i;

    printf("argc = %d\n", argc);

    for(i = 0; i < argc; i++){
        printf("arg %d is %s\n", i, argv[i]);
    }

    puts("Hello, World!");
    for(i = 0; i <= 100; i += 5){
        printf("%d\n", i);
    }

    return 0;
}