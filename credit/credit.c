#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

//Prompt the user for the credit card number

    long nc;

    do
    {
        nc = get_long("Number:");
    }
    while (nc < 0);

    long number = nc;    //saving the number because he is lost on the lenght calculation
    long number2 = nc;

//Test number by printing
//printf("%ld\n", number);

//Get the lenght of the Number

    int lenght = 0;

    for (lenght = 0; nc != 0; lenght++)
    {
        nc = nc / 10;
    }

//Test the lenght
//printf ("%i\n", lenght);

//Luhn’s Algorithm

    int num1 = 0;
    int aux1 = 0;
    int num2 = 0;
    int aux2 = 0;
    int aux22 = 0;
    int aux23 = 0;
    int checksum = 0;
    int checksum2 = 0;

    do
    {
        aux1 = number % 10;
//        printf("aux1: %i\n", aux1);
        num1 = num1 + aux1;
        number = number / 10;
        aux2 = number % 10;
//        printf("aux2: %i\n", aux2);
        aux2 = aux2 * 2;

        if (aux2 >= 10)
        {
            aux22 = aux2 % 10;
            aux23 = aux2 / 10;
            aux2 = aux22 + aux23;
            num2 = num2 + aux2;
            number = number / 10;
        }
        else
        {
            num2 = num2 + aux2;
            number = number / 10;
        }
    }
    while (number != 0);

    checksum = num1 + num2;
    checksum2 = checksum % 10;

//    printf("checksum2: %i\n", checksum2);


//    printf("numero1: %i\n", num1);
//    printf("numero2: %i\n", num2);
//    printf("check: %i\n", checksum);

//American Express uses 15-digit numbers and starts with 34 or 37
//MasterCard uses 16-digit numbers and starts with 51, 52, 53, 54, or 55
//Visa uses 13- and 16-digit numbers and starts with 4

    int visa = 0;
    int amex = 0;
    int master = 0;

    if (checksum2 == 0)
    {
        //Visa uses 13- and 16-digit numbers and starts with 4
        //MasterCard uses 16-digit numbers and starts with 51, 52, 53, 54, or 55
        if (lenght == 13 || lenght == 16)
        {
            if (lenght == 13)
            {
                visa = number2 / pow(10, 12);
                if (visa == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (lenght == 16)
            {
                visa = number2 / pow(10, 15);
                master = number2 / pow(10, 14);
                //printf("numero final master: %i\n", master);
                //printf("numero final visa: %i\n", visa);
                if (visa == 4)
                {
                    printf("VISA\n");
                }
                else if (master == 51 || master == 52 || master == 53 || master == 54 || master == 55)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        //American Express uses 15-digit numbers and starts with 34 or 37
        else if (lenght == 15)
        {
            amex = number2 / pow(10, 13);
            if (amex == 34 || amex == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}