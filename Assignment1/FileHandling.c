//
// Created by Darren on 18/03/2021.
//

#include "header.h"
#include "LinkedList.h"


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

extern int bookCount;
/** =================================FILE HANDLING =============================================== */
void saveToFileLinkedList() {

    FILE *fp;
    NODE * current ;
    current = list;
    errno_t err;
    int count=0;

    if ((err = fopen_s(&fp, "books.dat", "wb")) == 0) {

        while (current != NULL) {
            fwrite(current->element, sizeof(BOOK), 1, fp);
            current = current->next;
            count++;
        }
        printf("%d - Books saved to File - books.dat\n",count);

        fclose(fp);
    }else {
        printf("Error opening file for writing - books.dat\n");
    }
}

void getFromFileLinkedList() {
    FILE *fp;
    errno_t err;

    BOOK * bookPtr = (BOOK *)malloc(sizeof(BOOK));
    bookCount = 0;
    err = fopen_s(&fp, "books.dat", "rb");

    if (err != 0) {
        printf("cannot open file books.dat: %d\n", err);
    } else {
//        printf("Retrieving books from file...%s %d %d\n", "books.dat", sizeof(BOOK), sizeof(NODE)); /** Debug only **/

        while(fread(bookPtr, sizeof(BOOK), 1, fp)!=0) {
            if (bookCount == 0) { // mMust be first book if list is null
                addNewList(bookPtr);
            } else { // subsequent books
                addToEnd(bookPtr);
            }
            bookCount++;
            //printf("Book Count : %d %s\n", bookCount, bookPtr->title);

        }
        printf("Books retrieved = %d\n\n", bookCount);
        fclose(fp);
    }

}

