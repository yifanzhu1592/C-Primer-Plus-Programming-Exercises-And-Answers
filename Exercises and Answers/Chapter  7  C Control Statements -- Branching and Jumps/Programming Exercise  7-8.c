/* Programming Exercise 7-8 */

// Modify assumption a. in exercise 7 so that the program presents a menu of pay rates
// from which to choose. Use a switch to select the pay rate. The beginning of a run
// should look something like this:

// *****************************************************************
// Enter the number corresponding to the desired pay rate or action:
// 1) $8.75/hr                         2) $9.33/hr
// 3) $10.00/hr                        4) $11.20/hr
// 5) quit
// *****************************************************************

// If choices 1 through 4 are selected, the program should request the hours worked. The
// program should recycle until 5 is entered. If something other than choices 1 through 5
// is entered, the program should remind the user what the proper choices are and then
// recycle. Use #defined constants for the various earning rates and tax rates.


#include <stdio.h>
#define basic_time 40
#define overtime 1.5
#define rate_tier_1 300
#define rate_tier_2 150
#define tax_rate_1 0.15
#define tax_rate_2 0.2
#define tax_rate_3 0.25

int main(void)
{
	float hours, time;
	float basic_pay_rate;
	float gross_pay, taxes, net_pay;
	char choice;
	
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $8.75/hr                         2) $9.33/hr\n");
	printf("3) $10.00/hr                        4) $11.20/hr\n");
	printf("5) quit\n");
	printf("*****************************************************************\n");
	
	a:
	while ((choice = getchar()) == '\n') // in case that the user starts out by pressing "Enter"
		continue;
	while (getchar() != '\n') // skip the newline character
		continue;
	
	switch (choice)
	{
		case '1': basic_pay_rate = 8.75;
		          break;
		
		case '2': basic_pay_rate = 9.33;
		          break;
		          
		case '3': basic_pay_rate = 10.00;
		          break;
		
		case '4': basic_pay_rate = 11.20;
		          break;
		          
		case '5': printf("See you next time!\n");
		          return 0;
		
		default : printf("Please enter 1~5 to choose a pay rate or action:\n");
		          goto a;
	}
	
	printf("How many hours your work in a week?\n");
	scanf("%f", &hours);
	
	if (hours > basic_time)
		time = hours * overtime;
	else
		time = hours;
	
	gross_pay = time * basic_pay_rate;
	
	if (gross_pay < rate_tier_1)
		taxes = gross_pay * tax_rate_1;
	else if (gross_pay < rate_tier_1 + rate_tier_2)
		taxes = rate_tier_1 * tax_rate_1 + (gross_pay - rate_tier_1) * tax_rate_2;
	else
		taxes = rate_tier_1 * tax_rate_1 + rate_tier_2 * tax_rate_2 + (gross_pay - rate_tier_1 - rate_tier_2) * tax_rate_3;
	
	net_pay = gross_pay - taxes;
	
	printf("Your gross pay is $%g, your taxes is $%g, your net pay is $%g.\n", gross_pay, taxes, net_pay);
	
	return 0;
}
