#include <stdio.h>
#include <string.h>

FILE *encrypt(char *fileName, int key){
    FILE *f = fopen(fileName, "r");
    
    if (f != NULL){
        char name[100];
        name[0] = '\0';
        strncpy(name, fileName, 100);
        FILE *encrypted = fopen(strcat(name, ".encr"), "w");
        char c = fgetc(f);
        while(c != EOF){
            
            if (c == '\n' || c == ' '|| c == '\r'){
                fputc(c, encrypted);
            }else{
                fputc(c + key, encrypted);
            }
            c = fgetc(f);
        }
        fclose(f);
        if(remove(fileName) != 0){
            printf("error: unable to delete original file!");
        }
        fclose(encrypted);
        return encrypted;
    }else{
        printf("error: unable to open file!");
        return NULL;
    }
}

FILE *decrypt(char *fileName, int key){
    FILE *f = fopen(fileName, "r");
    
    if (f != NULL){
        char name[100];
        name[0] = '\0';
        strncpy(name, fileName, strlen(fileName) - 5);
        FILE *decrypted = fopen(name, "w");
        char c = fgetc(f);
        while(c != EOF){
            if (c == '\n' || c == ' '|| c == '\r'){
                fputc(c, decrypted);
            }else{
                fputc(c - key, decrypted);
            }
            c = fgetc(f);
        }
        fclose(f);
        if(remove(fileName) != 0){
            printf("error: unable to delete original file!");

        }
        fclose(decrypted);
        return decrypted;
    }else{
        printf("error: unable to open file!");
        return NULL;
    }
}
