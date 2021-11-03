#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    int cents, coins;
    do
    {
        dollars = get_float("Type in your change:\n");
    }
    while (dollars <= 0);
    //Rounding up the change
    cents = round(dollars * 100);
    coins = 0;
    
    //Counting the change 
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    } 
    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }
    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }
    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }
    printf("%i\n", coins);
}
