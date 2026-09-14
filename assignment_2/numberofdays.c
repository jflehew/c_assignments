#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//creates function to return true or false depedning on whether it is a leap year or not
bool leap_year_test(int year){
    //checks if it's the 400th year
    if(year % 400 == 0){
        return true;
    }
    //checks if it's the 100th year after 400th year is checked
    if(year % 100 == 0){
        return false;
    }
    //if both aboe do not pass checks if year is divisible by 4
    if(year % 4 == 0){
        return true;
    }
    //if all other cases fail returns false (not a leap year)
    return false;
}

// function to give a name to a month based on the number input by the user
// function takes in the month as an integer, the address of a number of days variable and the address of a string array for month name
void find_month_name(int month, int *days, char *month_name){
    //switch statement that determines which month the user called
        switch(month){
        case 1:
        // function strcpy copy's a new string into the array of char month_name
        strcpy(month_name, "January");
        // modifies the value at the address of days with the correct number of days in that month
        *days = 31;
        break;
        case 2:
        strcpy(month_name, "February");
        break;
        case 3:
        strcpy(month_name, "March");
        *days = 31;
        break;
        case 4:
        strcpy(month_name, "April");
        *days = 30;
        break;
        case 5:
        strcpy(month_name, "May");
        *days = 31;
        break;
        case 6:
        strcpy(month_name, "June");
        *days = 30;
        break;
        case 7:
        strcpy(month_name, "July");
        *days = 31;
        break;
        case 8:
        strcpy(month_name, "August");
        *days = 31;
        break;
        case 9:
        strcpy(month_name, "September");
        *days = 30;
        break;
        case 10:
        strcpy(month_name, "October");
        *days = 31;
        break;
        case 11:
        strcpy(month_name, "November");
        *days = 30;
        break;
        case 12:
        strcpy(month_name, "December");
        *days = 31;
        break;
    }
}

// a function which returns true of false and takes in a year, a month the address of a days int and the address of a char array
bool number_of_days_in_month(int year, int month, int *days_address, char *month_name_address){
    //if statement to determine if the input is valid for the current standard calander
    if(year < 1582 || month < 1 || month > 12){
        return false;
    }
    //calls the leap year test functiuon and sets is_leap_year to true or false based on the result
    bool is_leap_year = leap_year_test(year);
    // printf("The year is %d and is_leap_year is %d\n", year, is_leap_year);
    //calls the find month name function and sets the values of the days and name of that month
    find_month_name(month, days_address, month_name_address);
    //if statement to determine if it is februrary or not
    if(month == 2){
        //if statement, if it is feburary is it a leap year?
        if(is_leap_year){
            // printf("it's a leap year!\n");
            // sets days to 29 if conditions pass
            *days_address = 29;
        }else{
            // else februrary's days are 28
            *days_address = 28;
        }
    }
    //returns true if the input recieved was valid
    return true;
}
// function that returns nothing that takes in an address for the year and an address for the month and sets the users input to be their values
void scan_year_and_month(int*year, int*month){
    // creates and array of characters that can contain 1000 chars
    char user_input[1000];
    // a char to verify if a user input too much information
    char extra_input;
    // while loop that allows user to input information into the console until that information has met the criteria standards
    while(true){
        //print statement describing what the user should enter
        printf("-----\nPlease enter a year and month:\nThe year must be 1582 or later\nThe month must be enered as a number between 1 and 12\n-----\n");
        //takes in the user input
        fgets(user_input, sizeof(user_input), stdin);
        //counts the number of inputs made by a user and verifies they are of type int
        int number_of_ints = sscanf(user_input, "%d %d %c", year, month, &extra_input);
        //verifies only two inputs were taken from the user
        if(number_of_ints == 2){
            //if user has done this correctly return
            return;
        }
        //if the user has done something incorrectly print and restart loop
        printf("-----You either entered too few arguments or too many arguments-----\n");
    }
}

//main function
int main(){
    //initilize number of days variable
    int number_of_days;
    // initilize the array for month name
    char month_name[20];
    //initialize the user input for year
    int input_year;
    //initialize the user input for month
    int input_month;
    //initialize a booliean that determines if the number of days can be calculated
    bool correct_number_of_days;
    //call the function for the user to input their data
    scan_year_and_month(&input_year, &input_month);
    //calls number of days in the month function and sets correct number of days to the true/false value that is returned
    correct_number_of_days = number_of_days_in_month(input_year, input_month, &number_of_days, month_name);
    //checks to see if the number of days of a month was able to be calculated
    if(correct_number_of_days){
        //informs the user of the month, year, and # of days
        printf("The month of %s in the year of %d has %d days in it\n", month_name, input_year, number_of_days);
    } else{
        //informs the user if the dates they entered could not be calculated
        printf("the year and or month you entered cannot be calculated\n");
    }
    //end program
    return 0;
}