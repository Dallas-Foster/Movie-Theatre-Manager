cmake_minimum_required(VERSION 3.26)
project(CSAssignment5 C)

set(CMAKE_C_STANDARD 11)

add_executable(CSAssignment5 movieTheatreDB.c
        movieTheatreDB.h
        movieTheatreDB_movie.c
        movieTheatreDB_movie.h
        movieTheatreDB_actor.c
        movieTheatreDB_actor.h
        movie_actor_code.h
        movie_actor_code.c)
