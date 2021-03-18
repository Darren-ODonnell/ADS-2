/** This is a binary file that stores structures from an array into a binary file 
*   Note that you will have to update this code to use it with a linked list for 
*   the assignment 
*/
#include "header.h"


//Function prototypes
void saveToFileLinkedList(FILE *, NODE *);
void displayBooksLinkedList();
//void getFromFileLinkedList(FILE *);

char bookFile[10];

void saveToFileLinkedList(FILE *fp, NODE *books) {

    NODE * current = nullptr;
    current = books;
    printf("Saving books to file...%s\n",bookFile);

    fp = fopen(bookFile, "wb");

    while(current != nullptr) {
        fwrite(&current, sizeof(NODE), 1, fp);
        current = current->next;
    }

    fclose(fp);
}

void displayBooksLinkedList() {
    NODE * current = list;

    while (current != nullptr) {
        printf("BookID: %s -- Name: %s\n", current->element->id, current->element->title);
        current = current->next;
    }

}

//void getFromFileLinkedList(FILE *fp)  {
//    int i = 0;
//    char c;
//    printf("Retrieving students from file...%s\n",bookFile);
//    while (fread(&classOfStudents[i], sizeof(NODE), 1, fp) != 0)
//        i++;
//    fclose(fp);
//}
