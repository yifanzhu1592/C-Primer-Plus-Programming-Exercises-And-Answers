

#include <stdio.h>
#include "pe12-3a.h"

void check_mode(int *pm)
{
	if (*pm != METRIC && *pm != US)
	{
		printf("Invalid mode specified. Mode %d\n", *pm);
		printf("Previous mode will be used.\n");
		*pm = USE_RECENT;
	}
}

void get_info(int mode, double * pd, double * pf)
{
	if (mode == METRIC)
		printf("Enter distance traveled in kilometers: ");
	else
		printf("Enter distance traveled in miles: ");
	scanf("%lf", pd);
	if (mode == METRIC)
		printf("Enter fuel consumed in liters: ");
	else
		printf("Enter fuel consumed in gallons: ");
	scanf("%lf", pf);
}

void show_info(int mode, double distance, double fuel)
{
	printf("Fuel consumption is ");
	if (mode == METRIC)
		printf("%.2lf liters per 100 km.\n", 100 * fuel / distance);
	else
		printf("%.1lf miles per gallon.\n", distance / fuel);
}
