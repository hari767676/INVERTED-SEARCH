#include "main.h"

int update(Main **arr)
{
    char buffer[25];
    int flag = 0;

   
    printf("\033[1mENTER THE FILE NAME TO UPDATE THE DATABASE FROM: \033[0m");
    scanf("%s", buffer);

    if (strstr(buffer, ".") != NULL)
    {
        if (strcmp(strstr(buffer, "."), ".txt") == 0)
        {
            flag = 1;
        }
        else
        {
             printf("\033[1mPLEASE ENTER A .TXT FILE\033[0m\n");
            return FAILURE;
        }
    }
    else
    {
        printf("\033[1mPLEASE ENTER A .TXT FILE\033[0m\n");
        return FAILURE;
    }

    if (flag)
    {
        char buffer1[256];
        int index = 0;

        FILE *ftemp = fopen(buffer, "r");
        if (ftemp == NULL)
        {
            perror("File open failed");
            return FAILURE;
        }

        while (fscanf(ftemp, "%s", buffer1) != EOF)
        {
            char *token = strtok(&buffer1[1], ";");
            if (token == NULL)
            {
                fprintf(stderr, "Error parsing index\n");
                continue;
            }
            index = atoi(token);

            Main *temp = arr[index];
            Main *new = malloc(sizeof(Main));
            if (new == NULL)
            {
                fprintf(stderr, "Memory allocation failed\n");
                fclose(ftemp);
                return FAILURE;
            }

            strcpy(new->word, strtok(NULL, ";"));
            new->file_count = atoi(strtok(NULL, ";"));

            sub *new1 = malloc(sizeof(sub));
            if (new1 == NULL)
            {
                fprintf(stderr, "Memory allocation failed\n");
                free(new);
                fclose(ftemp);
                return FAILURE;
            }

            strcpy(new1->f_name, strtok(NULL, ";"));
            new1->word_count = atoi(strtok(NULL, ";"));
            new->sublink = new1;
            new->mainlink = NULL;
            new1->sublink = NULL;

            for (int i = 1; i < new->file_count; i++)
            {
                sub *temp = malloc(sizeof(sub));
                if (temp == NULL)
                {
                    fprintf(stderr, "Memory allocation failed\n");
                    fclose(ftemp);
                    return FAILURE;
                }

                strcpy(temp->f_name, strtok(NULL, ";"));
                temp->word_count = atoi(strtok(NULL, ";"));
                new1->sublink = temp;
                new1 = temp;
            }

            if (arr[index] == NULL)
            {
                arr[index] = new;
            }
            else
            {
                while (temp->mainlink != NULL)
                {
                    temp = temp->mainlink;
                }
                temp->mainlink = new;
            }
        }

        fclose(ftemp);
    }

    return SUCCESS;
}
