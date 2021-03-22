#ifndef DARREN01_HEADER_H
#define DARREN01_HEADER_H
#include "header.h"
#include "LinkedList.h"
#include "FileHandling.h"
#include "Reports.h"
#endif //DARREN01_HEADER_H

// initialise book count
int bookCount = 0;

void addNode(char [], char[], char[], int, bool, char[], int, int);
void startupProgram();
void addStartNodes();//For debugging
void displayMenu();

void takeBook();            // menu 1
void addBook();             // menu 2
void returnBook();          // menu 3
void deleteBook();          // menu 4
void displayAll();          // menu 5
void viewBook();            // menu 6
void mostLeastPopular();    // menu 7
void personalFunction();    // menu 8
void saveAndExit();         // menu 9

bool isLeftFour( char * );
bool isRightFour( char * );
bool isMidDash( const char * );

void inputID(char *);
void printError();

// Global LinkedList variables
//NODE * list;
//NODE * last;

/**************MAIN FUNCTION*******************/
int main() {
    // load books

    startupProgram();

    //displayBooksLinkedList(); /** Debug only **/

    displayMenu(); // show Menu

}

/**
 * The three functions are used to validate the ID field
 * isLeft() checks the first 4 are numbers
 * isRight() checks the last 4 are numbers
 * isMidDash() check the middle char is a dash character '-'
 * @return
 */
bool isLeftFour( char * in) {
    bool valid = true;
    for (int i=0;i<4;i++)
        if(!isdigit(in[i]))
            valid = false;

    return valid;
}
bool isRightFour( char * in) {
    bool valid = true;
    for (int i=5;i<9;i++)
        if(!isdigit(in[i]))
            valid = false;

    return valid;
}
bool isMidDash(const char * in) {
    return (in[4]=='-') ? true : false;
}

/**
 * Input Book ID
 * @param input
 */
void inputID(char * input){

    bool valid = false;
    bool left, right, mid = false;

    while (!valid) {
        printf("Enter a formatted String XXXX-XXXX : ");
        scanf_s("%s", input, 10);
        if(strlen(input) >=9) {
            left = isLeftFour(input);
            right = isRightFour(input);
            mid = isMidDash(input);

            valid = left && right && mid;
        }
    }
}

/**
 * Add Book to library
 */
 void addBook() { // menu opt 2
    //Create Book
    BOOK newBook;
    BOOK *aBook = &newBook;

    char input[10];
    char *in = input;

    inputID(in);

    while(!idNotInList(in)){
       printf("\n\nThis ID already exists in Library\n\n");
       inputID(in);
    }

    strcpy_s(aBook->id, 10, in);

    printf("\nInput the title of the book: ");
    scanf_s("%s", aBook->title, 50);

    printf("\nInput the Author of the book: ");
    scanf_s("%s", aBook->author,30);

    printf("\nInput the Publication Year of the book: ");
    scanf_s("%d", &aBook->publicationYear);

    while(aBook->publicationYear <= 2008) {
        printf("\nPublication Year must be greater than 2008, please input again: ");
        scanf_s("%d", &aBook->publicationYear);
    }

    strcpy_s(aBook->customerName, 30, "");

    printf("\nInput Cost of Book: \n");
    scanf_s("%d", &aBook->cost);

    aBook->available = true;
    aBook->loanCount = 0;

    if(bookCount == 0){
        addNewList(aBook); // Adds book into first position in linkedlist
    }else {
        addToEnd(aBook);
    }
    bookCount++;

}

void startupProgram() {
//  initialise nodes

    //addStartNodes(); // add 20 nodes
   // saveToFileLinkedList(bookCount); // in FileHandling.c
    //getFileData();
    getFromFileLinkedList( );// in FileHandling.c
}

/**
 * Display Menu System
 */
void displayMenu(){
    int input = 0;
    //Print Menu
    while(input != 9) {
        printf("1. Add Book\n"
               "2. Take a Book\n"
               "3. Return a Book\n"
               "4. Delete a Book\n"
               "5. View all books\n"
               "6. View a specific book\n"
               "7. View Most popular and least popular\n"
               "8. Library Book Report\n"
               "9. Exit Library\n\n"
               "Please Enter Your Option");
        scanf_s("%d", &input);

        switch(input){
            case 1:
                addBook();
                break;
            case 2:
                takeBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                displayAll();
                break;
            case 6:
                viewBook();
                break;
            case 7:
                mostLeastPopular();
                break;
            case 8: // Personal Function
                personalFunction();
                break;
            case 9:
                saveAndExit();
                break;
            default:
                printError();
                break;
        }
    }
}

void printError() {
    printf("\nError: Number out of range, please input a number from 1-9\n\n");
}

/**
 * Take book out on loan
 */
 void takeBook() { // menu opt 1
    //find book matching input
    char input[10];
    char *in = input;

    printf("Enter the ID of the book you wish to borrow: \n");


    bool bookBorrowed = false;
    NODE * node;
    while(!bookBorrowed) {
        inputID(in);
        while(idNotInList(in)) {
            printf("Book ID not found - Please Re-Enter: \n\n");
            inputID(in);
        }

        node = getByID(in); // in LinkedList
        if(!node->element->available) {
            printf("Book is unavailable - Please Try another Book\n\n");
        } else {
            // Book available and ID exists
            node->element->available = false;
            //increment loan count
            node->element->loanCount ++;
            //update customerName assigned to book
            printf("Input your name: \n");
            scanf_s("%s", node->element->customerName, 30);
            bookBorrowed = true;
        }

    }


}

/**
 * Return book to Library
 */
 void returnBook() {// menu opt 3
    // return by ID

    char input[10];
    char *in = input;

    char firstName[30];
    char *name = firstName;

    printf("Enter your name, which is registered to the book");
    scanf_s("%s", name, 30);
    printf("Enter the ID of the book you wish to return: \n");


    bool bookBorrowed = true;
    NODE * node;
    while(bookBorrowed) {
        inputID(in);
        while(idNotInList(in)) {
            printf("\n\nBook ID not found - Please Re-Enter \n\n");
            inputID(in);
        }

        node = getByID(in); // in LinkedList
        if(node->element->available) {
            printf("\n\nBook is currently not on loan - Please Re-Enter\n\n");
        } else {
            if(strcmp(node->element->customerName, name) == 0) {
                printf("\n\nThank you for returning the book\n\n");
                // Book availability back to true
                node->element->available = true;
                //update customerName assigned to book back to empty
                strcpy_s(node->element->customerName, 30, "");
                bookBorrowed = false;
            }else{
                printf("\nCustomer Name does not match customer who borrowed this book\n\n");
                break; // if name does not match borrowers name, return to menu
            }
        }

    }

}

/**
 * Delete book from library
 */
 void deleteBook() { // menu opt 4
//     delete by ID
    char input[10];
    char *in = input;
    inputID(in);

    if (getByID(in)->element->publicationYear < 2011) {
        deleteWithID(in); // in LinkedList
    }else{
        printf("\n\nThis book cannot be deleted as it is less than 10 years old\n");
    }
}

/**
 * Display All books in library
 */
 void displayAll() { // menu opt 5
    displayBooksLinkedList(); // in Reports.c
}

/**
 * View a single book detaILS IN LIBRARY
 */
 void viewBook() { // menu opt 6
     // By ID
     char input[10];
     char * in = input;

     inputID(in);
     viewWithID(in); // in LinkedList

}

/**
 * Report the Most popular and Least popular book based on borrowings
 */
 void mostLeastPopular() { // menu opt 7 - all in Reports.c
    reportHeader(); // Header block two lines above and below text
    viewPopular(); // single line of report output
    viewUnpopular(); // single line of report output
    reportEnding(); // line of '='
}

/**
 * Create a report of all the activities in the library
 */
 void personalFunction() { // menu opt 8 - all in Reports.c
    reportHeader(); // Header block two lines above and below text
    reportCostOfBooksSummary(); // 3 lines of report data
    reportEnding(); // line of '='
}

/**
 * Save books to file and exit
 */
void saveAndExit() { // menu opt 9 or default
    saveToFileLinkedList(list); // in LinkedList.c
    exit(0);
}

/**
 *
 */
//For debugging
void addStartNodes() {

    //addNode( "1234-0001","Harry Potter and the Philosopher's Stone ","J.K. Rowling",2001,0,"John",20,15);
    addNode( "1234-0002","Diary of a Wimpy Kid: Old School","Jeff Kinney",2015,0,"Fred",30,10);
    // addNode( "1234-0003","The BFG","Roald Dahl",1982,0,"Mary",40,10);
    //addNode( "1234-0004","Harry Potter and the Chamber of Secrets","J.K. Rowling",2002,1,"",40,15);
    //addNode( "1234-0005","Harry Potter and the prisoner of Azkaban","J.K. Rowling",2004,1,"",20,15);
    addNode( "1234-0006","Diary of a Wimpy Kid: Double Down","Jeff Kinney",2015,1,"",35,10);
    addNode( "1234-0007","Awful Auntie","David Walliams",2014,1,"",20,10);
    addNode( "1234-0008","Diary of a Wimpy Kid: Hard Luck","Jeff Kinney",2015,1,"",35,10);
    addNode( "1234-0009","Wonder","R.J. Palacio",2012,1,"",20,15);
    //addNode( "1234-0010","James and the Giant Peach","Roald Dahl",1996,1,"",40,15);
    addNode( "1234-0011","Ratburger","David Walliams",2012,0,"Joan",20,10);
    //addNode( "1234-0012","Matilda","Roald Dahl",1996,0,"Oisin",15,10);
    addNode( "1234-0013","The World's Worst Children","David Walliams",2016,0,"Darren",10,15);
    addNode( "1234-0014","Gangsta Granny","David Walliams",2011,0,"Marion",10,15);
    //addNode( "1234-0015","Fantastic Mr Fox","Roald Dahl",1970,1,"",35,10);
    addNode( "1234-0016","Demon Dentist","David Walliams",2013,1,"",5,10);
    addNode( "1234-0017","Diary of a Wimpy Kid: The Third Wheel","Jeff Kinney",2015,1,"",25,10);
    addNode( "1234-0018","Grandpa's Great Escape","David Walliams",2015,0,"Auveen",25,15);
    addNode( "1234-0019","Diary of a Wimpy Kid: Cabin Fever","Jeff Kinney",2015,0,"Eileen",35,20);
    addNode( "1234-0020","Under the Hawthorn Tree","Marita Conlon-McKenna",2015,0,"Liam",5,10);
}

void addNode( char id[], char title[], char author[], int year, bool available, char borrower[], int loanCount, int cost) {

    // create aBook object the n add to LinkedList
    BOOK * aBook  = malloc(sizeof(BOOK));

    strcpy_s(aBook->id, 10 ,id );
    strcpy_s(aBook->title, 50, title);
    strcpy_s(aBook->author, 30, author);
    strcpy_s(aBook->customerName, 30, borrower);

    aBook->available = available;
    aBook->loanCount = loanCount;
    aBook->cost = cost;
    aBook->publicationYear = year;

    if (bookCount == 0) {
        addNewList(aBook); // in LinkedList.c
        bookCount = 1;
    } else {
        addToEnd(aBook); // in LinkedList.c
        bookCount++;
    }

}

