/* Ryan Cummings and Dennis Pongratz
 * project1, CSCI112
 * 21/09/2018
 *
 * purpose:
 */

#include <stdio.h>
#include <math.h>

// declare functions

void getData(double *principal, double *annual_interest, int *nop);
double calculate_payment(double, double, double);
double relative_interest(double, double);

int main(int argc, char** argv) {
    int i, nop;
    double principal, annual_interest, payment, principalPer, relativeInterest;

    // get data
    getData(&principal, &annual_interest, &nop);
    double balance = principal;

    // do the calculation
    payment = calculate_payment(principal, annual_interest, nop);
    //printf("%lf\n", payment);
    
    // give the data back

    printf("\n");

    printf("Principal       %.2lf      Payment         $%.2lf\n", principal, payment);
    printf("Annual interest %.2lf%%        Term            %d months\n\n", annual_interest*100, nop);
    printf("Payment:        ");
    printf("Interest:     ");
    printf("Principal:      ");
    printf("Principal Balance:\n");
    printf("---------------------------------------------------------------\n");
    
    relativeInterest = relative_interest(principal, annual_interest); 

    for (i=0; i < nop; i++) {
        
        principalPer = payment - relativeInterest;
        balance = balance - principalPer;

        printf("%d", i + 1);
        printf("               ");
        printf("%.2lf", relativeInterest);
        printf("         ");
        printf("%.2lf", principalPer);
        printf("          ");
        printf("%.2lf\n", balance);

        relativeInterest = relative_interest(balance, annual_interest); 
    }
    
    printf("---------------------------------------------------------------\n");
    printf("Final payment  %.2lf\n", calculate_payment(principal, annual_interest, nop));
   
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


