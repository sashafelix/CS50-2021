#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int gradeCalculation(char input[]);
int main(void) 
{
    // Get input from user. 
    string input = get_string("Input String: ");

    // char input[] = "Congratulations! Today is your day. You're off to Great Places! You're off and away!";
    int x = gradeCalculation(input);
    if (x < 1)
    {
        printf("Before Grade 1\n");

    }
    else if (x > 16)
    {
        printf("Grade 16+\n");

    }
    else 
    {
        printf("Grade %i\n", x);

    }
}

int gradeCalculation(char input[]) 
{
    // The abstract contains 5 sentences, 119 words, and 639 letters or digits; L is 537 and S is 4.20 obtained by the formulas:
    // L = Letters ÷ Words × 100 = 639 ÷ 119 × 100 ≈ 537
    // S = Sentences ÷ Words × 100 = 5 ÷ 119 × 100 ≈ 4.20

    // Counts letters 
    int letters = 0;
    for (int i = 0; i < strlen(input); i++) 
        if (isalpha(input[i]))
        {
            letters++;
            
        }

    // count number of words
    int words = 0;
    for (int i = 0; input[i] != '\0'; i++) 
    {
        if ((input[i] == ' ' && input[i + 1] != ' ') || (input[i] == '.' && input[i + 1] != ' '))
        {
            words++;
            // printf("Words: %i\n", words);
        }
    }
    // count number of sentences
    int sentences = 0;
    for (int i = 0; input[i] != '\0'; i++) 
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!' || input[i] == '\n')
        {
            sentences++;
            // printf("Sentences: %i\n", sentences);
        }
    }
    
    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;
    float calculation = 0.0588 * L - 0.296 * S - 15.8;
    float index = round(calculation);
    
    // printf("letters: %i\n", letters);
    // printf("Words: %i\n", words);
    // printf("Sentences: %i\n", sentences);
    // printf("L: %f\n", L);
    // printf("S: %f\n", S);
    // printf("calculation: %f\n", calculation);
    // printf("index: %f\n", index);
    return index;
}