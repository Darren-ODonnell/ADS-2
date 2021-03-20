#ifndef DARREN01_HEADER_H
#define DARREN01_HEADER_H
#include "header.h"
#include "LinkedList.h"
#include "FileHandling.h"
#include "Reports.h"
#endif //DARREN01_HEADER_H

int nodeCount = 0; // keep track of how many nodes in list
char bookFile[10];


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#endif

void addNode(char [], char[], char[], int, bool, char[], int, int);
void startupProgram();
void addStartNodes();

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

// Global LinkedList variables
NODE * list;
NODE * last;

int bookCount = 0;

bool isLeftFour( char * );
bool isRightFour( char * );
bool isMidDash( const char * );

void inputID(char *);

/**************MAIN FUNCTION*******************/
int main() {
    // load books and initialise bookCount.

    startupProgram();

    displayMenu(); // show Menu

}

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

void inputID(char * input){

    bool valid = false;
    bool left, right, mid = false;


    while (!valid) {
        printf("Enter a formatted String XXXX-XXXX : ");
        scanf_s("%s", input, 10);

        printf("%s\n", input);

        left = isLeftFour(input);
        right = isRightFour(input);
        mid = isMidDash(input);

        valid = left && right && mid ;

        printf("Status %d %d %d\n",left, right, mid);

    }
}

void addBook() { // menu opt 2
    //Create Book
    BOOK newBook;
    BOOK *aBook = &newBook;

    char input[10];
    char * in = input;
    inputID(in);

    strcpy_s(aBook->id, 10, in);

    printf("Input the title of the book: ");
    scanf_s("%s", aBook->title, 50);

    printf("Input the Author of the book: ");
    scanf_s("%s", aBook->author,30);

    printf("Input the Publication Year of the book: ");
    scanf_s("%d", &aBook->publicationYear);

    printf("Input Your Name: ");
    scanf_s("%s", aBook->customerName,30);

    printf("Input Cost of Book: ");
    scanf_s("%d", &aBook->cost);

    aBook->available = true;

    aBook->loanCount = 0;

    //LIST.addNodeToEnd(aBook);

    //Memory Allocation

    //set last.next = inputBook

    //set last = inputBook

    //increment count

}

void startupProgram() {
//  initialise nodes
    list = last     = (NODE *) malloc(sizeof(NODE));
    list->element   = (BOOK *) malloc(sizeof(BOOK));
    list->next = NULL;

    addStartNodes(); // add 10 nodes
//    saveToFileLinkedList(); // in FileHandling.c
//    bookCount = getFromFileLinkedList(); in FileHandling.c
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
            default :
                saveAndExit();

        }
    }
}

void takeBook() { // menu opt 1
    //find book matching input

    //set book.available = false

    //increment loan count

}

void returnBook() { // menu opt 3
    // return by ID
}

void deleteBook() { // menu opt 4
    // delete by ID
    char input[10];
    char * in = input;
    inputID(in);

    deleteWithID(input);
}

void displayAll() { // menu opt 5
    displayBooksLinkedList(); // in Reports.c
}

void viewBook() { // menu opt 6
     // By ID
     char input[10];
     char * in = input;
     inputID(in);

     viewWithID(input);

}

void mostLeastPopular() { // menu opt 7 - all in Reports.c
    reportHeader(); // Header block two lines above and below text
    viewPopular(); // single line of report output
    viewUnpopular(); // single line of report output
    reportEnding(); // line of '='
}

void personalFunction() { // menu opt 8 - all in Reports.c
    reportHeader(); // Header block two lines above and below text
    reportCostOfBooksSummary(); // 3 lines of report data
    reportEnding(); // line of '='
}

void saveAndExit() { // menu opt 9 or default
//    saveToFileLinkedList(list); // in LinkedList.c
    exit(0);
}

void addStartNodes() {

    addNode( "1234-0001","Harry Potter and the Philosopher's Stone ","J.K. Rowling",2001,1,"John",20,15);
    addNode( "1234-0002","Diary of a Wimpy Kid: Old School","Jeff Kinney",2015,1,"Fred",30,10);
    addNode( "1234-0003","The BFG","Roald Dahl",1982,1,"Mary",40,10);
    addNode( "1234-0004","Harry Potter and the Chamber of Secrets","J.K. Rowling",2002,0,"",40,15);
    addNode( "1234-0005","Harry Potter and the prisoner of Azkaban","J.K. Rowling",2004,0,"",20,15);
    addNode( "1234-0006","Diary of a Wimpy Kid: Double Down","Jeff Kinney",2015,0,"",35,10);
    addNode( "1234-0007","Awful Auntie","David Walliams",2014,0,"",20,10);
    addNode( "1234-0008","Diary of a Wimpy Kid: Hard Luck","Jeff Kinney",2015,0,"",35,10);
    addNode( "1234-0009","Wonder","R.J. Palacio",2012,0,"",20,15);
    addNode( "1234-0010","James and the Giant Peach","Roald Dahl",1996,0,"",40,15);
    addNode( "1234-0011","Ratburger","David Walliams",2012,1,"Joan",20,10);
    addNode( "1234-0012","Matilda","Roald Dahl",1996,1,"Oisin",15,10);
    addNode( "1234-0013","The World's Worst Children","David Walliams",2016,1,"Darren",10,15);
    addNode( "1234-0014","Gangsta Granny","David Walliams",2011,1,"Marion",10,15);
    addNode( "1234-0015","Fantastic Mr Fox","Roald Dahl",1970,0,"",35,10);
    addNode( "1234-0016","Demon Dentist","David Walliams",2013,0,"",5,10);
    addNode( "1234-0017","Diary of a Wimpy Kid: The Third Wheel","Jeff Kinney",2015,0,"",25,10);
    addNode( "1234-0018","Grandpa's Great Escape","David Walliams",2015,1,"Auveen",25,15);
    addNode( "1234-0019","Diary of a Wimpy Kid: Cabin Fever","Jeff Kinney",2015,1,"Eileen",35,20);
    addNode( "1234-0020","Under the Hawthorn Tree","Marita Conlon-McKenna",2015,1,"Liam",5,10);
//
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

