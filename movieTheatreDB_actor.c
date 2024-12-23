/*
 * Movie Database 2.0: Actor Commands
 * Dallas Foster
 * 251287541
 *
 * This program follows many of the same principles as its movie counterpart. It prompts the
 * user to input an operation code in order to determine which command the user wants to use
 * on the actors, much like the movies. The user has the choice between 6 commands to input:
 * 'i' to insert a new actor to the database through a linked list, asking for an actor code,
 * name, imdb page; 's' to search for an actor based on the unique actor code inputted by the
 * user prior; 'u' to update any of the information that the user inputted for a specific actor
 * by searching again for the unique actor code; 'e' to erase an actor from the linked list and
 * thus the database itself; and 'q' to quit the program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movieTheatreDB_actor.h"

// Head of the actor linked list
struct Actor *actorHead = NULL; // Head of the actor linked list

// Function to manage actor operations
void manageActors() {
    printf("*********************\n");
    printf("* Manage Actors     *\n");
    printf("*********************\n");

    char command;

    do {
        // Prompt for user input for operation code
        printf("\n\nEnter operation code: ");
        // Read user's operation code
        scanf(" %c", &command);

        switch (command) {
            case 'i':
                // Call function to insert a new actor
                insertActor();
                break;
            case 's':
                // Call function to search for an actor
                searchActor();
                break;
            case 'u':
                // Call function to update actor details
                updateActor();
                break;
            case 'p':
                // Call function to print all actors
                printActors(-1);
                break;
            case 'e':
                // Call function to erase an actor
                eraseActor();
                break;
            case 'q':
                // Quit the actor management system
                break;
            default:
                // Display error message for invalid input
                printf("Invalid command. Try again.\n");
        }
        // Loop until user chooses to quit
    } while (command != 'q');
}

// Function to insert a new actor into the linked list
void insertActor() {
    // Allocate memory for new actor node
    struct Actor *newActor = (struct Actor *)malloc(sizeof(struct Actor));
    if (newActor == NULL) {
        // Display error if memory allocation fails
        printf("Memory allocation failed.\n");
        return;
    }

    int code, age;
    char name[50], imdbPage[50];

    // Prompt for user input for actor code
    printf("\tEnter actor code: ");
    // Read user input for actor code
    scanf("%d", &code);

    // Check if the entered actor code already exists
    struct Actor *temp = actorHead;
    while (temp != NULL) {
        if (temp->code == code) {
            // Display error for existing actor code
            printf("\tError: Actor code already exists.\n");
            // Move to the next actor in the list by returning and moving from the temporary
            // to the next in the list
            free(newActor);
            return;
        }
        temp = temp->next;
    }

    // Check to see if actor code is valid
    if (code < 0) {
        // Display error for invalid actor code
        printf("\tError: Invalid actor code.\n");
        free(newActor);
        return;
    }

    // Prompt for user input for actor name
    printf("\tEnter actor name: ");
    // Read the actor name
    scanf(" %49[^\n]", name);

    // Prompt for user input for actor age
    printf("\tEnter actor age: ");
    // Read user input for actor age
    scanf("%d", &age);

    // Check to see if inputted age is valid (Between 0 and 120
    if (age < 0 || age > 120) {
        printf("\tError: Invalid actor age.\n");
        free(newActor);
        return;
    }

    // Prompt for user input for IMDB profile page
    printf("\tEnter IMDB profile page: ");
    // Read IMDB profile page
    scanf(" %49[^\n]", imdbPage);

    // Assign code to the new actor node
    newActor->code = code;
    // Copy actor name
    strcpy(newActor->name, name);
    // Assign age to the new actor node
    newActor->age = age;
    // Copy IMDB profile page
    strcpy(newActor->imdbPage, imdbPage);
    // Initialize the next pointer to NULL
    newActor->next = NULL;

    // Inserting at the beginning of the list
    if (actorHead == NULL) {
        // If list is empty, make the new actor as the head
        actorHead = newActor;
    } else {
        // Traverse to the last actor in the list
        struct Actor *temp = actorHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Add the new actor at the end of the list
        temp->next = newActor;
    }
}

// Code to print all actors in the linked list
void printActors(int code) {
    // Initialize a temporary pointer to head
    struct Actor *temp = actorHead;
    // Initialize a temporary pointer to head
    printf("Actor Code\tActor Name\tAge\tIMDB Profile\n");
    while (temp != NULL) {
        if (code == -1 || code == temp->code) {
            // Print actor details
            printf("%d\t\t%s\t\t%d\t%s\n", temp->code, temp->name, temp->age, temp->imdbPage);
        }
        // Move to the next actor in the list
        temp = temp->next;
    }
}

// Code to search for an actor by code in the linked list
void searchActor() {

    int code;
    // Prompt for user input for actor code to search
    printf("\tEnter actor code: ");
    // Read user input for actor code
    scanf("%d", &code);

    struct Actor *temp = actorHead;
    while (temp != NULL) {
        if (temp->code == code) {
            // Display message for finding the actor
            printf("Actor found:\n");
            // Display header
            printf("Actor Code\tActor Name\tAge\tIMDB Profile\n");
            // Print information
            printf("%d\t\t%s\t\t%d\t%s\n", temp->code, temp->name, temp->age, temp->imdbPage);
            return;
        }
        // Move to the next actor in the list
        temp = temp->next;
    }
    // Display message for actor not found
    printf("Actor not found.\n");
}

// Code to update an actor by code in the linked list
void updateActor() {

    int code;
    // Prompt for user input for actor code to update
    printf("\tEnter actor code: ");
    // Read code
    scanf("%d", &code);

    // Go to linked list
    struct Actor *temp = actorHead;
    while (temp != NULL) {
        if (temp->code == code) {
            char name[50];
            int age;
            char IMDB[50];

            // Prompt for user input for updated actor name
            printf("Enter updated actor name: ");
            // Read updated actor name
            scanf(" %49[^\n]", name);
            // Prompt to input new age
            printf("Enter updated actor age: ");
            // Read new inputted age
            scanf("%d", &age);

            // Verify that the new age that was inputted follows the same guidelines
            // as the original and is in between 0-120
            if (age < 0 || age> 120) {
                printf("\tError: Invalid actor age.\n");
                return;
            }

            // Prompt for user input for updated IMDB profile page
            printf("Enter updated IMDB profile page: ");
            // Read updated IMDB profile page
            scanf(" %49[^\n]", IMDB);

            // Copy actor name
            strcpy(temp->name, name);
            // Assign updated age to actor
            temp->age = age;
            // Copy IMDB profile page
            strcpy(temp->imdbPage, IMDB);
            return;
        }
        // Move onto the next actor in the linked list
        temp = temp->next;
    }
    // Error handling in case code is invalid
    printf("Actor not found.\n");
}

// Code to delete an actor by code from the linked list
void eraseActor() {

    int code;
    // Prompt for actor code to look for
    printf("\tEnter actor code: ");
    scanf("%d", &code);

    // Initialize a pointer to the previous actor
    struct Actor *prev = NULL;
    // Initialize a pointer to the current actor as head
    struct Actor *current = actorHead;

    while (current != NULL) {
        // If the actor to be deleted is the head
        if (current->code == code) {
            // Update head to the next actor
            if (prev == NULL) {
                // Redirect the previous actor's pointer to the next actor
                actorHead = current->next;
            } else {
                prev->next = current->next;
            }
            // Free the memory occupied by the actor to be deleted
            free(current);
            // Display success message for actor deletion
            printf("Actor deleted successfully.\n");
            return;
        }
        // Move the previous pointer to the current actor
        prev = current;
        // Move the current pointer to the next actor
        current = current->next;
    }
    // Error handling in case of invalid code
    printf("Actor not found.\n");
}