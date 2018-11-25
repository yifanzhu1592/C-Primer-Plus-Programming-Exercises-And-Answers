/* Programming Exercise 5-8 */

// Write a program that displays the results of applying the modulus operation. The user
// should first enter an integer to be used as the second operand, which will then remain
// unchanged. Then the user enters the numbers for which the modulus will be computed,
// terminating the process by entering 0 or less. A sample run should look like this:

// This program computes moduli.
// Enter an integer to serve as the second operand: 256
// Now enter the first operand: 438
// 438 % 256 is 182
// Enter next number for first operand (<=0 to quit): 1234567
// 1234567 % 256 is 135
// Enter next number for first operand (<=0 to quit): 0
// Done


#include <stdio.h>

int main(void)
{
	int second_operand, first_operand;
	
	printf("Enter an integer to serve as the second operand: ");
	scanf("%d", &second_operand);
	printf("Now enter the first operand: ");
	scanf("%d", &first_operand);
	while (first_operand > 0)
	{
		printf("%d %% %d is %d\n", first_operand, second_operand, first_operand % second_operand);
		printf("Enter next number for first operand (<=0 to quit): ");
		scanf("%d", &first_operand);
	}
	printf("Done!\n");
	
	return 0;
}
