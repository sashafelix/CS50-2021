#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Request User input for name variable.
    string name = get_string("What is your name? ");
    //Print name variable with hello.
    printf("hello, %s\n", name);
}