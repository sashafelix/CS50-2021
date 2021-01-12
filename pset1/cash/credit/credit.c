#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get Card number from user.

    long cardNumber = get_long("Please enter Credit Card Number: ");

    while (cardNumber < 1 || cardNumber > 9999999999999999)
    {
        cardNumber = get_long("Please enter Credit Card Number: ");
    }

    // Make a copy of the card number to be used and modified throughout the process.

    long long tempNumber = cardNumber;

    int count = 0;

    while (tempNumber > 0)
    {
        tempNumber = tempNumber / 10;
        count++;
    }

    //Check if digit count matches knows CC number count

    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Apply Luhn's algorithm.

    int sum = 0;

    tempNumber = cardNumber;

    for (int i = 1; i <= count; i++)
    {
        int digit = tempNumber % 10;

        if (i % 2 == 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;

        tempNumber /= 10;
    }

    // Checking the validity of the number according to Luhn's algorithm

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Reset 'tempNumber' and apply calculations that will get the first two digits.

    tempNumber = cardNumber;

    while (tempNumber > 100)
    {
        tempNumber = tempNumber / 10;
    }

    int cardType = tempNumber;

    // Print the type of credit card depending on amount of digits each card has,
    // American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers.
    // American Express numbers start with 34 or 37
    // MasterCard numbers start with 51, 52, 53, 54, or 55
    // Visa numbers start with 4

    if (cardType > 50 && cardType < 56 && count == 16)
    {
        printf("MASTERCARD\n") ;
    }
    else if ((cardType == 34 || cardType == 37) && (count == 15))
    {
        printf("AMEX\n") ;
    }
    else if ((cardType / 10 == 4) && (count == 13 || count == 16 || count == 19))
    {
        printf("VISA\n") ;
    }
    else
    {
        printf("INVALID\n");
    }

    // Apply Luhn's algorithm.

    sum = 0;

    tempNumber = cardNumber;

    for (int i = 1; i <= count; i++)
    {
        int digit = tempNumber % 10;

        if (i % 2 == 0)
        {
            digit *= 2;

            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;

        tempNumber /= 10;
    }

    // Checking the validity of the number according to Luhn's algorithm

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 1;
    }

    return 0;
}