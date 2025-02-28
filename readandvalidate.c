#include "main.h"
#include <stdio.h>
#include <string.h>
void print_sll(Slist *head);
int insert_file_to_sll(Slist **head, char *argv);
int read_and_validate_files(int argc, char *argv[], Slist **head)
{
    for (int i = 1; i < argc; i++)
    {
        char *ext = strstr(argv[i], ".txt");
        if (ext != NULL && strcmp(ext, ".txt") == 0)
        {
        //    printf("\033[1;32mValidated file %d: %s\033[0m\n", i, argv[i]);
        }
        else
        {
            continue;
        }
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            continue;
        }

        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fseek(file, 0, SEEK_SET); 

        if (size <= 0)
        {
            fclose(file);
            continue;
        }
        fclose(file);

        if (insert_file_to_sll(head, argv[i]) == SUCCESS)
        {
            continue;
        }
    }
     print_sll(*head);
    return SUCCESS;
}

int insert_file_to_sll(Slist **head, char *argv)
{
    Slist *temp = *head;
    while (temp != NULL)
    {
        if (strcmp(temp->file_name, argv) == 0)
        {
            return FAILURE;
        }
        temp = temp->link;
    }

    Slist *new_node = malloc(sizeof(Slist));
    if (new_node == NULL)
    {
        fprintf(stderr, "ERROR: Memory allocation failed.\n");
        return FAILURE;
    }

    strcpy(new_node->file_name, argv);
    new_node->link = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        temp = *head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new_node;
    }
    return SUCCESS;
}

void print_sll(Slist *head)
{
    if (head == NULL)
    {
        printf("\033[1;31mINFO: List empty\033[0m\n");
        return;
    }

    Slist *temp = head;
    printf("\033[1;33mLIST : \033[0m");
    printf("\033[1;33mHead-> ");
    while (temp != NULL)
    {
        printf("%s", temp->file_name);
        if (temp->link != NULL)
            printf(" -> ");
        
        temp = temp->link;
    }
     printf(" -> ");
     printf("NULL");
     printf("\033[0m\n");
}