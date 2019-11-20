#include <stdio.h>
#include <stdlib.h>

/****************************************** ^ - ^  **************************************************/

/**This program takes as many inputs as the user wants to determine the which date comes later on
 * calendar. User can enter 0/0/0 to exit the program. Until enter 0/0/0, the program will keep asking for
 * a valid input. If an invalid input is given, the program may exit or ask for input again.
 *
 *Student Name:   Shiyu Wang
 *
 **/

/****************************************** ^ - ^ **************************************************/

int main() {

    //initialize date variables
    int month, day, year;

    // intilize flag value and counter for loop control
    int flag = 1, counter =0;

    //abc are for finding out the largest numbers
    int a=0,b=0,c=0;

    //while true
    while (flag) {

        //print to ask for input
        printf("Enter a date (mm/dd/yy):\t");


        //read input from user and output error
        //if the input is not integer
        if (scanf(" %d / %d / %d", &month, &day, &year) != 3) {
            printf("Error: Invalid Date Format!\n");


            //clear input buffer
            while ((getchar()) != '\n');

        }



        //if the input is exit date, update the latest date and set flag to 0 to exit
        else if (month == 0 && day == 0 && year == 0) {

            //if there has not been any valid date but 0/0/0, print error and exit
            if (counter == 0) {

                printf("Error: At least one date must be input!\n");
                exit(1);

            }

            flag = 0;
        }

        // if not exit date, check if the input are valid month/day/year respectively
        else if (month < 1 || month > 12)
            printf("Error: Invalid Month Number!\n");

        else if (day < 1 || day > 31)
            printf("Error: Invalid Day Number!\n");

        else if (year < 0 || year > 99)
            printf("Error: Invalid Year Number!\n");



        //if all dates are valid, update the latest date
        else {

            //increment counter if any valid date has been entered
            counter++;

            if(a == 0 && b == 0 && c == 0){

                a=month;
                b=day;
                c=year;
            }

            else {
                if (year > c) {

                    c = year;
                    a = month;
                    b = day;
                }

                else if(year == c) {

                    if (month > a){

                        a = month;
                        b = day;
                    }
                    else if(month == a){

                        if(day > b)
                            b = day;
                    }

                }
            }
        }


    }

    //after reading the exit date, print the latest date
    printf("%.2d/%.2d/%.2d is the latest date\n", a, b, c);
    return 0;
}
