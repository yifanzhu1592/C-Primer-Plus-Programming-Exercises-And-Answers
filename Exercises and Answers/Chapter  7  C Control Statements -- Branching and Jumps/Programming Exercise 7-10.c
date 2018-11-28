/* Programming Exercise 7-10 */

// The 1998 United States Federal Tax Schedule was the simplest in recent times. It had
// four categories, and each category had two rates. Here is a summary (dollar amounts are
// taxable income):

// Category                           Tax
// Single                             15% of first $17,850 plus 28% of excess
// Head of Household                  15% of first $23,900 plus 28% of excess
// Married, Joint                     15% of first $29,750 plus 28% of excess
// Married, Separate                  15% of first $14,875 plus 28% of excess

// For example, a single wage earner with a taxable income of $20,000 owes 0.15 x $17,850
// + 0.28 x ($20,000-$17,850). Write a program that lets the user specify the tax category
// and the taxable income and that then calculates the tax. Use a loop so that the user can
// enter several tax cases.


#include <stdio.h>
#define rate1 0.15
#define rate2 0.28

int main(void)
{
	char choice;
	int rate_tier;
	float income, tax;
	int flag;      // use this to decide to continue another turn or not
	
	do
	{
		printf("You are (enter 1~4 to choose your situation):\n");
		printf("1. Single\n");
		printf("2. Head of Household\n");
		printf("3. Married, Joint\n");
		printf("4. Married, Separate\n");
	
		choice = getchar();
		while (getchar() != '\n')
			continue;
		while (choice < '1' || choice > '4')
		{
			printf("Please enter 1~4 to choose:\n");
			choice = getchar();
			while (getchar() != '\n')
				continue;
		}
		switch (choice)
		{
			case '1' : rate_tier = 17850;
			           break;
		
			case '2' : rate_tier = 23900;
		               break;
		           
			case '3' : rate_tier = 29750;
		               break;
		           
			case '4' : rate_tier = 14875;
		               break;
		           
			default  : break;
		}
	
		printf("The please enter your taxable income:\n");
		while (scanf("%f", &income) != 1)
		{
			printf("Please enter a number:\n");
			while (getchar() != '\n')
				continue;
		}
		while (getchar() != '\n')
			continue;
	
		if (income < rate_tier)
			tax = income * rate1;
		else
			tax = rate_tier * rate1 + (income - rate_tier) * rate2;
	
		printf("The tax you need to pay is $%g.\n", tax);
	
		printf("Another turn? (Enter 'y' to continue, enter other characters to exit):\n");
		flag = 0;
		if (getchar() == 'y')
			flag = 1;
		while (getchar() != '\n')
			continue;
		printf("\n");
	} while (flag == 1);
	
	printf("See you next time!\n");
	
	return 0;
}
