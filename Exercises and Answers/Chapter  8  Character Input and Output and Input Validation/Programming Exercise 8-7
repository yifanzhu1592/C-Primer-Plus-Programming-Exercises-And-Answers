/* Programming Exercise 8-7 */

// Modify Programming Exercise 8 from Chapter 7 so that the menu choices are labeled by
// characters instead of by numbers; use q instead of 5 as the cut to terminate input.


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
	printf("a) $8.75/hr                         b) $9.33/hr\n");
	printf("c) $10.00/hr                        d) $11.20/hr\n");
	printf("q) quit\n");
	printf("*****************************************************************\n");
	
	while ((choice = getchar()) != EOF)
	{
		while (getchar() != '\n')
			continue;
		switch (choice)
		{
			case 'a': basic_pay_rate = 8.75;
			          break;
		
			case 'b': basic_pay_rate = 9.33;
		              break;
		          
			case 'c': basic_pay_rate = 10.00;
		              break;
		
			case 'd': basic_pay_rate = 11.20;
		              break;
		    
		    case 'q': printf("See you next time!\n");
		              return 0;
		
			default : printf("Please enter a~d to choose a pay rate, q to quit:\n");
			          continue;
		}
		break;
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
