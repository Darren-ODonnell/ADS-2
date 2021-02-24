// load any .h files here
#include <stdio.h>
#include "cfiles.h"

// load any other .c programs required here


void swapNumbersQuestion();

int main() {
    //swapNumbersQuestion();

    char email[MAX_EMAIL];
    char password[MAX_PASSWORD];
    printf("Input an email address: ");
    scanf("%s",email);

    generatePassword((char **) &password, (char **) &email);

    printf("Email: %s", email);
    return 0;
}

void swapNumbersQuestion(){
    int num1 = inputNumber();
    int num2 = inputNumber();

    swapNumbers(&num1, &num2);

    printf("%d %d", num1, num2);
}
