//
// Created by Darren on 12/03/2021.
//

#ifndef DARREN01_LINKEDLIST_H
#define DARREN01_LINKEDLIST_H
#endif //DARREN01_LINKEDLIST_H

void addNewList(BOOK * );
void addToEnd(BOOK * );
NODE * get(int);
NODE * getByID(char *);
void viewWithID(char *);
void deleteWithID(char *);
void viewBookInNode(NODE *);
void viewBookContents(BOOK *);
void bookCopy(struct data *, struct data *);
bool idNotInList(char *);