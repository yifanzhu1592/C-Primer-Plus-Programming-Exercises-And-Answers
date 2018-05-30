/* Programming Exercise 6-17 */

// Chuckie Lucky won a million dollars (after taxes), which he places in an account that
// earns 8% a year. On the last day of each year, Chuckie withdraws $100,000. Write a
// program that finds out how many years it takes for Chuckie to empty his account.


#include <stdio.h>
#define rate 0.08       // interest rate
#define initial 1000000 // initial funds
#define withdraw 100000 // money withdrew every year

int main(void)
{
	int years = 0;
	float money = initial;
	
	while (money > 0)
	{
		money += money * rate;
		money -= withdraw;
		years++;
	}
	
	printf("It takes %d years for Chuckie to empty his account.\n", years);
	
	return 0;
}
