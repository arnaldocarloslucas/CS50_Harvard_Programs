#include <stdio.h>
#include <cs50.h>

int main(void)
{
//Prompt the user the height

    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

//TEST height
//printf("%i\n", height);

//Buildings the columns

    for (int i = 0; i < height; i++)
    {
        for (int k = i + 1; k < height; k++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        for (int l = 0; l <= 1; l++)
        {
            printf(" ");
        }
        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}
