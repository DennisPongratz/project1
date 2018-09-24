/* Ryan Cummings and Dennis Pongratz
 * project1, CSCI112
 * 21/09/2018
 *
 * purpose:
 */

#include <stdio.h>
#include <math.h>

// declare functions

void getData(double *princ, double *annInt, double *nop);


int main(int argc, char** argv) {
    
    // declare variables 

    double princ, annInt, nop;

    // get data

    getData(&princ, &annInt, &nop); 

    // do the calculation

    

    // give the data back
   
    return(0);
}

void getData(double *princ, double *annInt, double *nop) {
    
    printf("please type in the initial principal: ");
    scanf("%lf", princ);

    printf("please type in the annual interest: ");
    scanf("%lf", annInt);

    printf("please type in the number of payments: ");
    scanf("%lf", nop);

}

