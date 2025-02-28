#include "main.h"
#include <stdio.h>
#include <string.h>

void display(Main *arr[])
{
    printf("\033[1;32m");

    printf("%-10s %-15s %-10s %-15s %-10s\n", "Index", "Word", "File_Count", "File_Name", "Word_Count");
    printf("%-10s %-15s %-10s %-15s %-10s\n", "-----", "------------", "----------", "------------", "----------");

    for (int i = 0; i < 28; i++)
    {
        Main *temp = arr[i];
        if (temp == NULL)
        {
            continue;
        }
        else
        {
            while (temp != NULL)
            {
                printf("%-10d %-15s %-10d", i, temp->word, temp->file_count);

                sub *temp1 = temp->sublink;
                int isFirstSubLink = 1; 

                while (temp1 != NULL)
                {
                    if (!isFirstSubLink)
                    {
                        printf("%-10s %-15s %-10s", "", "", "");
                    }

                    printf("%-15s %-10d\n", temp1->f_name, temp1->word_count);
                    temp1 = temp1->sublink;

                    isFirstSubLink = 0;
                }

                if (isFirstSubLink)
                {
                    printf("\n");
                }

                temp = temp->mainlink;
            }
        }
    }
    printf("\033[0m");
}


