#include <stdio.h>
#include <stdlib.h>
#include "db.h"
int main(int argc, char **argv){
    while(1){
        printf("Insert command(h for help, wq to quit and save): ");
        char input = getchar();
        rewind(stdin);
        switch(input){
            case 'a':
                add();
                break;
            case 'r':
                removeMovie();
                break;
            case 'd':
                display();
                break;
            case 'm':
                modify();
                break;
            case 'n':
                printf("there are %d movies in memory.\n", array_len);
                break;
            case 's':
                save();
                break;
            case 'l':
                load();
                break;
            case 'h':
                printf("press \"a\" to add a new movie record.\n");
                printf("press \"r\" to remove a movie record.\n");
                printf("press \"d\" to display all existing records.\n");
                printf("press \"m\" to modify an existing movie record.\n");
                printf("press \"n\" to show the total number of records.\n");
                printf("press \"s\" to save from memory to database file.\n");
                printf("press \"l\" to load to memory from database file.\n");
                printf("press \"wq\" to quit and save.\n");
                printf("press \"q!\" to quit without saving.\n");
                break;
            case 'w':
                save();
                break;
            case 'q':
                break;
            default:
                printf("invalid command!\n");
                break;
        }
        if(input == 'q' || input == 'w'){
            break;
        }
    }
    return 0;
}
