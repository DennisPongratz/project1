/* Ryan Cummings and Dennis Pongratz
 * project1, CSCI112
 * 21/09/2018
 *
 * purpose:
 * Progeram takes in principal amount, annual interest, and number of payments.
 * It calculates the monthly payment and builds an amortization schedule.
 */

#include <stdio.h>
#include <math.h>

// declare functions

void getData(double *principal, double *annual_interest, int *nop);
double calculate_payment(double principal, double annual_interest, double nop);
double relative_interest(double principal, double annual_interest);

// main function

int main(int argc, char** argv) {

    // declare variables
    int i, nop;
    double principal, annual_interest, payment, principalPer, relativeInterest, balance;

    // get data
    getData(&principal, &annual_interest, &nop);
    balance = principal;

    // do the calculation
    payment = calculate_payment(principal, annual_interest, nop);
    
    // give the data back with formated output
    printf("\n");

    printf("Principal");
    printf("%9s", "$");
    printf("%10.2lf", principal);
    printf("%15s", "Payment");
    printf("%9s", "$");
    printf("%9.2lf\n", payment);

    printf("Annual interest");
    printf("%12.1lf%%", annual_interest*100);
    printf("%15s", "Term");
    printf("%9d", nop);
    printf("%9s\n", "months");

    printf("\n");
  
    printf("%7s", "Payment");
    printf("%21s", "Interest");
    printf("%15s", "Principal");
    printf("%18s\n", "Principal");
    printf("%61s\n", "Balance");
    printf("---------------------------------------------------------------\n");
    
    // calculate relative interest
    relativeInterest = relative_interest(principal, annual_interest); 
    
    // for loop for ervery payment
    for (i=0; i < nop; i++) {
        
        principalPer = payment - relativeInterest;
        balance = balance - principalPer;

        printf("%3d", i + 1);
        printf("%25.2lf", relativeInterest);
        printf("%15.2lf", principalPer);
        printf("%18.2lf\n", balance);

        relativeInterest = relative_interest(balance, annual_interest); 
    }
    
    printf("Final payment $%.2lf\n", calculate_payment(principal, annual_interest, nop));
    printf("---------------------------------------------------------------\n");
    
    // exit program without errors
    return(0);
}

// get Data function
void getData(double *principal, double *annual_interest, int *nop) {
    
    printf("please type in the initial principal [$]: ");
    scanf("%lf", principal);

    printf("please type in the annual interest [%%]: ");
    scanf("%lf", annual_interest);
    *annual_interest = *annual_interest / 100;

    printf("please type in the number of payments: ");
    scanf("%d", nop);

}


/* calculates absolute amount of interest paid */
double relative_interest(double principal, double annual_interest){

    double relative_interest = (annual_interest / 12) * principal;

    return relative_interest;
}

/* calculates payments */
double calculate_payment(double principal, double annual_interest, double nop){
    double payment;
    double monthly_interest = annual_interest / 12;

    payment = ((monthly_interest * principal) / (1 - pow((1 + monthly_interest), -nop)));
    return payment;

}


