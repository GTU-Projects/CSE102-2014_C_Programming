/*############################################################################*/
/*                                                                            */
/*  HW01_Ibrahim_Talha_Aykac_121044031_part3.c               	              */
/*  _______________________                                                   */
/*                                                                            */
/*  Written by Talha Aykac on February 22, 2015                               */
/*  						                                                  */
/*  Description			                                                      */
/*                                                                            */
/*  Reads car informations from the file and calculates total fuel costs      */
/*  _______________________                                                   */
/*                                                                            */
/*  Inputs:                    												  */
/*    - Fuel informations of cars									          */
/*	Outputs:																  */
/*	  - Total fuel costs of cars        									  */
/*############################################################################*/
/*																	       	  */	
/*----------------------------------------------------------------------------*/
/*                                Includes                                    */
/*----------------------------------------------------------------------------*/

#include<stdio.h>


	/* START OF THE MAIN */
	
	int main(){

	FILE *iptr, *optr; 		/* POINTERS OF FILES */
	
	/* VARIABLES */
	int car1,car2,car3;
	double lc1,pc1,kmc1,lc2,pc2,kmc2,lc3,pc3,kmc3;
	double total1,total2,total3;  
	int TL1,TL2,TL3,kurus1,kurus2,kurus3;
	
	iptr=fopen("Cars.txt","r");

	optr=fopen("TotalFuelCosts.txt","a+");
	
	fscanf(iptr," %d %lf %lf %lf %d %lf %lf %lf %d %lf %lf %lf ",&car1,&lc1,&pc1,&kmc1,&car2,&lc2,&pc2,&kmc2,&car3,&lc3,&pc3,&kmc3);
	

	
	total1 = lc1 * pc1 * kmc1;
	total2 = lc2 * pc2 * kmc2;			/* CALCULATIONS OF TOTAL COSTS*/	
	total3 = lc3 * pc3 * kmc3;
	
	TL1 = (int)total1;
	TL2 = (int)total2;				/*CALCULATION THE INTEGER PART OF TOTAL COST*/
	TL3 = (int)total3;
	
	kurus1 = (total1-(int)total1) * 100 ;
	kurus2 = (total2-(int)total2) * 100 ;			/* CALCULATIONS THE OTHER PART OF TOTAL COSTS*/
	kurus3 = (total3-(int)total3) * 100 ;
	
	printf("The total fuel cost of the car %d is %d TL and %d Kurus.\n", car1, TL1, kurus1);
	printf("The total fuel cost of the car %d is %d TL and %d Kurus.\n", car2, TL2, kurus2);			/* PRINT TO CONSOLE */
	printf("The total fuel cost of the car %d is %d TL and %d Kurus.\n", car3, TL3, kurus3);
	
	fprintf(optr, " %d    %.2lf\n %d    %.2lf\n %d    %.2lf ", car1, total1, car2, total2, car3, total3 );		/* PRINT TO "TotalFuelCosts.txt" */
	
	
	fclose(iptr);

	fclose(optr);

	return 0;
}
/* END OF THE MAIN*/

/*###########################################################################*/
/*			END OF HW01_Ibrahim_Talha_Aykac_121044031_part3.c				 */
/*###########################################################################*/
