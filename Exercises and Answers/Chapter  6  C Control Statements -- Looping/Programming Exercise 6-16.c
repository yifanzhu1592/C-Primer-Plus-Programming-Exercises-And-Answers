/* Programming Exercise 6-16 */

// Daphne invests $100 at 10% simple interest. (That is, every year, the investment earns
// an interest equal to 10% of the original investment.) Deridre invests $100 at 5% interest
// compounded annually. (That is, interest is 5% of the current balance, including previous
// addition of interest.) Write a program that finds how many years it takes for the value
// of Deirdre's investment to exceed the value of Daphne's investment. Also show the two
// values at that time.


#include <stdio.h>

int main(void)
{
	const float rate_Daphne = 10.0/100;
	const float rate_Deridre = 5.0/100;
	const int original_investment = 100;
	int years = 0;
	float value_Daphne = original_investment;  // the value of Daphne's investment
	float value_Deridre = original_investment; // the value of Deridre's investment
	
	while (value_Daphne >= value_Deridre)
	{
		value_Daphne += original_investment * rate_Daphne;
		value_Deridre += value_Deridre * rate_Deridre;
		years++;
	}
	
	printf("It takes %d years for the value of Deridre's investment to exceed\nthe value of Daphne's investment.\n", years);
	printf("At that time, the value of Daphne's investment is %f,\nand the value of Deridre's investment is %f.\n", value_Daphne, value_Deridre);
	
	return 0;
}
