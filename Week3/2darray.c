#include <stdio.h>
#define EXAMS 3
#define STUDENTS 4

int main()
{
	int exams[STUDENTS][EXAMS];
	    
    //input the results	
	for (int i = 0; i < STUDENTS; i++)
	{
        printf("Input the %d results for student %d \n", EXAMS, (i+1)); 
		for (int j=0;j<EXAMS;j++)
			scanf("%d", &exams[i][j]);
	}
	
	printf("\n\n");
	
	//display the results	
	for (int i = 0; i < STUDENTS; i++)
	{
        printf("The %d results for student %d are...\n", EXAMS, (i+1)); 
		for (int j=0;j<EXAMS;j++)
			printf("%d%% ", exams[i][j]);
		printf("\n");
	}
	
}
