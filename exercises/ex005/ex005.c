#include <stdio.h>
#include <string.h>

void encrypt(char s[], int key){
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        char c = s[i];
        if(c == ' '){
            continue;
        }
        if(c == '\n'){
            s[i] = '\0';
            break;
        }
        s[i] = c + key;
    }

}

void decrypt(char s[], int key){
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        char c = s[i];
        if(c == ' '){
            continue;
        }
        if(c == '\n'){
            s[i] = '\0';
            break;
        }
        s[i] = c - key;

    }
}

int main(int argc, char **argv){
    char message[20];
    int key = 5;
    printf("Input message: ");
    fgets(message, 20, stdin);
    printf("Your message is: %s\n", message);
    encrypt(message, key);
    printf("Your encrypted message is: %s\n", message);
    decrypt(message, key);
    printf("Your decrypted message is: %s\n", message);
    
    return 0;
}
