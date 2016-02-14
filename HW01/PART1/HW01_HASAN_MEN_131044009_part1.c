/*##########################################################*/
/*HW01_HASAN_MEN_131044009_part1.c          				*/
/*________________________________							*/
/*Written by Hasan MEN on February 19, 2015					*/
/*													  	    */
/*Description:												*/
/*____________												*/
/*This program calculate some mathmatical problem         	*/
/*G(x) , F(x) , FOG(x) , GOF(x)								*/
/*INPUT:													*/
/*______													*/
/*	-x :user defined										*/
/*	-Y :constant macro										*/	
/*OUTPUT:													*/
/*_______													*/
/*	-FOG(X) and GOF(X)										*/
/*##########################################################*/

#include <stdio.h>
#include <math.h>
#define Y 8.0

/*##########################################################*/
/*															*/
/* Calculate G(a) function with basis matematical operators	*/
/* a : number which read from file.							*/
/*															*/
/*##########################################################*/
double gx(double a);

/*##########################################################*/
/*															*/
/* Calculate F(x), use sin,sqrt,pow function and return		*/
/* --result of F(x)											*/
/*															*/
/*##########################################################*/
double fx(double a);




int main(){
	/*START_OF_MAIN*/

	
	int	x;/* user defined variables*/

	FILE *inp;	/* input file pointer */
	FILE *outp;	/* output file pointer */
	/*END_OF_VARIABLES*/

	/* Open files */
	inp = fopen("Variables.txt","r");
	outp= fopen("Results1.txt","w");

	/* scan x and print screen all variables */
	fscanf(inp,"%d",&x);
	printf("X is %d and Constant Y is %.3f\n",x,Y);
	

	/* Sending x in the function so a assigned x */
	/* write gx and fx , using function in 3th part of fprintf func.*/
	printf("G(X) = %f and F(X) = %f\n",gx(x),fx(x));

	/* call gx and fx to and send value of fx and gx */
	/*write output files fogx and gofx */
	printf("GOF(x) = %f , FOG(x) = %f \n",gx(fx(x)),fx(gx(x)));
	fprintf(outp,"%f\t%f ",gx(fx(x)),fx(gx(x)));
	

	/*Close FILES*/
	fclose(inp);
	fclose(outp);

	return 0;
	/*END_OF_MAIN*/
}

double gx(double a){

	/*CALCULATE gx(a) and return value */  
	return a+(1.0/(a+(Y/(2.0*a))));
}

double fx(double a){
	/*CALCULATE gx(a) and return value */  
	return sin(pow((((a+Y)/a)+sqrt(log((pow(3.0,a)/(2.0*a+1))))),2.5));
}

/*##############################################################*/
/*				HW01_HASAN_MEN_131044009_part1.c				*/
/*##############################################################*/
