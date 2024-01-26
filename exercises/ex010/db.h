typedef enum ratings{
    Terrible = 0,
    Bad = 3,
    Average = 6,
    Good = 8,
    Excelent = 10
} Rating;


typedef struct movie{
    char name[50];
    int year;
    char lead_actor[50];
    Rating rating;
} Movie;

Movie *movie_collection;
extern int array_len;


int load();
void display();
void save();
void add();
void modify();
void removeMovie();
