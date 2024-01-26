#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "db.h"
#include "input.h"

int array_len = 0;

static int len_collection(char *filename){
    FILE *f = fopen(filename, "rb");
    if(f == NULL){
        printf("unable to read file\n");
        return -1;
    }else{
        fseek(f, 0, SEEK_END);
        int pos = ftell(f);
        fclose(f);
        return pos / sizeof(Movie);
    }
}

int load(){
    char filename[15];
    printf("What is the name of the database file to save to: ");
    readln(filename, 15);

    int len_movies = len_collection(filename);
    if(len_movies == -1){
        return -1;
    }
    FILE *f = fopen(filename, "rb");
    if(f == NULL){
        printf("unable to read file\n");
        return -1;
    }else{
        movie_collection = realloc(movie_collection, sizeof(Movie) * len_movies);
        if(movie_collection != NULL){
            int movies_read = fread(movie_collection, sizeof(Movie), len_movies, f);
            if(len_movies != movies_read){
                printf("error: %d movies in file, but only %d were read.\n", len_movies, movies_read);
            }
            fclose(f);
            printf("success! loaded %d movies\n", movies_read);
            array_len = movies_read;
            return movies_read;
        }else{
            printf("error: unable to alloc memory.\n");
        }
    }
}

void save(){
    char filename[15];
    printf("What is the name of the database file to save to: ");
    readln(filename, 15);

    FILE *f = fopen(filename, "wb");
    if(f == NULL){
        printf("Can't write to file: %s.", filename);
    }else{
        int count = fwrite(movie_collection, sizeof(Movie), array_len, f);
        if(count != array_len){
            printf("error in saving: %d files in memory and %d saved\n", array_len, count);
        }else{
            fclose(f);
            printf("saved!\n");
        }
    }
}

static char *getName(){
    char *name = malloc(50);
    printf("what is the name of the movie: ");
    readln(name, 50);
    return name;
}

static int getYear(){
    while(1){
            char y[5];
            printf("from what year is it: ");
            readln(y, 5);
            int year = atoi(y);
            if(year != 0){
                return year;
            }else{
                printf("invalid year, try again.\n");
            }
        }

    
}

static char *getActor(){
    char *actor = malloc(50);
    printf("what is the lead actor: ");
    readln(actor, 50);
    return actor;
}

static int getRating(){
    while(1){
            char r[3];
            printf("What is the movie's rating: ");
            readln(r, 3);
            int rat;
            if(r[0] == '0'){
                rat = 0;
            }else{
                rat = atoi(r);
                if(rat > 0 && rat <=10){
                    return rat;
                }else{
                    printf("invalid rating, try again.\n");
                }
            }
        }
}

void add(){
    movie_collection = realloc(movie_collection, sizeof(Movie) * (array_len + 1));
    if(movie_collection != NULL){
        char *name = getName();
        strcpy(movie_collection[array_len].name, name);
        free(name);

        int year = getYear();
        movie_collection[array_len].year = year;
        
        char *actor = getActor();
        strcpy(movie_collection[array_len].lead_actor, actor);
        free(actor);

        int rating = getRating();
        movie_collection[array_len].rating = rating;

        array_len += 1;
        printf("Movie added!\n");
    }else{
        printf("error: unable to alloc memory.\n");
    }
}

void display(){
    printf("---------- Movies ----------\n");
    for(int i = 0; i < array_len; i++){
        printf("----- Movie %d -----\n", i + 1);
        printf("name: %s\n", movie_collection[i].name);
        printf("year: %d\n", movie_collection[i].year);
        printf("lead actor: %s\n", movie_collection[i].lead_actor);
        printf("rating: %d\n", movie_collection[i].rating);
    }
}

static int selectMovie(){
    display();
        int size = log10(array_len) + 2;
        char *i = malloc(size);
        int index;
        do{
            printf("Select movie index(c to cancell): ");
            readln(i, size);
            if(i[0] == 'c'|| i[0] == 'C'){
                return - 1;
            }
            index = atoi(i);
        }while(index == 0 || index > array_len);
        free(i);
        return index - 1;
}

void modify(){
    if(array_len == 0){
        printf("No movies in memory to modify!\n");
    }else{
        printf("What movie do you want to modify?\n");
        int index = selectMovie();
        if(index == -1){
            return;
        }

        printf("1: name\n");
        printf("2: year\n");
        printf("3, lead actor\n");
        printf("4: rating\n");
        printf("5: All\n");

        char f[2];
        int field;
        do{
            printf("What do you want to modify(c to cancell): ");
            readln(f, 2);
            if(f[0] == 'c' || f[0] == 'C'){
                return;
            }
            field = atoi(f);

        }while(field == 0 || field > 5);
        
        if(field == 5 || field == 1){
            char *name = getName();
            strcpy(movie_collection[index].name, name);
            free(name);
        }

        if(field == 5 || field == 2){
            int year = getYear();
            movie_collection[index].year = year;
        }

        if(field == 5 || field == 3){
            char* actor = getActor();
            strcpy(movie_collection[index].lead_actor, actor);
            free(actor);
        }

        if(field == 5 || field == 4){
            int rating = getRating();
            movie_collection[index].rating = rating;
        }

        printf("Successfully modified movie data!\n");
    }
}

void removeMovie(){
    printf("What movie do you want to delete?\n");
    int index = selectMovie();
    if(index == -1){
        return;
    }
    Movie *tmp_collection = malloc(sizeof(Movie) * array_len);
    tmp_collection = movie_collection;
    movie_collection = malloc(sizeof(Movie) * (array_len - 1));

    int count = 0;
    for(int i = 0; i < array_len; i++){
        if(i != index){
            movie_collection[count] = tmp_collection[i];
            count++;
        }
    }
    free(tmp_collection);
    array_len -= 1;
    printf("Successfully deleted one movie entry!");
}
