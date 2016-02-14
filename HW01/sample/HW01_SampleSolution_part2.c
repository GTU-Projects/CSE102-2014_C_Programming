/*######################################################*/
/*HW01_NevzatFurkan_Yangil_141044035.c                  */
/*_________________________________________             */
/*Written by Nevzat Furkan Yangil on February 24, 2015  */
/*                                                      */
/*Description                                           */
/*_____________                                         */
/*Takes two linear equation find x and y values from    */
/*the equations then puts these values into a funtion   */
/*and outputs the result  				*/
/*Inputs                                                */
/*  -Two linear equations coefficients                  */
/*  -A function with two unkowns  		        */
/*Outputs:                                              */
/*  -Value of x and y                                   */
/*  -Result of the two unkown function			*/
/*######################################################*/
/*                                                      */
/*------------------------------------------------------*/
/*                      Includes                        */
/*------------------------------------------------------*/

#include <stdio.h> 
#include <math.h> 


int main()
{
	double q11, q12, q13 ; /* Coefficients of the first eqution. */
	double q21, q22, q23 ; /* Coefficients of the second eqution. */
	double f1, f2 ;        /* Coefficients of the function. */
	double rf ;	       /* Result of the function. */	
	double Cal11, Cal12, Cal21, Cal22 ; /* Some needed value for calculations. */ 
	double y, x ; /* The value of x and y */

	FILE *i1ptr, *i2ptr, *optr ;
	
	i1ptr = fopen("EqCoefficients.txt", "r") ;
	i2ptr = fopen("FuncCoefficients.txt", "r") ;
	optr = fopen("Results2.txt", "w") ;

	/* Gets the inputs from files */
	fscanf(i1ptr, "%lf %lf %lf %lf %lf %lf", &q11, &q12, &q13, &q21, &q22, &q23) ;
	fscanf(i2ptr, "%lf %lf", &f1, &f2) ;

	fclose(i1ptr) ;
	fclose(i2ptr) ;

	/* Calculations to find value of x and y */
	Cal11 = q22 * q11 / q21 ;
	Cal12 = q23 * q11 / q21 ;
	
	Cal21 = q12 - Cal11 ;
	Cal22 = q13 - Cal12 ;

	y = Cal22 / Cal21 ;
	x = (q13 - (q12 * y)) / q11 ;

	/* Calculating function with value of x and y placed */
	rf = (f1 * x) + (f2 * y) ;

	/* Gives the results to the console */
	printf("x equals %f.\ny equals %f.\nf(x,y) equals %f.\n", x, y, rf) ;

	/* Writes the results to a file */
	fprintf(optr, "%f %f %f", x, y, rf) ;

	fclose(optr) ;


	return (0) ;

}

/*#####################################################*/
/*     End of HW01_NevzatFurkan_Yangil_141044035.c     */
/*#####################################################*/
