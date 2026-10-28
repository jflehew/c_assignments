#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


/**********************************************************************
 * API
 *********************************************************************/

typedef struct _movie movie;

/* Creates a new Movie with the specified title, release_year (in the range 1900-2030), lead actor and lead actress. The total number of ratings and the average audience rating is initialized to zero. Function returns NULL if any of the pointer parameters are NULL or if release_year is not in the correct format/range. */
movie * newMovie(char *title, int release_year, char *lead_actor, char *lead_actress); 


/* Update the total number of ratings and average audience rating based on the parameter "rating" (which is an integer from 1 to 10) for the movie "mov". Returns 0 if successful and -1 for malformed input */
int updateRating(movie *mov, int rating); //user submits rating from 1-10, avg can still be float


/*Returns 1 if mov1 has higher audience rating, 2 is mov2 has higher audience rating and 0 if both have same audience rating. Returns -1 for malformed input.*/
int whichMovieShouldIWatch(movie *mov1, movie *mov2); 


/*Prints out a one line summary of the movie (similar to the first line on the wikipedia page for any movie) that includes all the info contained in the structure. Returns 0 if successful or -1 if input is malformed. */
int printSummary(movie *mov);



/* Deletes the movie pointed to by mov. Returns 0 if successful or -1 if input malformed */
void deleteMovie(movie *mov);



/**********************************************************************
 * Application
 *********************************************************************/


//Write your main function with test cases here 


/**********************************************************************
 * Library implementation
 *********************************************************************/



//Write the implementations of the API functions here


