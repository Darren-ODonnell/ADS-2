//
// Created by Darren on 11/03/2021.
//
//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <accctrl.h>
#include <stdbool.h>
#include <errno.h>


// template for a book
typedef struct data {
    char id[10];
    char title[50];
    char author[30];
    int publicationYear;
    bool available;
    char customerName[30];
    int loanCount;
    int cost;
} BOOK;

// template for one node
typedef struct LinearNode {
    struct data *element;
    struct LinearNode *next;
} NODE;

NODE *list;
NODE *last;