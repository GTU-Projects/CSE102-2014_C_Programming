/*##############################################################*/
/*HW00_HASAN_MEN_131044009_part1.c								*/
/*________________________________								*/
/*Written by Hasan MEN on February 14, 2015						*/
/*																*/
/*Description													*/
/*___________													*/
/*Takes the Integral of a given 1st degree polynomial			*/
/*Inputs:														*/
/*	-Coefficients of the 1st degree polynomial					*/
/*  -Zero input value of the resulting polynomial				*/
/*Outputs:														*/
/*  -Resulting 2nd degree polynomial							*/
/*##############################################################*/
/*																*/
/*--------------------------------------------------------------*/
/*	       					Includes							*/
/*--------------------------------------------------------------*/

#include <stdio.h>

int main(){
	/* Start of main */
	double ia0, ia1;     /*cofficients of the input poly*/
	double p0;	     /*P(0) value of the resulting poly*/
	double ra0, ra1, ra2;     /*coefficients of the resulting poly*/
	/* End of variables */
	
	/*Get the 1st degree input polynomial*/
	printf("Enter the coefficients of the poly (from higher to lower order)>");
	scanf("%lf%lf", &ia1, &ia0);

	/*Get the zero input of the resulting poly(2nd degree polynomial)*/
	printf("Enter P(0) value for the resulting polynomial=>");
	scanf("%lf", &p0);

	/*Calculate the resulting poly*/
	ra2 = (1.0/2) * ia1; 	/* ra2 => a/2 in (ax^2+bx+c) */
	/*(1.0/2) use to convert from integer to double*/

	ra1 = ia0; 			/* ia0 => b in (ax^2+bx+c)   */
	ra0 = p0; 			/* rao => c in (ax^2+bx+c)	 */
	
	/*Output the resulting poly*/
	printf("The resulting poly is %5.2fx^2 + %5.2fx + %5.2f\n", ra2, ra1, ra0);

	return 0;	/*program works succesfully*/
}	
/*##############################################################*/
/*			  End of HW00_HASAN_MEN_131044009_part1.c			*/
/*##############################################################*/
