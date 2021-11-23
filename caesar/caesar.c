#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void cipher(string text, int text_len, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        char * p;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        long key = strtol(argv[1], &p, 10);

        string text = "";
        int text_len = strlen(text);
        while (text_len == 0)
        {
            text = get_string("plainext: ");
            text_len = strlen(text);
        }

        printf("ciphertext: ");
        //Cypher function
        cipher(text, text_len, key);
    }
}

void cipher(string text, int text_len, int key)
{
    for (int i = 0; i < text_len; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {

            printf("%c", ((((text[i] - 'a') + key) % 26) + 'a'));;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            printf("%c", ((((text[i] - 'A') + key) % 26) + 'A'));;
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}