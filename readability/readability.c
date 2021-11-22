#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// index = 0.0588 * L - 0.296 * S - 15.8

int count_letters(string str);
int count_words(string str);
int count_sentences(string str);
float calculate_index(int letters, int words, int sentences);

int main(void)
{

    string text = "";
    int letters_count = 0;
    int words_count = 0;
    int sentences_count = 0;
    float index = 0;

    while(strlen(text) <= 0)
    {
        text = get_string("Text: ");
    }
    if(strlen(text) < 2)
    {
        printf("Invalid text, try again.\n");
        return 0;
    }
    else
    {
        letters_count = count_letters(text);
        words_count = count_words(text);
        sentences_count = count_sentences(text);

        index = calculate_index(letters_count, words_count, sentences_count);
        int grade = round(index);
        if(grade > 1 && grade < 16)
        {
            printf("Grade %i\n", grade);
        }
        else if(grade >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Before Grade 1\n");
        }
    }
}

int count_letters(string str)
{
    int counter = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        // printf("%i\n", (int) str[i]);
        int current_char = (int) toupper(str[i]);
        if(current_char != 32)
        {
            if((current_char >= 65) && (current_char <= 90))
            {
                //printf("%c\n", (char) current_char);
                counter++;
            }
        }
    }
    return counter;
}

int count_words(string str)
{
    int counter = 1;
    for(int i = 0; i < strlen(str); i++)
    {
        if((int) str[i] == 32)
        {
            counter++;
        }
    }
    return counter;
}

int count_sentences(string str)
{
    int counter = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        int current_char = (int) str[i];
        if(current_char == 33 || current_char == 46 || current_char == 63)
        {
            counter++;
        }
    }
    return counter;
}

float calculate_index(int letters, int words, int sentences)
{
    return 0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sentences / (float) words) - 15.8;
}
