//
// Created by Darren on 03/03/2021.
//
/**************************************************************/
/*                                                            */
/*   Program to demonstrate the implementation of a simple    */
/*   linked list of numbers with a delete function.			  */
/*                                                            */
/**************************************************************/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef DARREN01_HEADER_H
#define DARREN01_HEADER_H
#include "header.h"
#include "LinkedList.h"
#endif //DARREN01_HEADER_H
extern int bookCount;

/**
 * Create a new list and add book as first book at top list
 * @param aBook
 */
void addNewList(BOOK * aBook) {
    list = malloc(sizeof( NODE ));
    list->element = malloc(sizeof( BOOK ));
    last = list;

    bookCopy(list->element,aBook);
    last->next = NULL;
}

/**
 * subsequent books are added to the end (or at last)
 * @param aBook
 */
void addToEnd(BOOK * aBook) {

    last->next = malloc(sizeof( NODE ));
    last->next->element = malloc(sizeof( BOOK ));

    last = last->next;
    bookCopy(last->element,aBook);

    last->next = NULL;
}

/**
* Check if ID is already in list before attempting to add a new book.
* @param id
* @return
*/
bool idInList(char * in){
    NODE *current = list;
    while( current != NULL){
        if( strcmp(current->element->id, in) == 0) {
            return false;
        }
        current = current->next;
    }
    return true;
}

/**
 * Using to copy the contents of a book just entered to the libary linkedlist.
 * @param aBook
 * @param newBook
 */
void bookCopy(struct data *aBook, struct data *newBook) {

    strcpy_s(aBook->customerName, 30, newBook->customerName);
    strcpy_s(aBook->author, 30, newBook->author);
    strcpy_s(aBook->title, 50, newBook->title);
    strcpy_s(aBook->id, 10, newBook->id);
    aBook->cost = newBook->cost;
    aBook->available =  newBook->available;
    aBook->loanCount =  newBook->loanCount;
    aBook->publicationYear =  newBook->publicationYear;

}

/**
 * Get a node at an index in the library
 * Bookcount is used to keep track of how many books in libary
 * @param index
 * @param bookCount
 * @return
 */
NODE * get(int index){

    if(index > bookCount) {
        printf("Index to get is out of range");
    } else {
        if (list != NULL) {
            NODE *node;
            node = list;
            for (int i = 1; i < index; i++) {
                node = node->next;
            }
            return node;
        }
    }
    return NULL;
}

/**
 * Delete node based on its ID number
 * @param id
 */
void deleteWithID(char * id) {
    NODE *before = malloc(sizeof(NODE));
    NODE *current = malloc(sizeof(NODE));

    //Placeholder for pointer to allow space to be freed up.
    NODE *spaceToClear;

    printf("id to delete %s BookCount %d\n",id, bookCount);

    for(int i = 0; i <= bookCount; i++) {
        current = get(i);
        if (i > 0) { // before does not exist for first node
            before = get(i - 1);
        }

        //if current is equal to id, delete id

        if ((strcmp(current->element->id, id))== 0) {

            if(current == list){ // first in list
                spaceToClear = list;
                list = list->next;

            }else if (current == last) { //last in list

                printf("id to delete as last: %s\n", id);
                spaceToClear = last;

                before->next = NULL;

                last = before;

            }else{ //not first or last
                before->next = current->next;
                spaceToClear = current;

            }
            free(spaceToClear);
            bookCount--;
            return; // no need to continue in for loop if node has been deleted
        }
    }
}

/**
 * View node - by viewing the element in node
 * @param node
 */
void viewBookInNode(NODE * node){
    viewBookContents(node->element);
}

/**
 * View the contents of the book within the node
 * @param book
 */
void viewBookContents(BOOK * book){
    char availability[6];
    if(book->available){
        strcpy(availability, "True");
    }else{
        strcpy(availability, "False");
    }
    printf("\n\nNode ID:%s"
           "\nNode Title:%s"
           "\nNode Author:%s"
           "\nNode publicationYear:%d"
           "\nNode Available:%s"
           "\nNode customerName:%s"
           "\nNode loanCount:%d"
           "\nNode Book Cost:%d\n"
            ,book->id
            ,book->title
            ,book->author
            ,book->publicationYear
            ,availability
            ,book->customerName
            ,book->loanCount
            ,book->cost);
}

/**
 * View book based on its ID
 * @param id
 */
void viewWithID(char * id){
    NODE *node = getByID(id);

    if(node != NULL){
        printf("Inside ViewWithID %s \n", id);
        viewBookInNode(node);
    }else{
        printf("There are no books with ID: %s \n", id);
    }

}

/**
 * Return book based on its ID
 * @param id
 * @return
 */
NODE * getByID(char * id){

    NODE *node = list;
    node->next = list->next;


    while(node != NULL){
        if(strcmp(node->element->id, id) == 0){//If the two IDs are the same
            return node;
        }else {
            node = node->next;
        }

    }
    return NULL;
}






