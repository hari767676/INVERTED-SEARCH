#include <string.h>
#include "main.h"
#include <stdio.h>

int save_db(Main *arr[])
{
    char file[50];

    printf("\033[1mENTER THE OUTPUT FILE NAME TO SAVE DATABASE: \033[0m");
    scanf("%s", file);

    if (strcmp(strstr(file, "."), ".txt") == 0)
    {
        printf("\033[1m%s HAS .TXT EXTENSION\033[0m\n", file);
    }
    else
    {
        printf("\033[1mERROR: ENTER A FILE WITH .TXT EXTENSION\033[0m\n");
        return FAILURE;
    }

    FILE *fptr = fopen(file, "w");
    if (fptr == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s for writing.\n", file);
        return FAILURE;
    }

    for (int i = 0; i < 28; i++)
    {
        Main *temp_main = arr[i];

        while (temp_main != NULL)
        {
            fprintf(fptr, "#%d;%s;%d;", i, temp_main->word, temp_main->file_count);

            sub *temp_sub = temp_main->sublink;
            while (temp_sub != NULL)
            {
                fprintf(fptr, "%s;%d;", temp_sub->f_name, temp_sub->word_count);
                temp_sub = temp_sub->sublink;
            }
            fprintf(fptr, "#\n");

            temp_main = temp_main->mainlink;
        }
    }

    fclose(fptr);

     printf("\033[1mDATABASE SUCCESSFULLY SAVED TO %s\033[0m\n", file);
    
    return SUCCESS;
}
