/**************************************************************/
/*                                                            */
/*   Program to demonstrate the implmentation of a simple     */
/*   linked list of numbers with a delete function.								  */
/*                                                            */
/**************************************************************/

#define bool int
#define false 0
#define true (!false)

//Libraries
#include <stdio.h>
#include <stdlib.h>

//Preprocessor Variable
#define SIZE 3
#define nullptr NULL

//Stucture template for data part of the linked list
 struct data {
 	int num;
 };

//Stucture template for one node
struct LinearNode {
     struct data *element;
	struct LinearNode *next;
};


// Function prototypes
void addNodes();  //adding nodes to front of the list
void deleteNode(int); // delete a specific node
void viewAllNodes();
bool isEmpty();

//Methods that i added
void addNodesToEnd();
bool duplicate();
struct LinearNode* get(int);



// Global Variables
int nodeCount = 0; // keep track of how many nodes in list

struct LinearNode *list = nullptr; //front of list

struct LinearNode *last = nullptr; //pointer to last node in list



/**************MAIN FUNCTION*******************/
int main() {
	int delNum=0;
    char delay;

	addNodesToEnd();
	viewAllNodes();
	printf("Please enter the number of the node to delete : ");
    scanf("%d",&delNum);
    deleteNode(delNum);

	struct LinearNode * res = get(2);
	printf("Number got with get = %d\n", res->element->num);

	printf("Duplicate: %s\n", duplicate() ? "True" : "False");
   // viewAllNodes();

}

/**********ADD THREE NODES TO THE LIST******************/
// Each new node is added to the front of the list
void addNodesToEnd(){
    int i;
    int aNumber;
    struct LinearNode *aNode;
    struct data *anElement;

    // add SIZE nodes to the list
    for (i=0; i<SIZE; i++) {
        printf("Enter a number for node %d: ", i+1);
        scanf("%d", &aNumber);

        //create space for new data element
        anElement = (struct data *)malloc(sizeof(struct data));

        // create space for new node
        aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));

        //add aNumber to data node
        anElement->num = aNumber;

        if (aNode == NULL)
            printf("Error - no space for the new node\n");
        else { // add data part to the node
            aNode->next = NULL;
            aNode->element = anElement;

            //add node to front of the list
            if (isEmpty())
            {
                list = aNode;
                last = aNode;
            }
            else {
                //aNode is the current node being input, set next to null
                aNode->next = nullptr;
                //current last positions next becomes tje node being input
                last->next = aNode;
                //the last is now the node being input
                last = aNode;

            } //end else
            nodeCount++;
        }//end else
    }//end for
}

bool duplicate(){
    int index = 1;
    struct LinearNode *node;
    node = list;


    //iterate through the list and check every index after the current index to check all values
    for (int i = 1;i <= nodeCount-1; i++) {
        for (int j = i + 1; j <= nodeCount; j++) {
            // if values are the same set isDuplicated to true and exit loop
            printf("get(%d) %d with %d at get(%d)\n",i,get(i)->element->num ,get(j)->element->num, j);

            if (get(i)->element->num == get(j)->element->num) {
                return true;
            }
        }
    }

    return false;
}
struct LinearNode * get(int index){

    if(index > nodeCount) {
        printf("Index to get is out of range");
    } else {
        if (list != nullptr) {
            struct LinearNode *node;
            node = list;
            for (int i = 1; i < index; i++) {
                node = node->next;
            }
            return node;
        }
    }
}

void addNodes() {
	int aNumber;
	struct LinearNode *aNode;
	struct data *anElement;

	// add SIZE nodes to the list
	for (int i=0; i<SIZE; i++) {
		printf("Enter a number for node %d: ", i+1);
		scanf("%d", &aNumber);

         //create space for new data element
         anElement = (struct data *)malloc(sizeof(struct data));

		// create space for new node
		aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));

         //add aNumber to data node
         anElement->num = aNumber;

		if (aNode == nullptr)
			printf("Error - no space for the new node\n");
		else { // add data part to the node
		 	aNode->next = nullptr;
		 	aNode->element = anElement;

			//add node to front of the list
			if (isEmpty())
			{
				list = aNode;
				last = aNode;
		    }
			else {
				aNode->next = list;
				list = aNode;
			} //end else
			nodeCount++;
		}//end else
	}//end for
} //end addNodes

void viewAllNodes() {
	struct LinearNode *current;

	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
			current = list;
			while (current != nullptr) {
				printf("Node value is %d\n", current->element->num);
				current=current->next;
			} //end while
    }//end else
} //end viewAllNodes

void deleteNode(int aNumber) {
	struct LinearNode *current, *previous;
	bool notFound = true;



	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else  {
			current = previous = list;

			while (notFound && current != nullptr) {
				if (aNumber == current->element->num)
					notFound = false;
				else {
						previous = current;
						current = current->next;
				}//end else
			} //end while

			if (notFound)
				printf("Error - there is not such node with value %d\n", aNumber);
			else  {
				if (current == list) {
					list = list->next;
					free(current);
				} //end else
				else {
						previous ->next= current->next;
						free(current);
				} //end else
				printf("Node with value %d has been deleted\n", aNumber);
                nodeCount--;
			}//end else

		}//end else
}// end deleteNode


bool isEmpty() {
	if (list == nullptr)
		return true;
	else
		return false;
}
