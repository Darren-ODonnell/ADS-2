#include <stdio.h>
#define bool int
#define false 0
#define true (!false)

int main()
{
    char delay;
	float accountbalance, servicecharge, total;
	servicecharge = 0;
	bool closed = false;  
	
	printf("Enter an account balance:");
	scanf("%f",&accountbalance);
	
	if (accountbalance < 0) 
    {	
       servicecharge = 5.00; 
       if (accountbalance < -1000)
       {
          printf("Your account will now be closed until debt is cleared");
          closed = true;
       }//end nested if
     }//end if
     
	total = accountbalance - servicecharge;
	
	if (!closed)
       printf("Account balance = %5.2f, Service Charge = %5.2f, total = %5.2f\n",
			accountbalance, servicecharge, total);

   getchar();
   getchar();
}
