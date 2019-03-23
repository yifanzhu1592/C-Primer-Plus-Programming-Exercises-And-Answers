#include <stdio.h>

static int the_mode;
static int distance;
static double fuel;

void set_mode(int mode)
{
	if (mode == 1)
	{
		the_mode = 1;
	}
	else if (mode == 0)
	{
		the_mode = 0;
	}
	else
	{
		printf("Invalid mode specified. Mode %d(US) used.\n", the_mode);
	}
}

void get_info()
{
	if (the_mode == 0)
	{
		printf("Enter distance traveled in kilometers: ");
		scanf("%d", &distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%lf", &fuel);
	}
	else
	{
		printf("Enter distance traveled in miles: ");
		scanf("%d", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%lf", &fuel);
	}
}

void show_info()
{
	if (the_mode == 0)
	{
		printf("Fuel consumption is %.2lf liters per 100 km.\n", fuel * 100 / distance);
	}
	else
	{
		printf("Fuel consumption is %.1lf miles per gallon.\n", distance / fuel);
	}
}
