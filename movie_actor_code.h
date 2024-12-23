#ifndef MOVIE_ACTOR_H
#define MOVIE_ACTOR_H

struct MovieActorCode {
    int movieCode;
    int actorCode;
    struct MovieActorCode *next;
};

void manageMovieActorCode();
void insertRelationship();
void searchRelationship();
void printRelationships();
void printMoviesForActor();
void printActorsForMovie();
void removeRelationship();
#endif