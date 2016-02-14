/*##########################################################*/
/*HW01_HASAN_MEN_131044009_part3.c          				*/
/*________________________________							*/
/*Written by Hasan MEN on February 19, 2015					*/
/*															*/
/*Description:												*/
/*____________												*/
/*This program reads car information from input file and 	*/	
/*compute total fuel cost									*/
/*INPUT:													*/
/*______													*/
/*	-amount of consumed fuel,price of fuel					*/
/*	-total km,car number									*/	
/*OUTPUT:													*/
/*_______													*/
/*	-car number												*/
/*	-Total fuel costs(tl and kurus)							*/
/*##########################################################*/
#include <stdio.h>

int main(){
	/*START_OF_MAIN*/
	int carNum1,carNum2,carNum3;	/*item numbers*/
	double amount1,price1,totalKm1;	/*car informations*/
	double amount2,price2,totalKm2;
	double amount3,price3,totalKm3;
	double totcost1,totcost2,totcost3;	/*total costs*/
	FILE *car;	/*ınput file*/
	FILE *cost;	/*output file*/
	/*END_OF_VARIABLES*/

	/*open_i/o_file*/
	car = fopen("Cars.txt","r");
	cost = fopen("TotalFuelCosts.txt","w");

	/*Read car information from Cars.txt*/
	printf("Reading Information from Car.txt\n");

	fscanf(car,"%d%lf%lf%lf",&carNum1,&amount1,&price1,&totalKm1);
	fscanf(car,"%d%lf%lf%lf",&carNum2,&amount2,&price2,&totalKm2);
	fscanf(car,"%d%lf%lf%lf",&carNum3,&amount3,&price3,&totalKm3);
	
	/*Print car information on screen*/
	printf("CarNumber\tFuel\tPrice\tTotalKM\n");
	printf("%d\t\t%.2f\t%.2f\t%.2f\n",carNum1,amount1,price1,totalKm1);
	printf("%d\t\t%.2f\t%.2f\t%.2f\n",carNum2,amount2,price2,totalKm2);
	printf("%d\t\t%.2f\t%.2f\t%.2f\n",carNum3,amount3,price3,totalKm3);

	/*Compute total costs */
	totcost1 = amount1*price1*totalKm1;
	totcost2 = amount2*price2*totalKm2;
	totcost3 = amount3*price3*totalKm3;

	/*Print total costs in tl and kurus*/
	/*  (int)((totcost1-(int)totcost1)*100) */
	printf("The total fuel cost of the car %d is %d TL and %d Kurus \n",carNum1,
	(int)totcost1,(int)((totcost1-(int)totcost1)*100));
	printf("The total fuel cost of the car %d is %d TL and %d Kurus \n",carNum2,
	(int)totcost2,(int)((totcost2-(int)totcost2)*100));
	printf("The total fuel cost of the car %d is %d TL and %d Kurus \n",carNum3,
	(int)totcost3,(int)((totcost3-(int)totcost3)*100));
	
	/* printf only item codes and fuel costs in output file */ 
	fprintf(cost,"%d %.2f\n%d %.2f\n%d %.2f",carNum1,totcost1,carNum2,totcost2,
															  carNum3,totcost3);
	
	/*CLOSE_FILE*/
	fclose(car);
	fclose(cost);
	return 0;
}
/*##############################################################*/
/*			END_OF_HW01_HASAN_MEN_131044009_part2.c				*/
/*##############################################################*/
