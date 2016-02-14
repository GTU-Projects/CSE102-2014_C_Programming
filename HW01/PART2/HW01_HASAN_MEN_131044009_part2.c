/*##########################################################*/
/*HW01_HASAN_MEN_131044009_part2.c          				*/
/*________________________________							*/
/*Written by Hasan MEN on February 19, 2015					*/
/*															*/
/*Description:												*/
/*____________												*/
/*This probram, take 2 function and find commoncoefficient..*/
/*than its write x and y on new funciton and calculate		*/
/*INPUT:													*/
/*______													*/
/*	-Coefficients of funcitons								*/
/*	-COefficient of 3rd func. to calculate new value		*/	
/*OUTPUT:													*/
/*_______													*/
/*	-x and y :commond coef.									*/
/*	-F(x,y)  : result of 3rd function						*/
/*##########################################################*/
#include <stdio.h>

int main(){
	/*START_OF_MAIN*/
	double cfOne1,cfOne2,resOne;	/*func 1*/
	double cfTwo1,cfTwo2,resTwo;	/*func 2*/
	double x,y;	/*commont coef*/
	double cfFuncA,cfFuncB; /*func 3*/
	FILE *equ;	/* func1 and func2 coef.  file pointer */
	FILE *func;	/* func3 coef file pointer*/
	FILE *rslt; /* resault[F(x,y)] file pointer*/
	/*END_OF_VARIABLES*/

	/*Opening i/o file*/
	equ = fopen("EqCoefficients.txt","r");
	func = fopen("FuncCoefficients.txt","r");
	rslt = fopen("Results2.txt","w");
	
	/*scaning coefficients of func1 and func2 from equ file*/
	printf("Reading Coefficient of Equation 1 --> ");
	fscanf(equ,"%lf%lf%lf",&cfOne1,&cfOne2,&resOne);
	printf("First equation => %.2fX + %.2fY = %.2f\n",cfOne1,cfOne2,resOne);
	printf("Reading Coefficient of Equation 2 --> ");
	fscanf(equ,"%lf%lf%lf",&cfTwo1,&cfTwo2,&resTwo);
	printf("Second equation => %.2fX + %.2fY = %.2f\n",cfTwo1,cfTwo2,resTwo);

	/*CALCULATE X VALUE */
	x = (((-cfTwo2)*resOne)+(cfOne2*resTwo))/(cfOne1*(-cfTwo2)+(cfOne2*cfTwo1));
	printf("X => %.2f\n",x);

	/* CALCULATE Y VALUE with using value of x*/
	y = ((resOne-(x*cfOne1)) / cfOne2);
	printf("Y => %.2f\n",y);

	/*Printf file x and y */
	fprintf(rslt,"%.2f\t%.2f\t",x,y);

	/*Scan coeffients of function 3 */
	printf("Reading Coefficient of Function --> ");
	fscanf(func,"%lf%lf",&cfFuncA,&cfFuncB);
	printf("Function => %.2fX + %.2fY\n",cfFuncA,cfFuncB);

	/* print screen and file value of new func3 */
	printf("F(x,y) = %.2f\n",x*cfFuncA+y*cfFuncB);
	fprintf(rslt,"%.2f",x*cfFuncA+y*cfFuncB);

	/*CLOSE_FILE*/
	fclose(equ);
	fclose(func);
	fclose(rslt);
	return 0;
	/*END_OF_MAIN*/
}
/*##############################################################*/
/*				HW01_HASAN_MEN_131044009_part2.c				*/
/*##############################################################*/
