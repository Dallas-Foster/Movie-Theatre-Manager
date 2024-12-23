#ifndef Actor_H
#define Actor_H
// Define the structure for actors
struct Actor {
    int code; // Unique integer code
    char name[50]; // Set Max length of name to 50
    int age; // Set age to integer
    char imdbPage[50]; // Allow max imdb page to be 50
    struct Actor *next;
};

// Define functions of the c file
void manageActors();
void insertActor();
void printActors(int code);
void searchActor();
void updateActor();
void eraseActor();
#endif