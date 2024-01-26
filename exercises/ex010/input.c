#include <stdio.h>
#include <string.h>

static void flush_buffer(){
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
