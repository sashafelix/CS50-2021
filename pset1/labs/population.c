#include <cs50.h>

#include <stdio.h>

int calculation(int input);
int main(void) 
{
    // TODO: Prompt for start size
    int startSize = 0;
    while (startSize < 9) 
    {
        startSize = get_int("Start size: ");
    }

    // TODO: Prompt for end size
    int endSize = 0;
    while (endSize < startSize) 
    {
        endSize = get_int("End Size: ");
    }

    // TODO: Calculate number of years until we reach threshold

    int years = 0;
    int populationGrowth = 0;
    if (endSize == startSize) 
    {
        years = 0;
    } 
    else 
    {
        while (populationGrowth < endSize) 
        {
            populationGrowth = calculation(startSize);
            startSize = populationGrowth;
            years++;
        }

    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}

int calculation(int input) 
{
    int births = input / 3;
    //printf("Births: %i\n", births);
    int deaths = input / 4;
    //printf("Deaths: %i\n", deaths);
    int result = (input - deaths) + births;
    return (result);
}