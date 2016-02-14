/*##############################################################################*/
/*HW00_SampleSolution_part2.c                                        			*/
/*_____________________________													*/
/*Written by Evren Cifci on Februay 17, 2015									*/
/*																				*/
/*Description																	*/
/*___________ 																	*/
/*Multiplies 2 given 2nd Degree Polynomials          							*/
/*Inputs:																		*/
/*	-Coefficients of the 1st 2nd degree polynomial								*/
/*	-Coefficients of the 2nd 2nd degree polynomial								*/
/*Outputs:																		*/
/*	-Resulting 4th degree polynomial											*/
/*##############################################################################*/
/*																				*/
/*------------------------------------------------------------------------------*/
/*							Includes											*/
#include <stdio.h>
/*------------------------------------------------------------------------------*/
																				

int
main(){

	double a0, a1, a2;	/*coeffients of the 1st input poly*/
	double b0, b1, b2;	/*coeffients of the 2nd input poly*/
	double r0, r1, r2, r3, r4; /*coefficients of the resulting poly*/

	/*Get the 1st polynomial*/
	printf("Enter the coefficients of the first parabole (from higher to lower order)>");
	scanf("%lf%lf%lf", &a2, &a1, &a0);

	/*Get the 2nd polynomial*/
	printf("Enter the coefficients of the second parabole (from higher to lower order)>");
	scanf("%lf%lf%lf", &b2, &b1, &b0);


	/*Calculate the resulting poly*/
	r4 = a2*b2;
	r3 = a2*b1 + a1*b2;
	r2 = a0*b2 + a1*b1 + a2*b0;
	r1 = a0*b1 + a1*b0;
	r0 = a0*b0; 

	/*Output the resulting poly*/
	printf("The resulting polynomial is %5.2f x^4 + %5.2f x^3 + %5.2f x^2 + %5.2f x + %5.2f.", r4, r3, r2, r1, r0);
	
	return 0;
}

/*##############################################################################*/
/*			       End of HW00_SampleSolution_part2.c 			         		*/
/*##############################################################################*/
