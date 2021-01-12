#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    // Verify there is only 1 argument.
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    //Convert key string to int.
    int k = atoi(argv[1]);

    //Get message input from user.
    string msg = get_string("plaintext: ");
    printf("ciphertext: "); // print out cipher

    //Iterate through plain text letter by letter
    for (int i = 0, n = strlen(msg) ; i < n; i++)
    {
        //Check if it is lowercase.
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            //New lowercase Character with key added
            printf("%c", (((msg[i] - 'a') + k) % 26) + 'a');
        }
        //Check if its UPPERCASE
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            //New UPPERCASE Character with key added
            printf("%c", (((msg[i] - 'A') + k) % 26) + 'A');
        }
        else
        {
            printf("%c", msg[i]);
        }
    }
    printf("\n");
    return 0;
}