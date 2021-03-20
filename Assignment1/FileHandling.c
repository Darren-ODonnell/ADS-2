//
// Created by Darren on 18/03/2021.
//

#include "header.h"


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
/** =================================FILE HANDLING =============================================== */
void saveToFileLinkedList() {

    FILE *fp;
    NODE * current ;
    current = list;
    errno_t err;

    printf("Saving books to file...%s\n","books.dat");

    if ((err = fopen_s(&fp, "books.dat", "wb")) != 0) {
        printf("File opened - books.dat\n");
        int count = 0;
        while (current != NULL) {
            BOOK * book = current->element;
            fwrite(&book, sizeof(BOOK), 1, fp);
            current = current->next;
            count++;
        }
        printf("%d - Books saved to File - books.dat\n",count);

        fclose(fp);
    }else {
        printf("Error opening file for writing - books.dat\n");
    }
}

int getFromFileLinkedList() {
    int count = 0;
    FILE *fp;
    errno_t err;
    list = last = NULL;

    BOOK * book;

    if ((err = fopen_s(&fp, "books.dat", "rb")) != 0)
        printf("Unable to open file - books.dat\n");
    else {
        printf("Retrieving books from file...%s\n", "books.dat");

        while ((fread(&book, sizeof(BOOK), 1, fp)) != 0) {
            if (list == NULL) { // empty list
                list->element = book;
                last = list;
                last->next = NULL;
                // list = last = node;
            } else {
                NODE * node = malloc(sizeof(*node));
                node->element = book;
                node->next = NULL;

            }
            printf("Book Count : %d %s\n", count, book->title);

            last->next = NULL;
            count++;
        }
        printf("Books retrieved = %d\n", count);
        fclose(fp);
    }
    return count;
}