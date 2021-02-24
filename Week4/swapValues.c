#include <stdio.h>

void swap(float *, float *);

int main()
{
		float num1, num2;

	printf("Please enter 2 numbers: ");
	scanf("%f%f", &num1, &num2);

	if (num1 > num2)
	  swap(&num1, &num2);
	printf("The numbers in order are %5.1f %5.1f\n", num1, num2);
}

void swap(float *ptr1, float *ptr2)
{
	float temp;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

