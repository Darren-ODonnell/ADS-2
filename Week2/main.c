#include <stdio.h>
#define MAX 4	  /* size of array	*/

void fibonacci();
void switchEx();
void countEven();
void number3();
void string();

int main() {
//number3();
//fibonacci();
//switchEx();
//countEven();
string();
    return 0;
}
void string(){
    char str[20];
    char chr;
    int i =0;

    printf("Input into the array, use full stop to end input");
    do {
        scanf("%c", &chr);
        str[i] = chr;
        i++;
    }while(chr != '.' && i < 20);
    printf("%s", str);
}

void number3()
{
    int table[MAX];	  /* declare array    */
    int num;		  /* to hold input    */
    int i,index=0;	 /* index for the array */
    int signal;	 /* return code for scanf*/

    printf("Enter an integer : ");
    signal=scanf("%d",&num);	/* read first input */

    while (index < MAX) // signalled by a Control-Z
    {
        if (signal != 1) 		/* invalid input */
        {
            printf("Invalid input after %d values\n",index);  getchar();
            break;  //end if
        }
        else if (index>MAX-1) {     /* array full */
            printf("No more room after %d values\n",index); getchar();
            break;
        } //end else if
        else      /* valid entry */
            table[index++] = num;

        printf("Enter an integer : ");
        signal=scanf("%d",&num);	 /* read next input */
    } //end while


    /* write out numbers in reverse */
    for (i=index-1; i>=0; i--)
        printf("%d\n",table[i]);

    getchar();


} //end program

void countEven()
{
    char delay;
    int table[MAX];	  /* declare array    */
    int i, index=0;	 /* index for the array */


    do
    {
        printf("Enter an integer : ");
        scanf("%d",&table[index++]);
    }while (index < MAX);



    /* write out numbers in reverse */
    for (i=index-1; i>=0; i--)
        printf("%d\n",table[i]);

    //Write out all even numbers
    for(int x = 0; x < MAX; x++){
        if( table[x] % 2 == 0){
            printf(" %d ", table[x]);
        }
    }

} //end program

void fibonacci(){
    int x;
    int total = 0;
    int one = 0, two = 1, three;

    printf("Input a number for fibonacci series");
    scanf("%d", &x);

    printf("%d  %d ", one, two);
    for(int i = 0; i < x; i++){

        three = one + two;
        printf(" %d ", three);
        one = two;
        two = three;
    }

}

void switchEx(){
    int month;
    int year;
    printf("Input a number for month 1-12");
    scanf("%d", &month);

    printf("Input the year");
    scanf("%d", &year);

    int days =0;

    switch(month){
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                days = 29;
            }else{
                days = 28;
            }
            break;
        default:
            days = 31;
            break;
    }

    printf("%d Days in Month %d", days, month);

}
