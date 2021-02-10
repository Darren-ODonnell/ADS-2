//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#define SIZE 3
//
//void main()
//{
//	int numbers[SIZE];
//	int index;
//
//
///*	1. Input and display array values in the traditional way */
//	printf("\n\nInput and display array values in the traditional way\n");
//	for (index = 0;index <SIZE; index++) {
//		printf("Enter number %d :", index + 1);
//		scanf("%d", &numbers[index]);
//	}
//
//	for (index = 0; index < SIZE; index++)
//		printf("Number %d is %d and its memory address is %u\n",
//		      index + 1, numbers[index], &numbers[index]);
//
//
///*	2. Input and display array values using pointers  */
//	printf("\n\nInput and display array values using pointers\n");
//	for (index = 0;index <SIZE; index++) {
//		printf("Enter number %d :", index + 1);
//		scanf("%d", numbers + index);
//	}
//
//	for (index = 0; index < SIZE; index++)
//		printf("Number %d is %d and its memory address is %u\n",
//		   index + 1, *(numbers + index), numbers + index);
//
//
//}
