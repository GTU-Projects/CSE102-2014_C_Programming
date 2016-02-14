/*##########################################################################*/
/*HW00_HASAN_MEN_131044009_part2.c			        						*/
/*__________________________												*/
/*Written by Hasan MEN on February 14, 2015									*/
/*																			*/
/*Description																*/
/*___________																*/
/*Takes the coefficients of polies and find multiplication of polies		*/
/*Inputs:																	*/
/*  -Coefficients of the 2nd degree polynomials								*/
/*Outputs:																	*/
/*  -Resulting 2nd degree polynomials										*/
/*  -The multiplication of them(4th degree poly)							*/
/*##########################################################################*/
/*																			*/
/*--------------------------------------------------------------------------*/
/*									Includes 								*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>

int 
main(){
	/* Start_of_main */
	/*coefficients of input polynomials */
	double	coefA, coefB, coefC,
			coefD, coefE, coefF;
	
	/*coefficients of output poly*/
	double newCoefA, newCoefB, newCoefC, newCoefD, newCoefE;
 	/* enf of variables */

	/*Get first polynomial*/
	printf("Enter the coefficients of the first poly(from A to C -AX^2+BX+C)>");
	scanf("%lf%lf%lf", &coefA, &coefB, &coefC);

	/*Get the second polynomial*/
	printf("Enter the coefficients of the second poly(from D to E-DX^2+EX+F)>");
	scanf("%lf%lf%lf", &coefD, &coefE, &coefF);

	/*Check the polynomials on screen */
	printf("1st Poly is %3.2f*x^2 + %3.2f*x + %3.2f \n", coefA, coefB, coefC);
	printf("2nd Poly is %3.2f*x^2 + %3.2f*x + %3.2f \n\n", coefD, coefE, coefF);

	/*Calculate new coefficient of 4th degree polynomial*/
	newCoefA = (coefA * coefD);
	newCoefB = (coefA * coefE)+(coefB * coefD);
	newCoefC = (coefA * coefF)+(coefB * coefE)+(coefC * coefD);
	newCoefD = (coefB * coefF)+(coefC * coefE);
	newCoefE = (coefC * coefF);

	/*Output the multiplication of 2 two polies*/
	printf("The multiplication of polies => \n ");
	printf("(%.1f)X^4 + (%.1f)X^3 + (%.1f)X^2 + (%.1f)X + (%.1f)\n",
				newCoefA, newCoefB, newCoefC, newCoefD, newCoefE);
	return 0;
}

/*##########################################################################*/
/* 					End of HW00_HASAN_MEN_131044009_part2.c					*/
/*##########################################################################*/
