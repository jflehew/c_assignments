#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>


/**********************************************************************
 * API
 *********************************************************************/

typedef struct _movie movie;

/* Creates a new Movie with the specified title, release_year (in the range 1900-2030), lead actor and lead actress. The total number of ratings and the average audience rating is initialized to zero. Function returns NULL if any of the pointer parameters are NULL or if release_year is not in the correct format/range. */
movie * newMovie(char *title, int release_year, char *lead_actor, char *lead_actress); //!complete


/* Update the total number of ratings and average audience rating based on the parameter "rating" (which is an integer from 1 to 10) for the movie "mov". Returns 0 if successful and -1 for malformed input */
int updateRating(movie *mov, int rating);  //user submits rating from 1-10, avg can still be float //! complete


/*Returns 1 if mov1 has higher audience rating, 2 is mov2 has higher audience rating and 0 if both have same audience rating. Returns -1 for malformed input.*/
int whichMovieShouldIWatch(movie *mov1, movie *mov2); //! complete


/*Prints out a one line summary of the movie (similar to the first line on the wikipedia page for any movie) that includes all the info contained in the structure. Returns 0 if successful or -1 if input is malformed. */
int printSummary(movie *mov); //! complete



/* Deletes the movie pointed to by mov. Returns 0 if successful or -1 if input malformed */
void deleteMovie(movie *mov);//!complete



/**********************************************************************
 * Application
 *********************************************************************/


//Write your main function with test cases here 
int main(){
    int err;
    movie * movie_one = newMovie(
        "The Matrix",
        1999,
        "Keanu Reeves",
        "Carrie-Anne Moss"
    ); assert(movie_one);
    err = updateRating(movie_one, 8); assert(!err);
    err = updateRating(movie_one, 10); assert(!err);
    err = updateRating(movie_one, 7); assert(!err);
    err = updateRating(movie_one, 9); assert(!err);
    err = updateRating(movie_one, 6); assert(!err);
    err = printSummary(movie_one); assert(!err);

     /* Test 2: average requiring a decimal */
    movie *movie_two = newMovie(
        "Alien",
        1979,
        "Tom Skerritt",
        "Sigourney Weaver"
    );
    assert(movie_two);
    err = updateRating(movie_two, 8); assert(!err);
    err = updateRating(movie_two, 9); assert(!err);
    err = printSummary(movie_two); assert(!err);


    /* Test 3: movie comparison */
    err = whichMovieShouldIWatch(movie_one, movie_two);
    assert(err == 2);


    /* Test 4: movies with equal ratings */
    movie *movie_three = newMovie(
        "Movie Three",
        2005,
        "Actor Three",
        "Actress Three"
    );
    assert(movie_three);

    movie *movie_four = newMovie(
        "Movie Four",
        2010,
        "Actor Four",
        "Actress Four"
    );
    assert(movie_four);

    err = updateRating(movie_three, 5); assert(!err);
    err = updateRating(movie_three, 7); assert(!err);

    err = updateRating(movie_four, 6); assert(!err);

    err = whichMovieShouldIWatch(movie_three, movie_four);
    assert(!err);


    /* Test 5: invalid ratings */
    err = updateRating(movie_one, 11);
    assert(err);

    err = updateRating(movie_one, 0);
    assert(err);

    err = updateRating(movie_one, -1);
    assert(err);


    /* Test 6: NULL movie passed to updateRating */
    err = updateRating(NULL, 5);
    assert(err);


    /* Test 7: NULL passed to whichMovieShouldIWatch */
    err = whichMovieShouldIWatch(movie_one, NULL);
    assert(err);

    err = whichMovieShouldIWatch(NULL, movie_one);
    assert(err);

    err = whichMovieShouldIWatch(NULL, NULL);
    assert(err);


    /* Test 8: invalid release years */
    movie *bad_movie_one = newMovie(
        "Too Old",
        1899,
        "Actor",
        "Actress"
    );
    assert(!bad_movie_one);

    movie *bad_movie_two = newMovie(
        "Too New",
        2031,
        "Actor",
        "Actress"
    );
    assert(!bad_movie_two);


    /* Test 9: boundary release years */
    movie *movie_five = newMovie(
        "Old Movie",
        1900,
        "Actor Five",
        "Actress Five"
    );
    assert(movie_five);

    movie *movie_six = newMovie(
        "Future Movie",
        2030,
        "Actor Six",
        "Actress Six"
    );
    assert(movie_six);


    /* Test 10: NULL constructor arguments */
    movie *bad_movie_three = newMovie(
        NULL,
        2000,
        "Actor",
        "Actress"
    );
    assert(!bad_movie_three);

    movie *bad_movie_four = newMovie(
        "Title",
        2000,
        NULL,
        "Actress"
    );
    assert(!bad_movie_four);

    movie *bad_movie_five = newMovie(
        "Title",
        2000,
        "Actor",
        NULL
    );
    assert(!bad_movie_five);


    /* Test 11: NULL printSummary */
    err = printSummary(NULL);
    assert(err);

    /* Clean up */
    deleteMovie(movie_one);
    deleteMovie(movie_two);
    deleteMovie(movie_three);
    deleteMovie(movie_four);
    deleteMovie(movie_five);
    deleteMovie(movie_six);
    return 0;

}


/**********************************************************************
 * Library implementation
 *********************************************************************/

//Write the implementations of the API functions here
struct _movie{
    char *title;
    int release_year;
    char *lead_actor;
    char *lead_actress;
    int *ratings;
    int number_of_ratings;
    float rating_average;
};

movie * newMovie(char *title, int release_year, char *lead_actor, char *lead_actress){
    if(title == NULL || lead_actor == NULL || lead_actress == NULL){return NULL;}
    if(release_year < 1900 || release_year > 2030){return NULL;}

    movie * new_movie = malloc(sizeof(movie));
    if(!new_movie){
        return NULL;
    }

    (*new_movie).title = malloc(strlen(title) + 1);
    if(!(*new_movie).title){
        free(new_movie);
        return NULL;
    }
    strcpy((*new_movie).title, title);
    
    (*new_movie).release_year = release_year;
    
    (*new_movie).lead_actor = malloc(strlen(lead_actor) + 1);
    if(!(*new_movie).lead_actor){
        free((*new_movie).title);
        free(new_movie);
        return NULL;
    }
    strcpy((*new_movie).lead_actor, lead_actor);
    
    (*new_movie).lead_actress = malloc(strlen(lead_actress) + 1);
    if(!(*new_movie).lead_actress){
        free((*new_movie).title);
        free((*new_movie).lead_actor);
        free(new_movie);
        return NULL;
    }
    strcpy((*new_movie).lead_actress, lead_actress);
    
    (*new_movie).ratings = malloc(sizeof(int)); 
    if(!(*new_movie).ratings){
        free((*new_movie).title);
        free((*new_movie).lead_actor);
        free((*new_movie).lead_actress);
        free(new_movie);
        return NULL;
    }
    (*new_movie).ratings[0] = 0;

    (*new_movie).number_of_ratings = 0;

    (*new_movie).rating_average = 0.0;

    

    return new_movie;
}

int updateRating(movie *mov, int rating){
    if(!mov){return -1;}
    if(rating < 1 || rating > 10){return -1;}

    if((*mov).number_of_ratings == 0){
        (*mov).ratings[(*mov).number_of_ratings] = rating;
        (*mov).number_of_ratings += 1;
        (*mov).rating_average = (float)rating;
        return 0;
    }

    int * temp = realloc((*mov).ratings, ((*mov).number_of_ratings + 1) * sizeof(int));
    if(!temp){return -1;}
    (*mov).ratings = temp;
    (*mov).ratings[(*mov).number_of_ratings] = rating;
    (*mov).number_of_ratings += 1;

    int total = 0;
    for(int i = 0; i < (*mov).number_of_ratings; i++){
        total += (*mov).ratings[i];
    }
    (*mov).rating_average = (float)total / (*mov).number_of_ratings;
    return 0;
    
}

int whichMovieShouldIWatch(movie *mov1, movie *mov2){
    if (mov1 == NULL || mov2 == NULL){return -1;}
    if((*mov1).rating_average > (*mov2).rating_average){return 1;}
    else if((*mov1).rating_average < (*mov2).rating_average){return 2;}
    return 0;
}

int printSummary(movie *mov){
    if(!mov){return -1;}
    printf(
        "Title: %s\n"
        "Release Year: %d\n"
        "Lead Actor: %s\n"
        "Lead Actress: %s\n"
        "Total Number of Ratings: %d\n"
        "Average Rating: %g\n"
        "Ratings: \n",
        (*mov).title, 
        (*mov).release_year, 
        (*mov).lead_actor, 
        (*mov).lead_actress, 
        (*mov).number_of_ratings, 
        (*mov).rating_average
    );
    for(int i = 0; i < (*mov).number_of_ratings; i++){
        printf("%d: %d\n", i+1,(*mov).ratings[i]);
    }
    return 0;
}

void deleteMovie(movie *mov){
    if(mov){
        free(mov->title);
        free(mov->lead_actor);
        free(mov->lead_actress);
        free(mov->ratings);
        free(mov);
    }
}


