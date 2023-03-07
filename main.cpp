#include <iostream>
#include <string.h>

double totalAmt(double userCarAmt, double agePerc){
    double total;
    total = (userCarAmt * agePerc) / 12;
    return(total);
}

double malePercentage(int age){
    double agePerc;
    if (age >= 15 && age < 25){
        agePerc = 0.25;
    } else if (age >= 25 && age < 40) {
        agePerc = 0.17;
    } else if (age >= 40 && age < 70) {
        agePerc = 0.10;
    }
    return agePerc;
}

double femalePercentage(int age){
    double agePerc;
    if (age >= 15 && age < 25) {
        agePerc = 0.20;
    } else if (age >= 25 && age < 40) {
        agePerc = 0.15;
    } else if (age >= 40 && age < 70) {
        agePerc = 0.10;
    }
    return agePerc;
}

int main() {

    int flagSex, age;
    double userTotalAmt, agePerc, userCarAmt;
    char userSex[5];

    printf("Are you 'Male' or 'Female': \n");
    scanf("%s",userSex);

    //check sex validity
    if(strncmp(userSex,"Male",5)==0){
        flagSex = 0;
    } else {
        flagSex = 1;
    }

    printf("Enter your age: \n");
    scanf("%d",&age);

    if (age >= 70){
        printf("Cannot service due to age requirements\n");
    }

    printf("Enter the purchase price of the vehicle: \n");
    scanf("%lf",&userCarAmt);


    //Calculate if Male
    if (flagSex == 0) {
        agePerc = malePercentage(age);
    }

    //Calculate if Female
    if (flagSex == 1) {
        agePerc = femalePercentage(age);
    }

    userTotalAmt = totalAmt(userCarAmt,agePerc);

    printf("Male or Female: %s\n",userSex);
    printf("Enter your age: %d\n", age);
    printf("Purchase price of the vehicle: $%.2f\n", userCarAmt);
    printf("Your monthly insurance total is: $%.2f\n", userTotalAmt);


    return 0;
}
