#include <stdio.h>

//Global Structure - note this does NOT declare a structuee
struct point {
       int x;
       int y;
}; 

int main ()
{
    struct point p1, p2;
    
    printf("Enter first point's x value: ");
    scanf("%d", &p1.x);
    
    printf("Enter first point's y value: ");
    scanf("%d", &p1.y);
    
    printf("\nThe first point's values are : %d and %d\n", p1.x, p1.y);
    p2 = p1;
    printf("The seconds point's values are : %d and %d\n", p2.x, p2.y);
    
    p1.x=99;
    
    printf("\nAfter updating p1.x, the first point's values are : %d and %d\n", p1.x, p1.y);
    printf("After updating p1.x, the second point's values are : %d and %d\n", p2.x, p2.y);
    
  
  
}
    
       
