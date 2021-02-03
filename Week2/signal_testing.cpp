/* Program to validate an integer */
	#include <stdio.h>
    #define MAX 4	  /* size of array	*/
    #define bool int
    #define false 0
    #define true !false
   
   int main()  
   {
		int num;		  /* to hold input    */ 
        int c;
        int signal;	 /* return code for scanf*/
	   
	    bool valid = true;
	    
	    do
	    {
	        valid = true;
	      	printf("Enter an integer : ");
	    	signal=scanf("%d",&num);	/* read first input */
	    	if (num < 0 || signal == 0)
	    	{
	    		//THIS LOOP WITH NO BODY WILL CLEAR THE SCANNER OF ALL INPUT 
	    		//ESSENTIALLY IT LOOPS THROUGH THE SCANNER EXTRACTING EACH CHARACTER
	    		//UNTIL IT GETS TO A NEWLINE OR AN End Of File MARKER
	    	    while ((c = getchar()) != '\n' && c != EOF) {}
	    	    
	    	   printf("Error - input again\n");
	    	   valid = false;
	    	}
	 	}while(!valid);
	 	
	 	getchar(); getchar();
}
