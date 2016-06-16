#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int movieId;
    char movieTitle[50];
    char genre[25];
    int mDuration;
    char mDescription[100];
    int mScore;
    int isEmpty;
    char imageLink[100];

}sMovies;

void menuF(sMovies[], int);

void initIsEmpty(sMovies[], int);

int addMovie(sMovies[], int);

int firstFreeSpace(sMovies[], int);

int getElementID(sMovies[], char[], int);

int saveInFile(sMovies[]);

int loadFromFile(sMovies[]);

int removeMovie(sMovies[], int);

int modifyMovie(sMovies[], int);

int listMovies(sMovies[], int, int);

int fileGen(sMovies[], char[], int);

#endif // LIB_H_INCLUDED

