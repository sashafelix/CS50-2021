#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Define Variables
    int quater, dime, nickel, penny;
    quater = 25;
    dime = 10;
    nickel = 5;
    penny = 1;
    
    //Get change value
    float change;
    do
    {
        change = get_float("What is the change amount? ");
        //printf("%f\n", change);
    }
    while (change <= 0);
    int cents = round(change * 100);

    //Print value
    //printf("You have %i, change.\n", cents);
    //Calculate coin sizes
    int changeCalc = cents;
    int coinCount = 0;
    
    //Calculate coins need in a loop
    do
    {
        if (changeCalc >= 25)
        {
            changeCalc = changeCalc - quater;
            coinCount++;
        }
        else if (changeCalc >= 10 && changeCalc < 25)
        {
            changeCalc = changeCalc - dime;
            coinCount++;
        }
        else if (changeCalc >= 5 && changeCalc < 10)
        {
            changeCalc = changeCalc - nickel;
            coinCount++;
        }
        else
        {
            changeCalc = changeCalc - penny;
            coinCount++;
        }        
    } 
    while (changeCalc != 0);
    printf("Coins used: %i\n", coinCount);
}