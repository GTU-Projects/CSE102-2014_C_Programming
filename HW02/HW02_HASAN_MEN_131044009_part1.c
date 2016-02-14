/*######################################################################*/
/*HW02_HASAN_MEN_131044009_part2.c          							*/
/*________________________________										*/
/*Written by Hasan MEN on February 27, 2015								*/
/*													  	   				*/
/*Description:															*/
/*____________															*/
/* This program takes a random number and give user 2 change to find	*/
/* this number and if user cannot find each steps, it will give 		*/
/*	a little advise														*/
/*INPUT:																*/
/*______																*/
/*	-guess : user guess from keybord									*/	
/*OUTPUT:																*/
/*_______																*/
/*	approaches infos													*/
/*  positive and negative infos											*/
/*######################################################################*/
#include <stdio.h>
#include <stdlib.h>		/* rand() and srand() functions */  

/*function prototypes*/
int RNG();
int CalculateTheDifference(int num1,int num2);
void WarnThePlayer(int number,int guess);

int main(){
	/*START_OF_MAIN*/
	int number;
	int guess;
	/* END_OF_VARIABLES*/

	srand(time(NULL));		/* Reset random number for each use */

	number = RNG();		/* assign a random number to variable number */

	/* take first guess */
	printf("Enter your first guess = ");
	scanf("%d",&guess);
		
	/* if guess is true ,write successful and finish the program*/
	if(number==guess)
		printf("Congratulations...You find number\n");
	else {
		WarnThePlayer(number,guess);	/* if not true warn the player*/
		printf("Enter your second guess = ");
		scanf("%d",&guess);	/* take second guess*/
		if(number==guess)	
			printf("Congratulations...You find number\n");
		else WarnThePlayer(number,guess); 
		/*again not true, warn once more*/
		/*enf of change , the player couldn't find the randon number */
		}
	
	return 0;
	/*END_OF_MAIN*/
}

/*##################################################################*/
/* This function create a random number with using rand()			*/
/*	function and return to number variable							*/
/*##################################################################*/
int RNG(){
	return (1+rand()%10);	/* 1<=x<=10 */
}


/*##################################################################*/
/* Calculate difference between numbers to help user if can not 	*/
/* find first change 												*/
/*-- find big and small number after that remove them 				*/
/*##################################################################*/
int CalculateTheDifference(int num1,int num2){
	
	int temp;	/* use temp vary. to change number order */

	if(num1<num2){
		temp=num1;
		num1=num2;
		num2=temp;
		}

	return num1-num2;	/* big number - small number */
}


/*##################################################################*/	
/* This function warn the player about his guess number				*/
/* takes number and guess parameter 								*/
/* call CalculateTheDifference function and check some inf. 		*/
/* if thats true writes on screen or write warnings 				*/ 
/*##################################################################*/ 
void WarnThePlayer(int number,int guess){

	/* show the user which number is bigger */
	if(number>guess)
		printf("Your Number > Guess\n");
	else if (number<guess)
		printf("Your Number < Guess\n");

	/* find difference and show little advice */
	if (CalculateTheDifference(number,guess)>=5)
			printf("You are too far from the number\n");
	else if (CalculateTheDifference(number,guess)>=3)
			printf("You are far from the number\n");
	else if (CalculateTheDifference(number,guess)<=2)
			printf("You are close to the number\n");
}

/*##################################################################*/
/*				END_OF_HW02_HASAN_MEN_131044009_part1.c         	*/
/*##################################################################*/
