#include <stdio.h>
//
// Created by Darren on 17/02/2021.
//

//int inputNumber();
//void swapNumbers(int *num1, int *num2);

void swapNumbers(int *num1, int *num2){
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;

};

int inputNumber(){
    int num;
    printf("Input number 1: ");
    scanf("%d", &num);
    return num;
};