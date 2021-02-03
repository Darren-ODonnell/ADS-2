/*program to read in a list of numbers and to write them out in reverse order*/
	#include <stdio.h>
	
    #define MAX 4	  /* size of array	*/
   
   int main()  
   {
       char delay;
       int table[MAX];	  /* declare array    */
       int i, index=0;	 /* index for the array */
      
      
	   do
	   {
         printf("Enter an integer : ");
         scanf("%d",&table[index++]);          
       }while (index < MAX);
      
      
    
  /* write out numbers in reverse */
	for (i=index-1; i>=0; i--)
       printf("%d\n",table[i]);
 
   
   
} //end program

   
