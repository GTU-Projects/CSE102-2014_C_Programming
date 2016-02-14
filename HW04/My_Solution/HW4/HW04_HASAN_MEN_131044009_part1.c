/*************************************************************
 *                                                           *
 * HW04 Q1                                                   *
 * Student Name: HASAN MEN                                   *
 * Student ID  : 131044009                                   *
 * Date        : 15.3.15                                     *
 * Points      : This program reads plain message from text  *
 * file and convert this 1/0 .It's not enough to share plain *
 * message because of cold war.Atfer that, takes 1/0 from	 *
 * encode files and return that chars to "*","-" and "_" and *
 * write in the crypted message file.						 *
 *                                                           *
 *************************************************************/
#include <stdio.h>



#define PLAINTEXTFILE "Files/Q1/PlainMessagesToSent.txt"
#define ENCODEDFILE "Files/Q1/EncodedMessages.txt"
#define CRYPTEDFILE "Files/Q1/CryptedMessages.txt"

/*function prototypes */
/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void 
encode_and_write_to_file(FILE *f_out_ptr, char character);

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int 
encode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return encoded character number                           *
 *************************************************************/
int 
crypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Reads plane text, creates encoded and crypted text files  *
 *************************************************************/
int 
main(int argc, char* argv[])
{
	/* Start_of_main */
	
	FILE *f_plane_ptr, *f_encoded_ptr, *f_crypted_ptr;
	
	/* if files couldnot be opened , print error and exit the programs */ 
	if((f_plane_ptr= fopen(PLAINTEXTFILE,"r"))==NULL || 
	   (f_encoded_ptr= fopen(ENCODEDFILE,"w"))==NULL )
	{
		if((f_plane_ptr= fopen(PLAINTEXTFILE,"r"))==NULL)
			printf("Can't open the PLAINTEXTFILE to read.\n");
		else
			printf("Can't open the ENCODEDFILE to write.\n");
	}
	
	/* files opened and continued */
	else
	{
	
	/* call encode_message and start to crypte message */
	encode_message(f_plane_ptr, f_encoded_ptr);
	
	/*close files*/
	fclose(f_plane_ptr);
	fclose(f_encoded_ptr);
	
		/* if files couldnot be opened , print error and exit the programs */ 
		if((f_crypted_ptr= fopen(CRYPTEDFILE,"w"))==NULL || 
			(f_encoded_ptr= fopen(ENCODEDFILE,"r"))==NULL )
		{
			if((f_crypted_ptr= fopen(CRYPTEDFILE,"w"))==NULL)
				printf("Can't open the CRYPTEDFILE to write\n");
			else
				printf("Can't open the ENCODEDFILE to read.\n");
		}	
		/* files opened and continued */
		else
		{
		
		/*call crypt_message funcion for last cryping*/
		crypt_message(f_encoded_ptr, f_crypted_ptr);
		
		/* Mission completed */
		printf("\n****    CRYPTED	****\n");
		
		/*close files */
		fclose(f_crypted_ptr);
		fclose(f_encoded_ptr);	
		}
	}
	return 0;
	/*end _of_main*/
}

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message      									 *
 * Input:													 *
 * ------characters which readed from plainfile              *
 * Output:													 *
 * ------encoded message(1/0's) -> writed in ENCODEDFILE	 *
 *************************************************************/
void 
encode_and_write_to_file(FILE *f_out_ptr, char character)
{

	int number_of_ones;	/* numbers , readed from encoding table */
	int ones;			/* local variable for loop */
	
	/*	GTU Encoding Table */
	switch(character)
	{
	case 'E':
		number_of_ones=0; 		break;
	case 'I':
		number_of_ones=1;		break;
	case ' ':
		number_of_ones=2;		break;
	case 'T':
		number_of_ones=3;		break;
	case 'C':
		number_of_ones=4;		break;
	case 'N':
		number_of_ones=5;		break;
	case 'A':
		number_of_ones=6;		break;
	case 'G':	
		number_of_ones=7;		break;
	case 'B':		
		number_of_ones=8;		break;
	case 'Z':		
		number_of_ones=9;		break;
	case 'H':		
		number_of_ones=10;		break;
	case 'L':		
		number_of_ones=11;		break;
	case 'U':		
		number_of_ones=12;		break;
	case 'V':		
		number_of_ones=13;		break;
	case 'R':		
		number_of_ones=14;		break;
	case 'S':		
		number_of_ones=15;		break;
	case 'Y':		
		number_of_ones=16;		break;
		
	default : printf("*** %c NOT SUPPORTED	***",character);
	}
	
	/* write to end of number of ones */
	for(ones=1;ones<=number_of_ones;ones++)
	{
		fprintf(f_out_ptr,"1");
	}
	fprintf(f_out_ptr,"0");
	
	/*end of funcion*/	
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 * Input:													 *
 * ------PLAİNTEXTFİLE 							             *
 * Output:													 *
 * ------encoded message(1/0's) -> writed in ENCODEDFILE	 *
 *************************************************************/

int 
encode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	char character;	/* allocated to chars, readed files */
	int counter = 0; /* number of chars read from input file */
	
	
	while(fscanf(f_in_ptr,"%c",&character) != EOF)

	{
	/* s.times computer reads "\n" end of line and send this func. ,I made it
	 * to escape warnings."\n" not a character for us. */
		if(character != '\n')
		{
		
		/* send chars to write file like 0/1's */
		encode_and_write_to_file(f_out_ptr,character);
		counter++;	/* increase number of read */
		}
		
		/* if reads '\n' , scan next character to come end of file*/
		else fscanf(f_in_ptr,"%c",&character);
	}	
	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return number of characters read from encoded text file   *
 *************************************************************/
int 
crypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	char number;	/* local variable, keep 1/0 from file */
	int counter = 0;	/* */
	int read_number=0; /* number of characters read file*/
	int N=5; 
	
	while(fscanf(f_in_ptr,"%c",&number) != EOF)
	{
		int M=N;
	
	/* reading char from file if it's 1 prints '*' , if it's 0 print '0'*/
	/* and increase read number and inrease number 						*/
	/* if counter==m print '-' and reduce N-- when N==0 -> make N==5	*/
	/* *****-****-***-**-*-*****-****-***-**-*							*/
	/* make a loof like up there 										*/
		if(number!='\n')
		{
			
			if(number=='1')
				fprintf(f_out_ptr,"*");
			else fprintf(f_out_ptr,"_");
			counter++;	
			read_number++;		
		}
		
		if(counter==M)
		{
			fprintf(f_out_ptr,"-");
			counter=0;
			N--;
	
			if(N==0)
			{
				N=5;
			}
		}	
	}
	return read_number;
}

/* END OF HW04_HASAN_MEN_131044009_part1.c   */
