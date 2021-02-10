#include <stdio.h>
#include <string.h>
#define SIZE 5

int main()
{
    char strings[SIZE][70];
    int index, indexOfLongest;
    int longestLength = 0;
    char pause;

    for (index=0; index < SIZE; index ++) {
        printf("Enter string %d: ", index+1);
        gets(strings[index]);
     } //end for

for (index = 0; index < SIZE; index++) {
    if (strlen(strings[index]) > longestLength) {
       longestLength = strlen(strings[index]);
       indexOfLongest = index;
     } //end if
}//end for

printf("The longest string is %s with %d characters\n",
            strings[indexOfLongest], longestLength);

printf("Alphabetically Smallest: %s", strings)
}
