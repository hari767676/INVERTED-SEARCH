#include "main.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int search_db(Main *arr[])
{
    char word[30];
    int index;

    printf("\033[1mENTER THE WORD YOU WANT TO SEARCH IN DATABASE:\033[0m\n");
    scanf("%s", word);

    if (word[0] >= 'a' && word[0] <= 'z')
    {
        index = word[0] - 'a';
    }
    else if (word[0] >= 'A' && word[0] <= 'Z')
    {
        index = word[0] - 'A';
    }
    else if (word[0] >= '0' && word[0] <= '9')
    {
        index = 26; 
    }
    else
    {
        index = 27; 
    }

    Main *temp = arr[index];
    if (temp == NULL)
    {
        printf("\033[1mWORD NOT FOUND IN DATABASE.\033[0m\n");
        return DATA_NOT_FOUND;
    }

    while (temp != NULL)
    {
        if (strcmp(temp->word, word) == 0)
        {
            printf("\033[1mTHE WORD '%s' IS PRESENT IN %d FILES:\033[0m\n", word, temp->file_count);
            sub *stemp = temp->sublink;

            
            while (stemp != NULL)
            {
                 printf("\033[1m  FILE: %s -> %d TIMES\033[0m\n", stemp->f_name, stemp->word_count);
                stemp = stemp->sublink;
            }
            return SUCCESS;
        }
        temp = temp->mainlink; 
    }

    printf("\033[1mWORD NOT FOUND IN DATABASE.\033[0m\n");
    return DATA_NOT_FOUND;
}
