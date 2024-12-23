#ifndef Movie_H
#define Movie_H
// Define the structure for movies
struct Movie {
    int code; // define the code
    char name[100]; // Set the maximum name length to 100
    char genre[25]; // Set the maximum genre length to 25
    float rating; // Set the rating to a float to allow for decimal ratings
    struct Movie *next;
};

// Define functions from the c file
void manageMovies();
void insertMovie();
void printMovies(int code);
void searchMovie();
void updateMovie();
void eraseMovie();
#endif