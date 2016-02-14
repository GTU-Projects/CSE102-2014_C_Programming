/*************************************************************
 *                                                           *
 * HW04 Q1                                                   *
 * Student Name: ......                                      *
 * Student ID  : ......                                      *
 * Date        : ......                                      *
 * Points      : Write points what you believe to deserve    *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define PLAINTEXTFILE "Files/Q1/PlainMessagesToSent.txt"
#define ENCODEDFILE "Files/Q1/EncodedMessages.txt"
#define CRYPTEDFILE "Files/Q1/CryptedMessages.txt"

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
	FILE *f_plane_ptr, *f_encoded_ptr, *f_crypted_ptr;

	/* exit program and print error if plain text file could not be opened to read */
	if( (f_plane_ptr = fopen(PLAINTEXTFILE, "r")) == NULL)
	{
		printf("Error!\nCouldn't open file.");
		return 1;
	}

	/* exit program and print error if encoded text file could not be opened to write */
	if( (f_encoded_ptr = fopen(ENCODEDFILE, "w")) == NULL)
	{
		printf("Error!\nCouldn't create file.");
		return 2;
	}

	encode_message(f_plane_ptr, f_encoded_ptr);

	/* close plain and encoded files */
	fclose(f_plane_ptr);
	fclose(f_encoded_ptr);

	/* exit program and print error if crypted text file could not be opened to write */
	if( (f_crypted_ptr = fopen(CRYPTEDFILE, "w")) == NULL)
	{
		printf("Error!\nCouldn't create file.");
		return 3;
	}

	/* exit program and print error if encoded text file could not be opened to read */
	if( (f_encoded_ptr = fopen(ENCODEDFILE, "r")) == NULL)
	{
		printf("Error!\nCouldn't read file.");
		return 2;
	}

	crypt_message(f_encoded_ptr, f_crypted_ptr);

	/* close crypted and encoded files */
	fclose(f_encoded_ptr);
	fclose(f_crypted_ptr);

	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void 
encode_and_write_to_file(FILE *f_out_ptr, char character)
{
	int number_of_ones, i;
	switch(character)
	{
		case 'E': number_of_ones = 0; break;
		case 'I': number_of_ones = 1; break;
		case ' ': number_of_ones = 2; break;
		case 'T': number_of_ones = 3; break;
		case 'C': number_of_ones = 4; break;
		case 'N': number_of_ones = 5; break;
		case 'A': number_of_ones = 6; break;
		case 'G': number_of_ones = 7; break;
		case 'B': number_of_ones = 8; break;
		case 'Z': number_of_ones = 9; break;
		case 'H': number_of_ones = 10; break;
		case 'L': number_of_ones = 11; break;
		case 'U': number_of_ones = 12; break;
		case 'V': number_of_ones = 13; break;
		case 'R': number_of_ones = 14; break;
		case 'S': number_of_ones = 15; break;
		case 'Y': number_of_ones = 16; break;
	}

	for(i=0; i<number_of_ones; ++i)
	{
		fprintf(f_out_ptr, "%d", 1);
	}
	fprintf(f_out_ptr, "%d", 0);
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int 
encode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	char c;
	int counter = 0;
	
	while( fscanf(f_in_ptr, "%c", &c) != EOF)
	{
		encode_and_write_to_file(f_out_ptr, c);
		++counter;
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
	char c;
	int counter = 0, n = 5, i = 0;
	
	while( fscanf(f_in_ptr, "%c", &c) != EOF)
	{
		if(c == '1')
		{
			fprintf(f_out_ptr, "%c", '*');
		}
		else
		{
			fprintf(f_out_ptr, "%c", '_');
		}
		++counter;
		if(counter == n)
		{
			++i;
			fprintf(f_out_ptr, "%c", '-');
			i = i % 5;
			n = counter + 5 - i;
		}
	}

	return counter;
}