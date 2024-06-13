#include <stdio.h>
#define DISTANCECHANGE 1.609
#define FUELCHANGE 3.785
int main()
{
	float distance,fuel,litre,km;
	printf("Please enter your travel distance(miles) and you fuel consumption(gallon):\n");
	scanf("%f %f",&distance,&fuel);
	printf("You can go %.1f miles with a gallon of fuel.\n",distance/fuel);
	litre=fuel/FUELCHANGE;
	km=distance/DISTANCECHANGE;
	printf("You need %.1f litres of fuel if you go 100 km.",km*100/litre);
	return 0;
	
	
}