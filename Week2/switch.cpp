#include <stdio.h>
int main()
{
 
    char grade = 'F';
    
    switch (grade) 
     { 
           case 'A'  :
                printf("You received 80% - 100%");
                break;
           case 'B' : 
                printf("You received 60% - 79%");
                break;
           case 'C' : 
                printf("You received 50% - 59%");
                break;
           case 'D' : 
                printf("You received 40% - 49%");
                break;
           case 'E' : case 'F' :
                printf("You failed the exam");
                break;
         	default:
             printf("There is no such grade");
     }//end switch


  getchar();
   getchar();
}
