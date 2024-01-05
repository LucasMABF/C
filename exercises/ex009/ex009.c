#include <stdio.h>
#include "encryption.h"

int main(int argc, char **argv){
    FILE *f = fopen("hello.txt", "w");
    fputs("Hello, world!\n", f);
    fclose(f);

    FILE *g = fopen("hello.txt", "r");
    if(g != NULL){
        char line[200];
        while (fgets(line, 200, g) != NULL){
            printf(line);
        }
    }
    fclose(g);

    FILE *h = encrypt("hello.txt", 1);
    printf("encrypted into file .encr\n");
    FILE *i = decrypt("hello.txt.encr", 1);
    printf("decrypted file\n");

}
