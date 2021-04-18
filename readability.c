#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    float l = letters / words * 100.0;
    float s = sentences / words * 100.0;
    float result = 0.0588 * l - 0.296 * s - 15.8;
    int result_round = round(result);
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result_round);
    }
}

float count_letters(string text)
{
    float length = strlen(text);
    float letters = 0;
    for (int i = 0; i < length; i++)
    {
        float character = text[i];
        if (character >= 65 && character <= 90)
        {
            letters++;
        }
        else if (character >= 97 && character <= 122)
        {
            letters++;
        }
    }
    return letters;
}

float count_words(string text)
{
    int length = strlen(text);
    float words = 0;
    for (int i = 0; i < length; i++)
    {
        float character = text[i];
        if (character == 32)
        {
            words++;
        }
    }
    int a = text[length - 1];
    if (a == 46)
    {
        words++;
    }
    return words;
}

float count_sentences(string text)
{
    float length = strlen(text);
    float sentences = 0;
    for (int i = 0; i < length; i++)
    {
        float character = text[i];
        if (character == 46 || character == 33 || character == 63)
        {
            sentences++;
        }
    }
    return sentences;
}