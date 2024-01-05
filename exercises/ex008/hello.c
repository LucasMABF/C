#include <stdio.h>

static void say_bye(){
    printf("bye!");
}

void say_hello(){
    printf("Hello! ");
    say_bye();
}
