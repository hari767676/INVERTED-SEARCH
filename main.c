
#include <stdio.h>
#include <string.h>
#include "main.h"

int main(int argc, char *argv[])
{
    int option;
    int isDatabaseCreated = 0; 
    int isUpdated = 0; 
    Main *arr[28] = {NULL};
    Slist *head = NULL;

    if (read_and_validate_files(argc, argv, &head) == SUCCESS)
        printf("\033[1;32mREAD AND VALIDATION SUCCESSFUL\033[0m\n"); 
    else
        printf("\033[1;31mREAD AND VALIDATION FAILED\033[0m\n"); 

    do
    {
        printf("\033[1m----------------------------------------------\033[0m\n");
        printf("\033[1m1. CREATE DATABASE\033[0m\n");
        printf("\033[1m2. DISPLAY DATABASE\033[0m\n");
        printf("\033[1m3. SEARCH DATABASE\033[0m\n");
        printf("\033[1m4. SAVE DATABASE\033[0m\n");
        printf("\033[1m5. UPDATE DATABASE\033[0m\n");
        printf("\033[1m6. EXIT\033[0m\n");
        printf("\033[1m----------------------------------------------\033[0m\n");
        printf("\033[1mENTER THE OPTION: \033[0m");

        scanf("%d", &option);

        switch (option)
        {
            case 1:
                if (!isDatabaseCreated || isUpdated)  
                {
                    if (create(&head, arr) == SUCCESS)
                    {
                        printf("\033[1;32mCREATE DATABASE SUCCESSFUL\033[0m\n");
                        isDatabaseCreated = 1; 
                        isUpdated = 0; 
                    }
                    else
                    {
                        printf("\033[1;31mDATABASE CREATION FAILED\033[0m\n");
                    }
                }
                else
                {
                    printf("\033[1;31mDATABASE ALREADY CREATED. TO CREATE AGAIN, UPDATE THE DATABASE FIRST.\033[0m\n");
                }
                break;

            case 2:
                display(arr);
                break;

            case 3:
                if (search_db(arr) == SUCCESS)
                {
                    printf("\033[1;32mSEARCH SUCCESSFUL\033[0m\n");
                }
                break;

            case 4:
                save_db(arr);
                printf("\033[1;32mDATABASE SAVED SUCCESSFULLY\033[0m\n");
                break;

            case 5:
                if (!isUpdated)  
                {
                    if (update(arr) == SUCCESS)
                    {
                        printf("\033[1;32mDATABASE UPDATE COMPLETED.\033[0m\n");
                        isUpdated = 1;  
                    }
                    else
                    {
                        printf("\033[1;31mDATABASE UPDATE FAILED.\033[0m\n");
                    }
                }
                else
                {
                    printf("\033[1;31mDATABASE HAS ALREADY BEEN UPDATED. CANNOT UPDATE AGAIN\033[0m\n");
                }
                break;

            case 6:
                printf("\033[1;32mEXIT SUCCESSFUL!!\033[0m\n");
                break;

            default:
                printf("\033[1;31mINVALID OPTION\033[0m\n");
                break;
        }

    } while (option != 6);

    return SUCCESS;
}
