#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// atoi() in stdlib.h converts a string into a number, Key go string into a integer
// isalpha() - treat the character is true if is a alphabetic letter
// isupper() - treat the character is true if is a capital letter
// toupper() - transform lowercase on upper, if is already upper, return the same letter
// islower() - treat the character is true if is a lower letter
// strlen() - tell you how many characters are in the string
// isdigit() - checks for a digit (0 through 9)

//$ ./substitution               --> Usage: ./substitution key
//$ ./substitution JTREKYAVO     --> Key must contain 26 characters.
//$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMO2 --> Key must only contain alphabetic characters.
//$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOV --> Key must not contain repeated characters.

int main(int argc, string argv[])
{
    // restricting to null values or more than one variables
    if (argv[1] == '\0' || argv[2] != '\0')
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int lenght = strlen(argv[1]);

    // verifying if input have 26 characters
    if (lenght != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Creating a auxiliar list to save capital letters and test it
    int aux2[26];

    for (int i = 0; i != 26; i++)
    {
        aux2[i] = toupper(argv[1][i]);
    }

    for (int i = 0; i != lenght; i++)
    {
        //Testing if have just alphabetic letters
        int aux = isalpha(argv[1][i]);

        if (aux == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        //Testing if have repeated letters
        for (int j = 1; aux2[i + j] != '\0'; j++)
        {
            if (aux2[i] == aux2[i + j])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    int lenght2 = strlen(plaintext);
    int ciphertext[lenght2];

    for (int i = 0; i != lenght2; i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            int up = plaintext[i] - 65;
            ciphertext[i] = toupper(argv[1][up]);
        }
        else if (islower(plaintext[i]) != 0)
        {
            int low = plaintext[i] - 97;
            ciphertext[i] = tolower(argv[1][low]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: ");
    for (int i = 0; i != lenght2; i++)
    {
        printf("%c", ciphertext[i]);
    }

    printf("\n");
}