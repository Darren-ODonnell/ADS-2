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

/**
 * Create a new list and add book as first book at top list
 * @param aBook
 */
void addNewList(BOOK * aBook) {
    list->element = aBook;
    last->element = aBook;
    last->next = NULL;

}

/**
 * subsequent books are added to the end (or at last)
 * @param aBook
 */
void addToEnd(BOOK * aBook) {
    last->next = (NODE *)malloc(sizeof(NODE ));
    last = last->next;
    last->element = (BOOK *)malloc(sizeof(BOOK));
    last->element = aBook;

    last->next = NULL;

}

//void enterNewNode(){
//
//    NODE *aNode;
//    BOOK anElement;
//
//    // add SIZE nodes to the list
//
//    //create space for new data element
//
//    printf("Size of struct data : %zd", sizeof(BOOK));
////    anElement = (struct data )malloc(sizeof(struct data));
//
//    // create space for new node
//    aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));
//
//    //Input Details
//
//    printf("Input the 8 digit ID: ");
//    scanf("%s", anElement.id);
//
//    printf("Input the title of the book: ");
//    scanf("%s", anElement.title);
//
//    printf("Input the Author of the book: ");
//    scanf("%s", anElement.author);
//
//    printf("Input the Publication Year of the book: ");
//    scanf("%d", &anElement.publicationYear);
//
//    printf("Input Your Name: ");
//    scanf("%s", anElement.customerName);
//
//    anElement.available = true;
//
//    anElement.loanCount = 0;
//
//
//    if (aNode == NULL)
//        printf("Error - no space for the new node\n");
//    else { // add data part to the node
//        aNode->next = NULL;
//        aNode->element = anElement;
//
//        //add node to front of the list
//        if (isEmpty())
//        {
//            list = aNode;
//            last = aNode;
//        }
//        else {
//            //aNode is the current node being input, set next to null
//            aNode->next = nullptr;
//            //current last positions next becomes tje node being input
//            last->next = aNode;
//            //the last is now the node being input
//            last = aNode;
//
//        } //end else
//        nodeCount++;
//    }//end else
//
//}
//
//void autoAddNode(char id[], char title[], char author[], int year, bool avail, char name[], int loanCount ) {
//    struct LinearNode *aNode;
//    struct data anElement;
//
//    // add SIZE nodes to the list
//
//    //create space for new data element
//
//    strcpy(anElement.title, title);
//
//
//
//    printf("Size of struct data : %zd", sizeof(struct data));
////    anElement = (struct data *)malloc(sizeof(struct data));
//
//    // create space for new node
//    aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));
//
//    if (aNode == NULL)
//        printf("Error - no space for the new node\n");
//    else { // add data part to the node
//        aNode->next = NULL;
//        aNode->element = anElement;
//
//        //add node to front of the list
//        if (isEmpty())
//        {
//            list = aNode;
//            last = aNode;
//        }
//        else {
//            //aNode is the current node being input, set next to null
//            aNode->next = nullptr;
//            //current last positions next becomes tje node being input
//            last->next = aNode;
//            //the last is now the node being input
//            last = aNode;
//
//        } //end else
//        nodeCount++;
//    }//end else
//}
//
///**********ADD THREE NODES TO THE LIST******************/
//// Each new node is added to the front of the list
//void addNodesToEnd(){
//    int i;
//    int aNumber;
//    NODE *aNode;
//    BOOK * enElement = malloc(sizeof(BOOK));
//    BOOK anElement;
//
//
//    // add SIZE nodes to the list
//    for (i=0; i<SIZE; i++) {
//        printf("Enter a number for node %d: ", i+1);
//        scanf_s("%d", &aNumber);
//
//        //create space for new data element
////        anElement = (struct data *)malloc(sizeof(struct data));
//
//        // create space for new node
//        aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));
//
//        if (aNode == NULL)
//            printf("Error - no space for the new node\n");
//        else { // add data part to the node
//            aNode->next = NULL;
//            aNode->element = anElement;
//
//            //add node to front of the list
//            if (isEmpty())
//            {
//                list = aNode;
//                last = aNode;
//            }
//            else {
//                //aNode is the current node being input, set next to null
//                aNode->next = nullptr;
//                //current last positions next becomes tje node being input
//                last->next = aNode;
//                //the last is now the node being input
//                last = aNode;
//
//            } //end else
//            nodeCount++;
//        }//end else
//    }//end for
//}

// bool duplicate(){
//    int index = 1;
//    struct LinearNode *node;
//    node = list;
//
//    //iterate through the list and check every index after the current index to check all values
//    for (int i = 1;i <= nodeCount-1; i++) {
//        for (int j = i + 1; j <= nodeCount; j++) {
//            // if values are the same set isDuplicated to true and exit loop
//            printf("get(%d) %s with %s at get(%d)\n",i,get(i)->element.id ,get(j)->element.id, j);
//
//            if (get(i)->element.id == get(j)->element.id) {
//                return true;
//            }
//        }
//    }
//
//    return false;
//}
//struct LinearNode * get(int index){
//
//    if(index > nodeCount) {
//        printf("Index to get is out of range");
//    } else {
//        if (list != nullptr) {
//            NODE *node;
//            node = list;
//            for (int i = 1; i < index; i++) {
//                node = node->next;
//            }
//            return node;
//        }
//    }
//    return NULL;
//}

//void viewAllNodes() {
//
//    struct LinearNode *current;
//
//    if (isEmpty())
//        printf("Error - there are no nodes in the list\n");
//    else {
//        current = list;
//        while (current != nullptr) {
//            printf("\n\nNode ID:%s"
//                   "\nNode Title:%s"
//                   "\nNode Author:%s"
//                   "\nNode publicationYear:%d"
//                   "\nNode Available:%d"
//                   "\nNode customerName:%s"
//                   "\nNode loanCount:%d\n"
//                    ,current->element.id
//                    ,current->element.title
//                    ,current->element.author
//                    ,current->element.publicationYear
//                    ,current->element.available
//                    ,current->element.customerName
//                    ,current->element.loanCount);
//
//            current=current->next;
//        } //end while
//    }//end else
//} //end viewAllNodes
//
//void deleteNode(char id[]) {
//    struct LinearNode *current, *previous;
//    bool notFound = true;
//
//    if (isEmpty())
//        printf("Error - there are no nodes in the list\n");
//    else  {
//        current = previous = list;
//
//        while (notFound && current != nullptr) {
//            if (id == current->element.id)
//                notFound = false;
//            else {
//                previous = current;
//                current = current->next;
//            }//end else
//        } //end while
//
//        if (notFound)
//            printf("Error - there is not such node with id: %s\n", id);
//        else  {
//            if (current == list) {
//                list = list->next;
//                free(current);
//            } //end else
//            else {
//                previous ->next= current->next;
//                free(current);
//            } //end else
//            printf("Node with value %s has been deleted\n", id);
//            nodeCount--;
//        }//end else
//
//    }//end else
//}// end deleteNode
//
//void linearSearch(char id[])
//{
//    struct LinearNode *current = list;
//    while (current != NULL && (strcmp(current->element.id,id)!=0)) {
//        current=current->next;
//    }
//
//    if (current == NULL)
//        printf("%s does not exist in the list\n", id);
//    else
//        printf("%s has been found in the list\n", current->element.id);
//}
//
//bool isEmpty() {
//    if (list == nullptr)
//        return true;
//    else
//        return false;
//}

void viewWithID(char * id){
    NODE *node = getByID(id);

    if(node != NULL){
        printf("Inside ViewWithID %s \n", id);

        printf("\n\nNode ID:%s"
               "\nNode Title:%s"
               "\nNode Author:%s"
               "\nNode publicationYear:%d"
               "\nNode Available:%d"
               "\nNode customerName:%s"
               "\nNode loanCount:%d\n"
                ,node->element->id
                ,node->element->title
                ,node->element->author
                ,node->element->publicationYear
                ,node->element->available
                ,node->element->customerName
                ,node->element->loanCount);
    }else{
        printf("There are no books with ID: %s \n", id);
    }

}

struct LinearNode * getByID(char *id){

    NODE *node = list;
    node->next = list->next;
    printf("node: %s next: %s", node->element->id, node->next->element->id);

    while(node->next != NULL){
        if(strcmp(node->element->id, id) == 0){//If the two IDs are the same
            return node;
        }else {
            node = node->next;
        }

    }
    return NULL;
}






