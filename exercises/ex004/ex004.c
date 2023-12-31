#include <stdio.h>

int main(int argc, char **argv){
    printf("Enter an ASCII character: \n");
    char ch = getchar();
    
    switch (ch){
        case 0:
            printf("Character type: Null\n");
            break;
        case 7:
            printf("Character type: Bell\n");
            break;
        case 8:
            printf("Character type: Backspace\n");
            break;
        case 9:
            printf("Character type: Tab\n");
            break;
        case 10:
            printf("Character type: LineFeed\n");
            break;
        case 13:
            printf("Character type: Carriage return\n");
            break;
        case 32:
            printf("Character type: Space\n");
            break;
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
            printf("that is a good number you picked.\n");
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
            printf("Character type: Number\n");
            break;
        default:
            printf("Character type: Character\n");
            break;
        case 'A'...'Z':
            printf("Upper case letter\n");
            break;
        case 'a'...'z':
            printf("Lower case letter\n");
            break;
    }
}