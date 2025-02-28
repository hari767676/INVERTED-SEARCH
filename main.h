#ifndef MAIN_H
#define MAIN_H

#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND -2
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct node
{
    char file_name[20];
    struct node *link;
} Slist;

typedef struct mainnode
{
    char word[100];
    int file_count;
    struct subnode *sublink;
    struct mainnode *mainlink;
}Main;

typedef struct subnode
{
    char f_name[100];
    int word_count;
    struct subnode *sublink;
}sub;

int create(Slist **head, Main *arr[]);
int search_db(Main *arr[]);
int read_and_validate_files(int argc, char *argv[], Slist **head);
int insert_file_to_sll(Slist **head, char *argv);
int save_db(Main *arr[]);
void display(Main *arr[]);
void display(Main *arr[]);
int update(Main *arr[]);
#endif
