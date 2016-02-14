/*************************************************************
 *                                                           *
 * HW04 Q2                                                   *
 * Student Name: ......                                      *
 * Student ID  : ......                                      *
 * Date        : ......                                      *
 * Points      : Write points what you believe to deserve    *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define PLAINTEXTFILE "Files/Q2/ReceivedMessage.txt"
#define ENCODEDFILE "Files/Q2/EncodedInput.txt"
#define CRYPTEDINPUT "Files/Q2/CryptedInput.txt"

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/
void 
decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/
int 
decode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/
int 
decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Reads encrypted text and creates encoded and              *
 * plain text files                                          *
 *************************************************************/
int 
main(int argc, char* argv[])
{
	FILE *f_plane_ptr, *f_encoded_ptr, *f_crypted_ptr;

	/* exit program and print error if encrypted text file could not be opened to read */ 
	if( (f_crypted_ptr = fopen(CRYPTEDINPUT, "r")) == NULL)
	{
		printf("Error!\nCouldn't open file.");
		return 1;
	}

	/* exit program and print error if encoded text file could not be opened to write */
	if( (f_encoded_ptr = fopen(ENCODEDFILE, "w")) == NULL)
	{
		printf("Error!\nCouldn't create file.");
		return 2;
	} //exit program and print error if file could not be opened

	decrypt_message(f_crypted_ptr, f_encoded_ptr);

	/* close encrypted and encoded files */
	fclose(f_crypted_ptr);
	fclose(f_encoded_ptr);

	/* exit program and print error if plain text file could not be opened to write */
	if( (f_plane_ptr = fopen(PLAINTEXTFILE, "w")) == NULL)
	{
		printf("Error!\nCouldn't create file.");
		return 3;
	}

	/* exit program and print error if encoded text file could not be opened to read */
	if( (f_encoded_ptr = fopen(ENCODEDFILE, "r")) == NULL)
	{
		printf("Error!\nCouldn't read file.");
		return 2;
	} //exit program and print error if file could not be opened

	decode_message(f_encoded_ptr, f_plane_ptr);

	/* close encoded and plain files */
	fclose(f_encoded_ptr);
	fclose(f_plane_ptr);

	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/
void 
decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones)
{
	char c;
	switch(number_of_ones)
	{
		case 0: c = 'E'; break;
		case 1: c = 'I'; break;
		case 2: c = ' '; break;
		case 3: c = 'T'; break;
		case 4: c = 'C'; break;
		case 5: c = 'N'; break;
		case 6: c = 'A'; break;
		case 7: c = 'G'; break;
		case 8: c = 'B'; break;
		case 9: c = 'Z'; break;
		case 10: c = 'H'; break;
		case 11: c = 'L'; break;
		case 12: c = 'U'; break;
		case 13: c = 'V'; break;
		case 14: c = 'R'; break;
		case 15: c = 'S'; break;
		case 16: c = 'Y'; break;
	}

	fprintf(f_out_ptr, "%c", c);
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/
int 
decode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	char c;
	int number_of_ones = 0, num;
	int counter = 0;
	
	while( fscanf(f_in_ptr, "%c", &c) != EOF)
	{
		num = c - '0';
		if( num == 1)
		{
			++number_of_ones;
		}
		else
		{
			decode_and_write_to_file(f_out_ptr, number_of_ones);
			number_of_ones = 0;
		}
		++counter;
	}

	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/
int 
decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	char c;
	int counter = 0;
	
	while( fscanf(f_in_ptr, "%c", &c) != EOF)
	{
		if(c == '*')
		{
			fprintf(f_out_ptr, "%c", '1');
		}
		else if( c == '_')
		{
			fprintf(f_out_ptr, "%c", '0');
		}
		++counter;
	}

	return counter;
}