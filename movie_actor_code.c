#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_actor_code.h"
#include "movieTheatreDB_actor.h"
#include "movieTheatreDB_movie.h"


struct MovieActorCode *movieActorHead = NULL;




void insertRelationship() {
    // Insert a new movie/actor relationship
    int movieCode, actorCode;
    printf("Enter movie code: ");
    scanf("%d", &movieCode);

    // Check if the entered movie code exists in the database
    struct Movie *tempMovie = movieHead;
    int movieExists = 0;

    while (tempMovie != NULL) {
        if (tempMovie->code == movieCode) {
            movieExists = 1;
            break;
        }
        tempMovie = tempMovie->next;
    }

    if (!movieExists) {
        printf("Movie code does not exist.\n");
        return;
    }

    printf("Enter actor code: ");
    scanf("%d", &actorCode);

    // Check if the entered actor code exists in the database
    struct Actor *tempActor = actorHead;
    int actorExists = 0; // Flag to track actor existence

    while (tempActor != NULL) {
        if (tempActor->code == actorCode) {
            actorExists = 1;
            break;
        }
        tempActor = tempActor->next;
    }

    if (!actorExists) {
        printf("Actor code does not exist.\n");
        return;
    }

    // Insert the relationship if both movie and actor codes are valid
    struct MovieActorCode *newRelationship = (struct MovieActorCode *)malloc(sizeof(struct MovieActorCode));

    if (newRelationship == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newRelationship->movieCode = movieCode;
    newRelationship->actorCode = actorCode;
    newRelationship->next = NULL;

    // Insert the new relationship into the database
    if (movieActorHead == NULL) {
        movieActorHead = newRelationship;
    } else {
        struct MovieActorCode *lastRelationship = movieActorHead;
        while (lastRelationship->next != NULL) {
            lastRelationship = lastRelationship->next;
        }
        lastRelationship->next = newRelationship;
    }

    printf("Relationship inserted successfully.\n");
}

void manageMovieActorCode() {
    char command;

    do {
        printf("\n\nEnter an operation code: ");
        scanf(" %c", &command);
        switch (command) {
            case 'r':
                insertRelationship();
                break;
            case 's':
                searchRelationship();
                break;
            case 'p':
                printRelationships();
                break;
            case 'm':
                printMoviesForActor();
                break;
            case 'a':
                printActorsForMovie();
                break;
            case 'e':
                removeRelationship();
                break;
            case 'q':
                break;
            default:
                printf("Invalid command. Try again.\n");
        }
    } while (command != "q");
}