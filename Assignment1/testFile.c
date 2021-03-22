//
// Created by Darren on 21/03/2021.
//
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


int main() {
    FILE *fp;
    errno_t err;

    struct data book;
    struct data * bookPt = malloc(sizeof(BOOK));
    struct data * bookPtr = &book;

    if((err = fopen_s(&fp,"books.dat", "rb")) != 0) {
        printf("File cant be opened\n");
    } else {
        printf("File has been opened\n");
    }
    fseek(fp,0,SEEK_SET);
    int count = 0;
    while(fread(&book,sizeof(BOOK), 1, fp) != 0) {
        count++;
        printf("%d %s\n",count, book.id);

    }
}

