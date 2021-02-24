//
// Created by Darren on 17/02/2021.
//
#include <stdio.h>
void generatePassword( char *password[20], char *email[50]);

void generatePassword(char *password[20], char *email[50]){
    for(int i = 0; i < 10; i++){
        *password[i] = (*email[i]+1);
    }
    printf("Password: %s", *password);
}