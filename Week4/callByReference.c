#include <stdio.h>

/* Function Prototypes */
int square(int *);
void endMessage(); 

//Global Variable
char message[]= "End of program";

int main()
{
	//local variable
    int i = 5;
   printf("square of %d is %d\n",i, square(&i)); 
   printf("After calling square function, i is %d\n", i); 
  endMessage();
}

int square (int *i) //parameter
{
   return ((*i) * (*i));
}

void endMessage()
{
   printf("%s \n", message);
}

