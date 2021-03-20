//
// Created by Darren on 12/03/2021.
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef DARREN01_HEADER_H
#define DARREN01_HEADER_H
#include "header.h"
#include "Reports.h"
#endif //DARREN01_HEADER_H

/**********************************************************************************************
 *********              Reports
 **********************************************************************************************/
void viewPopular() {

    char most[50] = "";
    int mostCount=0; // set high to begin with
    NODE * current = list;

    while(current != NULL) {
        if (current->element->loanCount > mostCount) {
            mostCount = current->element->loanCount;
            strcpy_s(most, sizeof(most), current->element->title);
        }
        current = current->next;
    }
    printf("Most Borrowed Book  : %s\n",most);
}

void viewUnpopular() {

    char least[50] = "";
    int leastCount=100; // set high to begin with
    NODE * current = list;

    while(current != NULL) {
        if (current->element->loanCount < leastCount) {
            leastCount = current->element->loanCount;
            strcpy_s(least, sizeof(least), current->element->title);
        }
        current = current->next;
    }
    printf("Least Borrowed Book : %s\n\n",least);
}

void displayBooksLinkedList() {
    NODE * current = list;
    int i = 1;
    printf("Printing book titles\n");
    while (current != NULL) {
        BOOK * book = current->element;
        char  * id = book->id ;
        char * title = book->title;

        char availability[6];
        if(book->available){
            strcpy(availability, "True");
        }else{
            strcpy(availability, "False");
        }
        printf("%d - ",i++);
        printf("BookID: %s -- Avail: %s -- Name: %s\n", id, availability, title);
        current = current->next;
    }
}

void reportCostOfBooksSummary() {
/** Sample Report
+----------------------------------------+
|     Library Financial Book Report      |
+----------------------------------------+
      Number of Books in Library :  20
  Total Cost of Books in Library :  250
Average Cost of Books in Library :  12
==========================================

Most Borrowed Book  : The BFG
Least Borrowed Book : Demon Dentist

==========================================
*/

    char most[50] = "";
    char least[50] = "";
    int mostCount=0;
    int leastCount=100;

    NODE * current = list;
    int count = 0;
    int totalCost = 0;

    while(current != NULL) {
        totalCost += current->element->cost;

        if (current->element->loanCount > mostCount) {
            mostCount = current->element->loanCount;
            strcpy_s(most, sizeof(most), current->element->title);
        }

        if (current->element->loanCount < leastCount) {
            leastCount = current->element->loanCount;
            strcpy_s(least, sizeof(least), current->element->title);
        }
        current = current->next;
        count++;
    }

    printf("%35s %d\n","Number of Books in Library : " , count);
    printf("%35s %d\n","Total Cost of Books in Library : ", totalCost);
    printf("%35s %d\n","Average Cost of Books in Library : ", totalCost/count);
    reportEnding();
    viewUnpopular();
    viewPopular();
    countBooksOnLoan();
    countBooksAvailable();


}

void reportHeader() {
    printf("\n+----------------------------------------+\n");
    printf("|          Library Book Report           |\n");
    printf("+----------------------------------------+\n");
}

void reportEnding() {
    printf("==========================================\n\n");
}

void countBooksOnLoan() {

    int booksOnLoan = 0;
    NODE * current = list;

    while(current != NULL) {
        if (current->element->available)
            booksOnLoan++;
        current = current->next;
    }
    printf("Books on Loan from Library: %d\n",booksOnLoan);

}

void countBooksAvailable() {
    int booksAvailable = 0;
    NODE * current = list;

    while(current != NULL) {
        if (!current->element->available)
            booksAvailable++;
        current = current->next;
    }
    printf("Books available in the Library: %d\n",booksAvailable);
}