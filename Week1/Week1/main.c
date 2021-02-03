#include <stdio.h>

//typedef struct average average;

void average();
void convertTemperature();
void displayDetails();
void triangle();

void main() {

    //convertTemperature();
    //average();
    //displayDetails();
    triangle();
}

void triangle(){
    int sides[3];


    printf("Input side 1");
    scanf("%d", &sides[0]);
    printf("Input side 2");
    scanf("%d", &sides[1]);
    printf("Input side 3");
    scanf("%d", &sides[2]);



        if(sides[0] == sides[1] == sides[2]){
            printf("Equilateral Triangle");
        }else if(sides[0]==sides[1] || sides[0] == sides[2] || sides[1] == sides[2]){
            printf("Isosceles Triangle");
        }else if(sides[0] != sides[1] != sides[2]){
            printf("Scalene Triangle");
        }
    }


void displayDetails(){
    char initial = 0;
    int age = 0;
    int height = 0;
    printf("Input initial");
    scanf("%c", &initial);
    printf("Input Age");
    scanf("%d", &age);
    printf("Input Height in feet");
    scanf("%d", &height);

    printf("%-12s %-12s %-12s \n","Identifier", "Age", "Height");
    printf("%-12c %-12d %-d %-6s", initial, age, height, "Feet");

}

void convertTemperature(){
    float temp_fahrenheit;
    printf("Hello, World!\n");
    printf("Input temperature in degrees fahrenheit");
    scanf("%f", &temp_fahrenheit);

    float temp_centigrade = (temp_fahrenheit - 32.0) * (5.0/9.0);

    printf("%f Degrees Fahrenheit : %f Degrees Celsius", temp_fahrenheit, temp_centigrade);
    //return 0;


}

void average() {

        float total;
        float average;
        float number;
        int SIZE = 3;
        for (int i = 0; i < SIZE; i++) {

            printf("Input number \n");
            scanf("%f", &number);

            total += number;

        }
        average = total / SIZE;
        printf("Total: %f\n", total);
        printf("Average: %f", average);

}
