/*######################################################################*/
/*HW03_HASAN_MEN_131044009_part1.c          							*/
/*________________________________										*/
/*Written by Hasan MEN on March 9, 2015									*/
/*													  	   				*/
/*Description:															*/
/*____________															*/
/*	- this is a guess game. It produce a random number and ask player	*/
/* to find this. İf user find, it will return how many times and ask 	*/
/*	play another games with new random number 							*/
/*INPUT:																*/
/*______																*/
/*	-want = choice play or not											*/
/*	-guess = 															*/	
/*OUTPUT:																*/
/*_______																*/
/*	approaches infos													*/
/*	counter = found in count of chance									*/
/*######################################################################*/
#include <stdio.h>
#include <stdlib.h>	

/*function prototypes*/
int RNG();
int CalculateTheDifference(int num1,int num2);
void WarnThePlayer(int number,int guess);

int main()
{
	/*START_OF_MAIN*/
	int number;
	int guess;
	char want;
	int counter=0;	/* keep the number of trials */
	int repeater=1; /*to use conditional loop*/
	/* END_OF_VARIABLES*/

	
	number = RNG();		/* assign a random number to variable number */

	printf("Wanna play a game ? (E)xit / (P)lay ");
	scanf(" %c",&want);

/* loop will return until press (e,E) */
	while(repeater==1)
	{
	
		switch(want)	
		{
		case 'e':
		case 'E':
			{
			printf("Good Bye...\n");
			repeater++;	/* if press e,E finish the loop */
			}
			break;
		case 'p':
		case 'P':
			{
				++counter; /* count how many times try  */
				printf("Press your %d (st/nd/rd/th) guess >",counter);
				scanf("%d",&guess);
				
				if(number==guess)
				{
					printf("Congrats...\nYou find in %d time(s)\n\n",counter);
					printf("Wanna play another game (E)xit / (P)lay = ");
					scanf(" %c",&want);
					
					/* start a new game and reset the random number */
					number = RNG();
					counter=0; /* reset  counter */
				}
				else
				{
				/* if number not equal to guess return warnings */
					WarnThePlayer(number,guess);
				}
			}
			break;
		default: 
			{
				/* incorrect character */
				printf("Override option\n");
				repeater++;
			}
		}
	}
	return 0;
	/*END_OF_MAIN*/
}

/*##################################################################*/
/* This function create a random number with using rand()			*/
/*	function and return to number variable							*/
/*##################################################################*/
int RNG()
{
	srand(time(NULL));
	return (1+rand()%10);	/* 1<=x<=10 */
}


/*##################################################################*/
/* Calculate difference between numbers to help user if can not 	*/
/* find first change 												*/
/*-- find big and small number after that remove them 				*/
/*##################################################################*/
int CalculateTheDifference(int num1,int num2)
{
	
	int temp;	/* use temp vary. to change number order */

	if(num1<num2)
	{
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
void WarnThePlayer(int number,int guess)
{
	/* show the user which number is bigger */
	if(number>guess)
		printf("Your Guess < Random - ");
	else if (number<guess)
		printf("Your Guess > Random - ");

	/* find difference and show little advice */
	if (CalculateTheDifference(number,guess)>=5)
			printf("You are too far from the number\n\n");
	else if (CalculateTheDifference(number,guess)>=3)
			printf("You are far from the number\n\n");
	else if (CalculateTheDifference(number,guess)<=2)
			printf("You are close to the number\n\n");
}
/*##################################################################*/
/*				END_OF_HW03_HASAN_MEN_131044009_part1.c         	*/
/*##################################################################*/
