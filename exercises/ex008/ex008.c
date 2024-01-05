#include <stdio.h>
#include "hello.h"
int n = 30;

void func1(){
    int n = 10;
    printf("inside function: %d\n", n);
}

void func2(){
    n = 20;
}

void func3(){
    static int a = 1000;
    printf("%d\n", a);
    a++;
}

int main(int argc, char **argv){
    printf("%d\n", n);
    func1();
    printf("%d\n", n);
    func2();
    printf("%d\n", n);
    func1();
    printf("%d\n", n);

    int i = 90;
    {
        int i = 100;
        printf("inside block: %d\n", i);
    }
    printf("outside block: %d\n", i);

    func3();
    func3();
    func3();

    say_hello();
    // say_bye();
    return 0;
}
