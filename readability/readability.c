#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    //Getting the number of letters in the text.
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letters++;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            letters++;
        }
        else
        {

        }
    }
    //Test number of letters
    //printf("%i letter(s)\n", letters);

    //Getting the number of words in the text.
    int words = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {

        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {

        }
        else if (text[i] == 33 || text[i] == 34 || text[i] == 39 || text[i] == 44 || text[i] == 46 || text[i] == 45 || text[i] == 58
                 || text[i] == 59 || text[i] == 96)
        {

        }
        else
        {
            words++;

        }
    }
    int words2 = 0;
    words2 = words + 1;
    //Testing the number of words
    //printf("%i word(s)\n", words2);

    //Getting the number of sentences in the text.
    int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
        else
        {

        }
    }
    //Testing the number of sentences
    //printf("%i sentence(s)\n", sentences);

    //Putting it All Together
    float L = (letters / (float)(words2)) * 100;
    float S = (sentences / (float)(words2)) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}