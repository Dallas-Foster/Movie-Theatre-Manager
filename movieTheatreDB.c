/*
 * Movie Database 2.0: Main Operations
 * Dallas Foster
 * 251287541
 *
 * The purpose of this file is to act as the main of the entire program. It continuously
 * loops for an input from the user for a variety of different commands; 'h' is a help command
 * which will print out a display that give information about the program and the other
 * commands; 'q' will quit the entire program; 'a' is the command that will call the control
 * actors program where the user can do a variety of commands to do with the actors; 'm'
 * is the command similar to the actors one, however it has to do with movies.
 */
#include <stdio.h>
#include "movieTheatreDB.h"
// Main function to control the program flow
int main() {

    char command;

    // Continuously prompt for commands until 'q' for quit
    do {
        // Prompt user for a command input
        printf("Enter command (h for help): ");
        // Read user input
        scanf(" %c", &command);

        switch (command) {
            case 'h':
                printf("Commands:\n\n");
                printf("h - Help: Display available commands\n");
                printf("q - Quit: Exit the program\n");
                printf("m - Control movies: Perform operations related to movies\n");
                printf("a - Control actors: Perform operations related to actors\n");
                break;
            case 'q':
                // Quit the program
                break;
            case 'm':
                // Call function to manage movies
                manageMovies();
                break;
            case 'a':
                // Call function to manage actors
                manageActors();
                break;
            case 'r':
                // Call function to manage actors
                manageMovieActorCode();
                break;
        }
        // Loop until user decides to quit the program
    } while (command != 'q');

    return 0;
}


