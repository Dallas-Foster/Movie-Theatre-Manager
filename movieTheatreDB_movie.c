/*
 * Movie Database 2.0: Movie Commands
 * Dallas Foster
 * 251287541
 *
 * This program serves as the movie command section of the database. It stores an arbitrary number
 * of movies. The program works by continuously prompting users for five possible commands: 'i' to insert a new movie,
 * requesting a unique movie code, name, genre, and rating while validating inputs for uniqueness, acceptable length of name and
 * genre, and a valid rating range (0.0 to 10.0); 's' to search for a movie using its code, printing its
 * details if found or notifying the user if the code doesn't exist; 'u' to update an existing movie by code,
 * prompting users to modify all attributes (code, name, genre, rating) and alerting if the specified code
 * isn't found; 'p' to print a table listing all movies in the database with attributes like Movie Code, Name,
 * Genre, and Rating; 'e' to erase a movie from the database by searching for it in the list
 * by the movie code.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movieTheatreDB_movie.h"

struct Movie *movieHead = NULL; // Head of the movie linked list

// Function to manage movie operations
void manageMovies() {
    printf("*********************\n");
    printf("* Manage Movies     *\n");
    printf("*********************\n");

    // Prompt user for the operation code depending on which command they want to use
    char command;
    do {
        printf("\n\nEnter operation code: ");
        scanf(" %c", &command);

        switch (command) {
            case 'i':
                // Call function to insert a new movie
                insertMovie();
                break;
            case 's':
                // Call function to search for a movie
                searchMovie();
                break;
            case 'u':
                // Call function to update movie details
                updateMovie();
                break;
            case 'p':
                // Call function to print all movies
                printMovies(-1);
                break;
            case 'e':
                // Call function to erase a movie
                eraseMovie();
                break;
            case 'q':
                // Quit the movie management system
                break;
            default:
                // Error handling to ensure a valid command is inputted
                printf("Invalid command. Try again.\n");
        }// Loop until user chooses to quit
    } while (command != 'q');
}

// Function to insert a new movie into the linked list
void insertMovie() {
    int code;
    char name[100];
    char genre[50];
    float rating;

    // Prompt the user to enter a code to be associated with the movie
    printf("Enter movie code: ");
    // Read user input
    scanf("%d", &code);

    // Check if the code is less than 0 or already exists
    struct Movie *temp = movieHead;
    while (temp != NULL) {
        if (temp->code == code) {
            printf("Error: Movie code already exists or is invalid.\n");
            return;
        }
        // Move to the next movie in the list
        temp = temp->next;
    }
    if (code < 0) {
        // Display error for invalid code
        printf("Error: Invalid movie code.\n");
        return;
    }

    // Prompt for user input for movie name
    printf("Enter movie name: ");
    // Read user input for movie name
    scanf(" %99[^\n]", name);

    // Prompt for user input for movie genre
    printf("Enter movie genre: ");
    // Read the movie genre
    scanf(" %49[^\n]", genre);

    // Prompt the user to enter the rating of the movie
    printf("\tEnter movie rating: ");
    // Read a floating-point number from the user and store it in the 'rating' variable
    scanf(" %4f", &rating);
    //
    float ratingMultiplier = rating * 10;
    // Compare the multiplied rating to the float rating to determine if there was a valid rating inputted
    int ratingRound = (int)ratingMultiplier;
    // Final check to determine if inputted rating was between 0 and 10.0 with a valid decimal
    if (rating < 0 || rating > 10 || ratingMultiplier != ratingRound) {
        // If not, user is prompted to re-enter a rating
        printf("Please input a valid rating between 0-10.0");
        return;
    }

    // Create a new movie node
    struct Movie *newMovie = (struct Movie *)malloc(sizeof(struct Movie));
    // Allocate memory for new movie node
    if (newMovie == NULL) {
        // Display error if memory allocation fails
        printf("Error: Memory allocation failed.\n");
        return;
    }

    // Copy the data into the new movie node
    newMovie->code = code; // Assign code to the new movie node
    strncpy(newMovie->name, name, sizeof(newMovie->name) - 1); // Copy movie name
    newMovie->name[sizeof(newMovie->name) - 1] = '\0'; // Ensure null-terminated string
    strncpy(newMovie->genre, genre, sizeof(newMovie->genre) - 1); // Copy movie genre
    newMovie->genre[sizeof(newMovie->genre) - 1] = '\0'; // Ensure null-terminated string
    newMovie->rating = rating;
    newMovie->next = NULL; // Initialize the next pointer to NULL

    // Insert the new movie into the linked list
    if (movieHead == NULL) {
        // If list is empty, make the new movie as the head
        movieHead = newMovie;
    } else {
        struct Movie *lastMovie = movieHead;
        while (lastMovie->next != NULL) {
            // Traverse to the last movie in the list
            lastMovie = lastMovie->next;
        }
        // Add the new movie at the end of the list
        lastMovie->next = newMovie;
    }

    // Display success message after insertion
    printf("Movie inserted successfully.\n");
}

// Function to print all movies in the linked list
void printMovies(int code) {
    // Initialize a temporary pointer to head
    struct Movie *temp = movieHead;
    // Display header for movie details
    printf("Movie Code\tMovie Name\tMovie Genre\tMovie Rating\n");
    while (temp != NULL) {
        if (code == -1 || code == temp->code) {
            // Print movie details
            printf("%d\t\t%s\t\t%s\t\t%.1f\n", temp->code, temp->name, temp->genre, temp->rating);
        }
        // Move to the next movie in the list
        temp = temp->next;
    }
}

// Function to search for a movie by code in the linked list
void searchMovie() {
    int code;
    // Prompt for user input for movie code to search
    printf("\tEnter movie code: ");
    // Read user input for movie code
    scanf("%d", &code);

    struct Movie *temp = movieHead;
    while (temp != NULL) {
        if (temp->code == code) {
            // Display message for finding the movie
            printf("Movie found:\n");
            printMovies(code);

            return;
        }
        // Move to the next movie in the list
        temp = temp->next;
    }
    // Display message for movie not found
    printf("Movie not found.\n");
}

// Function to update a movie by code in the linked list
void updateMovie() {
    // Code to update a movie by code in the linked list
    int code;
    // Prompt for user input for movie code to update
    printf("\tEnter movie code: ");
    // Read user input
    scanf("%d", &code);

    struct Movie *temp = movieHead;
    while (temp != NULL) {
        if (temp->code == code) {
            char name[100];
            char genre[25];
            float rating;

            // Prompt for user input for updated movie name
            printf("Enter updated movie name: ");
            // Read updated movie name
            scanf(" %99[^\n]", name);

            // Prompt for user input for updated movie genre
            printf("Enter updated movie genre: ");
            // Read updated movie genre
            scanf(" %24[^\n]", genre);

            // Prompt for user input for updated movie rating
            printf("Enter updated movie rating: ");
            // Read updated movie rating
            scanf(" %f", &rating);
            float ratingMultiplier = rating * 10;
            // Compare the multiplied rating to the float rating to determine if there was a valid rating inputted
            int ratingRound = (int)ratingMultiplier;
            // Final check to determine if inputted rating was between 0 and 10.0 with a valid decimal
            if (rating < 0 || rating > 10 || ratingMultiplier != ratingRound) {
                // If not, user is prompted to re-enter a rating
                printf("Please input a valid rating between 0-10.0");
                return;
            }
            strncpy(temp->name, name, sizeof(temp->name) - 1); // Copy movie name
            temp->name[sizeof(temp->name) - 1] = '\0'; // Ensure null-terminated string
            strncpy(temp->genre, genre, sizeof(temp->genre) - 1); // Copy movie genre
            temp->genre[sizeof(temp->genre) - 1] = '\0'; // Ensure null-terminated string
            temp->rating = rating;
            return;

        }
        // Move to the next movie in the list
        temp = temp->next;
    }
    printf("Movie not found.\n");
}

// Function to delete a movie by code from the linked list
void eraseMovie() {

    // Prompt for user input for the movie code to delete
    int code;
    printf("\tEnter movie code: ");
    scanf("%d", &code);
    // Initialize a pointer to the previous movie
    struct Movie *prev = NULL;
    // Initialize a pointer to the current movie as head
    struct Movie *current = movieHead;

    // If the movie to be deleted is the head
    while (current != NULL) {
        if (current->code == code) {
            // Update head to the next movie

            if (prev == NULL) {
                movieHead = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Movie erased successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Movie not found.\n");
}