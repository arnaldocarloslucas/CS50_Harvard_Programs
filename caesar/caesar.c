#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// atoi() in stdlib.h converts a string into a number, Key go string into a integer
// isalpha() - treat the character is true if is a alphabetic letter
// isupper() - treat the character is true if is a capital letter
// islower() - treat the character is true if is a lower letter
// strlen() - tell you how many characters are in the string

int main(int argc, string argv[])
{
    // restricting to null values and initiang with 0
    if (argv[1] == '\0' || argv[2] != '\0' || argv[1][0] == '0')
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int lenght = strlen(argv[1]);
    for (int i = 0; i != lenght; i++)
    {
        int aux = isalpha(argv[1][i]);
        // restricting the alphabetics in the key and non-negative integer
        if (aux != 0 || argv[1][i] == 45)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Converting the string to int
    int key = atoi(argv[1]);
    // Getting the plaintext
    string plaintext = get_string("plaintext: ");
    int lenght2 = strlen(plaintext);

    for (int i = 0; i != lenght2; i++)
    {
        char letter = plaintext[i];
        // If is uppercase, transform to alphabetic index and calculates, and returns
        if (isupper(letter) != 0)
        {
            char convert1 = letter - 65;
            int new1 = (convert1 + key) % 26;
            char newletter = new1 + 65;
            plaintext[i] = newletter;
        }
        // If is lowercase, transform to alphabetic index and calculates, and returns
        else if (islower(letter) != 0)
        {
            char convert1 = letter - 97;
            int new1 = (convert1 + key) % 26;
            char newletter = new1 + 97;
            plaintext[i] = newletter;
        }
    }
    printf("ciphertext: %s\n", plaintext);

}
