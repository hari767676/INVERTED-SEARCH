#include "main.h"
#include<string.h>
int create(Slist **head, Main *arr[]) 
{
    char buffer[26];
    int index = 0;
    Slist *temp = *head;

    while (temp != NULL) 
    {
        FILE *ftemp = fopen(temp->file_name, "r");
        if (!ftemp) 
        {
            printf("Error opening file: %s\n", temp->file_name);
            return FAILURE;
        }

        int file_processed = 0;
        for (int i = 0; i < 28; i++) 
        {
            Main *main_node = arr[i];
            while (main_node != NULL) 
            {
                sub *sub_node = main_node->sublink;
                while (sub_node != NULL) 
                {
                    if (strcmp(sub_node->f_name, temp->file_name) == 0) 
                    {
                        file_processed = 1; 
                        break;
                    }
                    sub_node = sub_node->sublink;
                }
                if (file_processed) break;
                main_node = main_node->mainlink;
            }
            if (file_processed) break;
        }

        if (file_processed) 
        {
            fclose(ftemp);
            temp = temp->link;
            continue;
        }
        while ((fscanf(ftemp, "%s", buffer)) != EOF) 
        {
            if (buffer[0] >= 'a' && buffer[0] <= 'z') 
            {
                index = buffer[0] - 'a';
            } 
            else if (buffer[0] >= 'A' && buffer[0] <= 'Z') 
            {
                index = buffer[0] - 'A';
            } 
            else if (buffer[0] >= '0' && buffer[0] <= '9') 
            {
                index = 26; 
            } 
            else 
            {
                index = 27;
            }
            if (arr[index] == NULL) 
            {
                Main *new = malloc(sizeof(Main));
                sub *new1 = malloc(sizeof(sub));
                if (new == NULL || new1 == NULL) 
                {
                    fclose(ftemp);
                    return FAILURE;
                }
                arr[index] = new;
                strcpy(new->word, buffer);
                new->file_count = 1;
                new->mainlink = NULL;
                new->sublink = new1;
                strcpy(new1->f_name, temp->file_name);
                new1->word_count = 1;
                new1->sublink = NULL;
            } 
            else 
            {
               
                Main *temp1 = arr[index];
                Main *prev1 = NULL;

                while (temp1 != NULL) 
                {
                    if (strcmp(temp1->word, buffer) == 0)
                     {
                        sub *temp2 = temp1->sublink;
                        sub *prev = NULL;

                        while (temp2 != NULL) 
                        {
                            if (strcmp(temp2->f_name, temp->file_name) == 0) 
                            {
                                temp2->word_count++;
                                goto end_word_processing;
                            }
                            prev = temp2;
                            temp2 = temp2->sublink;
                        }

                        sub *new2 = malloc(sizeof(sub));
                        if (new2 == NULL) 
                        {
                            fclose(ftemp);
                            return FAILURE;
                        }
                        prev->sublink = new2;
                        strcpy(new2->f_name, temp->file_name);
                        new2->word_count = 1;
                        new2->sublink = NULL;
                        temp1->file_count++;
                        goto end_word_processing;
                    }
                    prev1 = temp1;
                    temp1 = temp1->mainlink;
                }

            
                Main *new = malloc(sizeof(Main));
                sub *new1 = malloc(sizeof(sub));
                if (new == NULL || new1 == NULL) 
                {
                    fclose(ftemp);
                    return FAILURE;
                }
                prev1->mainlink = new;
                strcpy(new->word, buffer);
                new->file_count = 1;
                new->mainlink = NULL;
                new->sublink = new1;
                strcpy(new1->f_name, temp->file_name);
                new1->word_count = 1;
                new1->sublink = NULL;
            }

        end_word_processing:;
        }

        fclose(ftemp);
        printf("\033[1;32mDATABASE CREATED FOR FILE : %s\033[0m\n",temp->file_name);
        temp = temp->link;
    }
    return SUCCESS;
}
