#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_buffer(){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int readln(char s[], int maxlen){
    fgets(s, maxlen, stdin);
    int len_s = strlen(s);

    if(s[len_s - 1] == '\n'){
        s[len_s - 1] = '\0';
        len_s -= 1;
    }else{
        flush_buffer();
    }

    return len_s;
}

int readline(char s[], int maxlen){ // version 2
    char ch;
    int i = 0;
    int chars_remaining = 1;
    while(chars_remaining){
        ch = getchar();
        if(ch == '\n' || ch == EOF){
            chars_remaining = 0;
        }else if(i < maxlen - 1){
            s[i] = ch;
            i++;
        }
    }
    s[i] = '\0';
    return i;
}

int main(int argc, char **argv){
    char agestring[4];
    printf("Enter your age: ");
    readln(agestring, 4);
    int age = atoi(agestring);

    int bonus;
    if(age == 0){
        puts("you typed an invalid age!");
        return 1;
    }else if(age > 45){
        bonus = 1000;
    }else{
        bonus = 500;
    }

    printf("your age is %d, so your bonus is %d\n", age, bonus);

    char name[5];
    printf("Enter your first name: ");
    readln(name, 5);
    char name2[5];
    printf("Enter your last name: ");
    readln(name2, 5);
    printf("Hello, %s, %s\n", name, name2);

    puts("readline 2");
    char test[5];
    readline(test, 5);
    printf("test: %s\n", test);

    return 0;
}
