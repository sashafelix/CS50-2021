#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

char charSub(char c, string key);
// char *strchr(const char *str, int c);
int main(int argc, char *argv[])
{
    //Check is there is a Key with the launch
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Verify Key is 26 charackters long
    int keySize = strlen(argv[1]);
    if (keySize != 26)
    {
        printf("Usage: ./substitution key (must contan 26 unique letters)\n");
        return 1;
    }
    //Verify key only contains alphabetical characters
    string key = argv[1];
    for (int i = 0; i < keySize; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key may only contain alhabetic characters!\n");
            return 1;
        }
    }
    //verify key does NOT contain duplicate characters
    for (int i = 0; i < strlen(key); i++) 
    {  
        int count = 1;  
        for (int j = i + 1; j < strlen(key); j++) 
        {  
            if (key[i] == key[j] && key[i] != ' ') 
            {  
                count++;  
                key[j] = '0';  
            }  
        }  
        //A character is considered as duplicate if count is greater than 1  
        if (count > 1 && key[i] != '0')
        {
            printf("Key may not contain duplicate characters!\n");
            return 1;
        }
        
    }
    //Get plaintext from user input
    string msg = get_string("plaintext: ");
    printf("ciphertext: ");
    
    for (int i = 0, n = strlen(msg) ; i < n; i++)
    {
        //Loop through lower case characters and replace with character in key, return lowercase character.
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            printf("%c", tolower(charSub(msg[i], key)));
            
        }
        //Loop through lower case characters and replace with character in key, return uppercase character
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            printf("%c", toupper(charSub(msg[i], key)));

        }
        else
        {
            printf("%c", msg[i]);
        }
    }
    //Print blank line at the end.
    printf("\n");
    return 0;
}

char charSub(char c, string key)
{
    //Get index for character and return that index from the key value.
    char alpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    for (int i = 0, n = strlen(key) ; i < n; i++)
    {
        if (toupper(c) == alpha[i])
        {
            return key[i];
        }
    }
    return 0;
}
