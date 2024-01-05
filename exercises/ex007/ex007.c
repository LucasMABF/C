#include <stdio.h>
#include <string.h>

typedef struct movie Movie;

typedef enum ratings{
    Terrible = 0,
    Bad = 3,
    Average = 6,
    Good = 8,
    Excelent = 10
} Rating;

struct movie{
    char name[50];
    int year;
    char lead_actor[50];
    Rating rating;
};

int main(int argc, char **argv){
    Movie movies[2];
    strcpy(movies[0].name, "Forrest Gump");
    movies[0].year = 1994;
    strcpy(movies[0].lead_actor, "Tom Hanks");
    movies[0].rating = Excelent;

    printf("Movie: %s, Year: %d, Actor: %s, rating: %d\n", movies[0].name, movies[0].year, movies[0].lead_actor, movies[0].rating);
    return 0;
}
