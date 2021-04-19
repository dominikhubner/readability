#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


float count_letters(char *text);
float count_words(char *text);
float count_sentences(char *text);
char *inputString(FILE* fp, size_t size);

int main(void)
{
    char *text;
    printf("Text: ");
    text = inputString(stdin, 10);
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
    free(text);
}

float count_letters(char *text)
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

float count_words(char *text)
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

float count_sentences(char *text)
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

char *inputString(FILE* fp, size_t size){   //source: https://stackoverflow.com/a/16871702/12313613
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}