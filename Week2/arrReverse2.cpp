/*program to read in a list of numbers and to write them out in reverse order*/
	#include <stdio.h>
	#include <stdlib.h>
    #define MAX 4	  /* size of array	*/
   
   int main()  
   {
   
       int table[MAX];	  /* declare array    */
       int i, index=0;	 /* index for the array */
      
      
	   do
	   {
         printf("Enter an integer : ");
         if (scanf("%d",&table[index++]) != 1)
         {
            index--;
            printf("Error in input - please try again\n");
          
           getchar(); getchar(); getchar();//clearing the scanner of any return characters
         }             
       }while (index < MAX);
      
      
    
  /* write out numbers in reverse */
	for (i=index-1; i>=0; i--)
       printf("%d\n",table[i]);
 
    getchar();
    getchar();
   
} //end program

   
