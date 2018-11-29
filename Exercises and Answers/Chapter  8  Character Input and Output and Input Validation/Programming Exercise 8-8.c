/* Programming Exercise 8-8 */

// Write a program that shows you a menu offering you the choice of addition, subtraction,
// multiplication, or division. After getting your choice, the program asks for two numbers,
// then performs the requested operations. The program should accept only the offered
// menu choices. It should use type float for the numbers and allow the user to try again
// if he or she fails to enter a number. In the case of division, the program should prompt
// the user to enter a new value if 0 is entered as the value for the second number. A typical
// program run should look like this:

// Enter the operation of your choice:
// a. add           s. subtract
// m. multiply      d. divide
// q. quit
// a
// Enter first number: 22.4
// Enter second number: one
// one is not an number.
// Please enter a number, such as 2.5, -1.78E8, or 3: 1
// 22.4 + 1 = 23.4
// Enter the operation of your choice:
// a. add           s. subtract
// m. multiply      d. divide
// q. quit
// d
// Enter first number: 18.4
// Enter second number: 0
// Enter a number other than 0: 0.2
// 18.4 / 0.2 = 92
// Enter the operation of your choice:
// a. add           s. subtract
// m. multiply      d. divide
// q. quit
// q
// Bye.


#include <stdio.h>

void menu(void);

int main(void)
{
	char choice;
	char input;
	float first_num, second_num; // first number, second number
	float answer;
	
	menu();
	while ((choice = getchar()) != 'q')
	{
		while (getchar() != '\n')
			continue;
		
		if (choice != 'a' && choice != 's' && choice != 'm' && choice != 'd')
		{
			printf("Please enter a or s or m or d: ");
			continue;
		}	
		printf("Enter the first number: ");
		while (scanf("%g", &first_num) != 1)
		{
			while ((input = getchar()) != '\n')
				putchar(input);
			printf(" is not an number.\n");
			printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
		}
		
		printf("Enter the second number: ");
		while (scanf("%g", &second_num) != 1 || (second_num == 0 && choice == 'd'))
		{
			if (second_num != 0) // if "scanf("%g", &second_num) != 1"
			{
				while ((input = getchar()) != '\n')
					putchar(input);
				printf(" is not an number.\n");
				printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
			}
			else // if "second_num == 0 && choice == 'd' "
			{
				while (getchar() != '\n')
					continue;
				printf("Enter a number other than 0: ");
				second_num = -1; // so that "second_num != 0" again
			}
		}
		while (getchar() != '\n')
			continue;
		
		switch (choice)
		{
			case 'a': answer = first_num + second_num;
			          printf("%g + %g = %g\n", first_num, second_num, answer);
			          break;
			
			case 's': answer = first_num - second_num;
			          printf("%g - %g = %g\n", first_num, second_num, answer);
			          break;
			
			case 'm': answer = first_num * second_num;
			          printf("%g * %g = %g\n", first_num, second_num, answer);
			          break;
			
			case 'd': answer = first_num / second_num;
			          printf("%g / %g = %g\n", first_num, second_num, answer);
			          break;
			
			default : return 0;
		}
		menu();
	}
	
	printf("Bye.\n");
	
	return 0;
}

void menu(void)
{
	printf("Enter the operation of your choice:\n");
	printf("a. add           s. subtract\n");
	printf("m. multiply      d. divide\n") ;
	printf("q. quit\n");
}
