#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do{
        height = get_int("Type in the pyramid height:\n");
    }
    while (height < 1 || height > 8);

    for (int row = 0; row < height; row++)
    {
        // Loop to add spaces
        for (int space = height - row; space > 1; space--)
        {
            printf(" ");
        }
        // Loop to add hashes
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
