#include <stdio.h>

void main() {
    float temp_fahrenheit;
    printf("Hello, World!\n");
    printf("Input temperature in degrees fahrenheit");
    scanf("%f", &temp_fahrenheit);

    float temp_centigrade = (temp_fahrenheit - 32.0) * (5.0/9.0);

    printf("%f Degrees Fahrenheit : %f Degrees Celsius", temp_fahrenheit, temp_centigrade);
    //return 0;
}