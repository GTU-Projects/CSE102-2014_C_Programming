/*######################################################################*/
/*HW02_HASAN_MEN_131044009_part2.c          							*/
/*________________________________										*/
/*Written by Hasan MEN on February 27, 2015								*/
/*													  	   				*/
/*Description:															*/
/*____________															*/
/*This program find letter grade and contribution of letter				*/
/*with using exam result which store in Student file					*/
/*INPUT:																*/
/*______																*/
/*																		*/
/*##NOT:X is a variable like name1,name2,namex##						*/
/*	namex,snamex:first letter of names and surnames 					*/
/*	midOnex,midTwox:midtterm results of students						*/
/*	finalx: final result of students									*/
/*OUTPUT:																*/
/*_______																*/
/*	averagex:average of midOnex,midTwox,Finalx							*/
/*	snamex,namex														*/
/*	letter grade: calculated from averagex								*/
/*	contribution of letter: additives on local credit					*/
/*  "contribution = (letter_grade*credit)/total_credit "				*/
/*######################################################################*/
#include <stdio.h>
#define MIN_AVERAGE 0		/* min_average, average can not less than zero*/
#define MIN_MARK 0		    /* minimun-mark   0<=mark<=100*/
#define INVALID_MARK -1		/* use to return mark is false,invalid */

/* function prototypes*/
double average(int mid1,int mid2,int final);
char letterGrade(double average);
void ContributionLetterGrade(char letter);

int main(){
	/* START_OF_MAIN*/
	char name1,sname1,name2,sname2,name3,sname3,name4,sname4,name5,sname5;
	int midOneP1,midTwoP1,FinalOne;
	int midOneP2,midTwoP2,FinalTwo;
	int midOneP3,midTwoP3,FinalThree;
	int midOneP4,midTwoP4,FinalFour;
	int midOneP5,midTwoP5,FinalFive;

	char gradeOne,gradeTwo,gradeThree,gradeFour,gradeFive;
	double average1,average2,average3,average4,average5;

	FILE *inp;
	FILE *out;

	/* END_OF_VARIABLES*/

	/* define and open files */
	inp = fopen("Students.txt","r");
	out = fopen("Grades.txt","w");

	/* scanning student information from input file*/
	fscanf(inp,"%c%c%d%d%d",&name1,&sname1,&midOneP1,&midTwoP1,&FinalOne);
	fscanf(inp," %c%c%d%d%d",&name2,&sname2,&midOneP2,&midTwoP2,&FinalTwo);
	fscanf(inp," %c%c%d%d%d",&name3,&sname3,&midOneP3,&midTwoP3,&FinalThree);
	fscanf(inp," %c%c%d%d%d",&name4,&sname4,&midOneP4,&midTwoP4,&FinalFour);
	fscanf(inp," %c%c%d%d%d",&name5,&sname5,&midOneP5,&midTwoP5,&FinalFive);

	/* calculate average marks with average() fonction*/
	average1 = average(midOneP1,midTwoP1,FinalOne);
	average2 = average(midOneP2,midTwoP2,FinalTwo);
	average3 = average(midOneP3,midTwoP3,FinalThree);
	average4 = average(midOneP4,midTwoP4,FinalFour);
	average5 = average(midOneP5,midTwoP5,FinalFive);

	/*Print information to screen*/
	/* information : names,snames,averages,lettergrades and contributions */
	printf(" --------------- --------------- ");
	printf("--------------- ------------------\n");
	printf("|    STUDENT\t|    AVERAGE\t|    LETTER\t|   CONTRIBUTION   |\n");
	printf(" --------------- --------------- ");
	printf("--------------- ------------------\n");
	printf("\t%c%c\t\t%.1f\t\t%c\t\t",name1,sname1,average1,
		letterGrade(average1));
		ContributionLetterGrade(letterGrade(average1));

	printf(" --------------- --------------- ");
	printf("--------------- ------------------\n");
	printf("\t%c%c\t\t%.1f\t\t%c\t\t",name2,sname2,average2,
		letterGrade(average2));
		ContributionLetterGrade(letterGrade(average2));

	printf(" --------------- --------------- ");
	printf("--------------- ------------------\n");
	printf("\t%c%c\t\t%.1f\t\t%c\t\t",name3,sname3,average3,
		letterGrade(average3));
		ContributionLetterGrade(letterGrade(average3));

	printf(" --------------- --------------- ");
	printf("--------------- ------------------\n");+
	printf("\t%c%c\t\t%.1f\t\t%c\t\t",name4,sname4,average4,
		letterGrade(average4));
		ContributionLetterGrade(letterGrade(average4));

	printf(" --------------- --------------- ");
	printf("--------------- ------------------\n");
	printf("\t%c%c\t\t%.1f\t\t%c\t\t",name5,sname5,average5,
		letterGrade(average5));
		ContributionLetterGrade(letterGrade(average5));
	printf(" --------------- --------------- ");
	printf("--------------- ------------------\n");

	/* when we see -1 on screen or file this means, there are a problem*/
	/* it is our error codes */
	printf("\n-------------\n\"-1\"=> Invalid number/letter\n-------------\n");

/* write some information and calculations to output file*/
	fprintf(out,"%c%c %.2f\n",name1,sname1,average1);
	fprintf(out,"%c%c %.2f\n",name2,sname2,average2);
	fprintf(out,"%c%c %.2f\n",name3,sname3,average3);
	fprintf(out,"%c%c %.2f\n",name4,sname4,average4);
	fprintf(out,"%c%c %.2f\n",name5,sname5,average5);


	/*close files*/
	fclose(inp);
	fclose(out);
	return 0;
	/*END_OF_MAIN*/
}

/*##############################################################*/
/* This function takes exam notes and calculate average			*/
/*	average = 30percent of midterms and 40percent of final		*/
/*##############################################################*/
double average(int mid1,int mid2,int final){

	if (mid1>=MIN_MARK && mid2>=MIN_MARK && final>=MIN_MARK)
		return (mid1*3+mid2*3+final*4)/10.0;
	else return INVALID_MARK; /* return -1 if marks<0 */
}

/*###############################################################*/
/* This function takes averege marks if it's bigger than minimum */
/* average will return a letter according to notes table		 */
/* letters can be A,B,C,D,F										 */
/* if average<min_average will return error code(-1)			 */
/*###############################################################*/
char letterGrade(double average){

	if(average>=MIN_AVERAGE){
		if(average>=85)
			return 'A';
		else if(average >=70)
			return 'B';
		else if(average >=65)
			return 'C';
		else if(average >=40)
			return 'D';
		else return 'F';
	}
	else return 'X';
}


/*##############################################################*/
/* This function takes letter_grade from main and calculate 	*/
/* contribution of letter and write on screen					*/
/*##############################################################*/
void ContributionLetterGrade(char letter){

	switch (letter){

	case 'A' : printf("%.2f\n",(4.0*3.0)/20.0); break;
	case 'B' : printf("%.2f\n",(3.0*3.0)/20.0); break;
	case 'C' : printf("%.2f\n",(2.0*3.0)/20.0); break;
	case 'D' : printf("%.2f\n",(1.0*3.0)/20.0); break;
	case 'F' : printf("%.2f\n",(0.0*3.0)/20.0); break;
	default : printf("Unknown letter grade\n");	/* invalid letter*/
	}

}
/*##################################################################*/
/*				END_OF_HW02_HASAN_MEN_131044009_part2.c         	*/
/*##################################################################*/
