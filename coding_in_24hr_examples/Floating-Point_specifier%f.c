/*
 * Integer Vs Floating-point division */

#include <stdio.h>

main()
{
	int int_sum1, int_sum2, int_sum3;
	float flt_num1, flt_num2, flt_num3;

	int_sum1 = 32 / 10;
	flt_num1 = 32 / 10;
	int_sum2 = 32.0 / 10;
	flt-num2 = 32.0 / 10;
	int_sum3 = 32 / 10.0;
	flt_num3 = 32 /10.0;

	printf("The integer division of 32/10 is: %d.\n", int_sum1);
	printf("The floating-point division of 32/10 is: %f.\n", flt_num1);
	printf("The integer division of 32.0/10 is: %d.\n", int_sum2);
	printf("The floating-point 32.0/10 is: %f.\n", flt_num2);
	printf("The integer division of 32/10 is: %d.\n", int_sum3);
	printf("The floating-point of 32/10 is: %f.\n", flt_num3);

	return (0);
}
