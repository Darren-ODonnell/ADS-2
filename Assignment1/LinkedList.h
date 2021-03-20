//
// Created by Darren on 12/03/2021.
//

#ifndef DARREN01_LINKEDLIST_H
#define DARREN01_LINKEDLIST_H

#endif //DARREN01_LINKEDLIST_H

void addNodes();  //adding nodes to front of the list
void deleteNode(char[]); // delete a specific node
void viewAllNodes();
bool isEmpty();
void linearSearch(char[]);


void addNewList(BOOK * );
void addToEnd(BOOK * );


//Methods that i added
void addNodesToEnd();
bool duplicate();
NODE * get(int, int);
NODE * getByID(char *);
void viewWithID(char *);
void deleteWithID(char *, int *);
void viewBookInNode(NODE *);
void viewBookContents(BOOK *);
void bookCopy(struct data *, struct data *);