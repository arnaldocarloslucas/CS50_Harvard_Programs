#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
//Prompt the user for the Change Owed

    float dollars;
    int quarter;
    int dime;
    int nickel;
    int penny;
    int reminder;
    int coins = 0;
    do
    {
        dollars = get_float("Change Owed:");
    }
    while (dollars <= 0);

//Test value
//printf("%.2f\n", dollars);

//Convert Dollars to Cents

    int cents = round(dollars * 100);

//Tracking the number of coins

    reminder = cents;

    while (reminder >= 25)
    {
        reminder = reminder - 25;
        coins++;
    }

    while (reminder >= 10)
    {
        reminder = reminder - 10;
        coins++;
    }

    while (reminder >= 5)
    {
        reminder = reminder - 5;
        coins++;
    }

    while (reminder >= 1)
    {
        reminder = reminder - 1;
        coins++;
    }

    printf("%.i\n", coins);

}