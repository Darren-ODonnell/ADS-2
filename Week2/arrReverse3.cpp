/*program to read in a list of numbers and to write them out in reverse order*/
	#include <stdio.h>
    #define MAX 4	  /* size of array	*/
   
   int main()  
   {
       int table[MAX];	  /* declare array    */
       int num;		  /* to hold input    */ 
       int i,index=0;	 /* index for the array */
        int signal;	 /* return code for scanf*/
	   
        printf("Enter an integer : ");
	    signal=scanf("%d",&num);	/* read first input */

      while (index < MAX) // signalled by a Control-Z
      {  
	     if (signal != 1) 		/* invalid input */
	     {
	       	printf("Invalid input after %d values\n",index);  getchar();  
            break;  //end if
          }
     	 else if (index>MAX-1) {     /* array full */
	    	 printf("No more room after %d values\n",index); getchar();
             break; 
         } //end else if    
        else      /* valid entry */			
            table[index++] = num;
	    
	    printf("Enter an integer : ");
	    signal=scanf("%d",&num);	 /* read next input */
    } //end while
    
    
  /* write out numbers in reverse */
	for (i=index-1; i>=0; i--)
       printf("%d\n",table[i]);
 
      getchar();
   
     
} //end program

   
