/* Ryan Cummings and Dennis Pongratz
 * project1, CSCI112
 * 21/09/2018
 *
 * purpose:
 */

#include <stdio.h>
#include <math.h>

// declare functions

void getData(double *principal, double *annual_interest, double *nop);
double calculate_payment(double, double, double);

int main(int argc, char** argv) {
    double payment;
    // declare variables 

    double principal, annual_interest, nop;

    // get data

    getData(&principal, &annual_interest, &nop); 

    // do the calculation
    payment = calculate_payment(principal, annual_interest, nop);
    printf("%lf\n", payment);
    

    // give the data back
   
    return(0);
}

void getData(double *principal, double *annual_interest, double *nop) {
    
    printf("please type in the initial principal: ");
    scanf("%lf", principal);

    printf("please type in the annual interest: ");
    scanf("%lf", annual_interest);

    printf("please type in the number of payments: ");
    scanf("%lf", nop);

}
/* calculates payments */
double calculate_payment(double principal, double annual_interest, double nop){
    double payment;
    double monthly_interest = annual_interest / 12;

    payment = ((monthly_interest * principal) / (1 - pow((1 + monthly_interest), -nop)));
    return payment;

}

