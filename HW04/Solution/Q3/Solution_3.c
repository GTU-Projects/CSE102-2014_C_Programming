/*************************************************************
 *                                                           *
 * HW04 Q3                                                   *
 * Student Name: ......                                      *
 * Student ID  : ......                                      *
 * Date        : ......                                      *
 * Points      : Write points what you believe to deserve    *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define CHARACTERFILE "Files/Q3/CharacterList.txt"
#define SAMPLEFILE "Files/Q3/Sample.txt"
#define ENCODEDFILE "Files/Q3/XUniversityEncoded.txt"
#define PLAINTEXTFILE "Files/Q3/XUniversityMessage.txt"

/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void 
swap_int(int *a, int *b);

/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void 
swap_char(char *a, char *b);

/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void
sort(char *a, int a_num, char *b, int b_num, char *c, int c_num);

/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int 
is_letter(char c);

/*************************************************************
 * Read characters from character list file and if character *
 * is letter assign characters to c1, c2 and c3.             *
 * If file has not three letters assign NULL to input char   *
 * by order. For ex. file has two letters assign proper      *
 * letters to c1 and c2 and assign NULL to c3. If file has   *
 * four letters assign c1, c2 and c3 first three letters.    *
 * Return number of letters in character list file.          *
 * Do not forget to count only proper letters with your      *
 * is_letter function. Return number of letters not chars    *
 *************************************************************/
int 
read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3);

/*************************************************************
 * Read letters from Sample file and compute frequency of    *
 * letters. Then sort it inside this function. Call sort     *
 * function. At the end make sure that *c1 keeps most        *
 * frequent used letter, *c3 keeps least frequent used       *
 * letter and *c2 keeps remained letter                      *
 *************************************************************/
void 
count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3);

/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void 
decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3);

/*************************************************************
 * Learns XUniversity's encoding system from given files ,   *
 * decodes their encoded messages and writes as plain text to*
 * a file                                                    *
 *************************************************************/
int 
main(int argc, char* argv[])
{
	FILE *f_character_list_ptr, *f_sample_file_ptr, *f_encoded_ptr,
		*f_plain_text_ptr;
	int character_number;
	char c1, c2, c3;
	/* exit program and print error if plain text file could not be opened to read */
	
	/* exit program and print error if character list file could not be opened to read */
	if( (f_character_list_ptr = fopen(CHARACTERFILE, "r")) == NULL)
	{
		printf("Error!\nCouldn't open file.");
		return 1;
	} /* exit program and print error if file could not be opened */

	/* call read_character_list function and get return value *
	 * if number of letter read is not equal to three exit    *
	 * program                                                */
	character_number = read_character_list(f_character_list_ptr, &c1, &c2, &c3);
	
	if(character_number != 3)
	{
		printf("Character list is corrupted!\n");
		return 2;
	}
	
	/* close character list file */ 
	fclose(f_character_list_ptr);

	/* exit program and print error if sample file could not be opened to read */
	if( (f_sample_file_ptr = fopen(SAMPLEFILE, "r")) == NULL)
	{
		printf("Error!\nCouldn't open file.");
		return 1;
	}

	/* Call count_letters function and swap letters inside function *
	 * according to number of counts                                */
	count_letters(f_sample_file_ptr, &c1, &c2, &c3);
	
	/* close sample file */
	fclose(f_sample_file_ptr);

	/* exit program and print error if encoded file could not be opened to read */
	if( (f_encoded_ptr = fopen(ENCODEDFILE, "r")) == NULL)
	{
		printf("Error!\nCouldn't open file.");
		return 1;
	}
	
	/* exit program and print error if plain text file could not be opened to write */
	if( (f_plain_text_ptr = fopen(PLAINTEXTFILE, "w")) == NULL)
	{
		printf("Error!\nCouldn't open file.");
		return 1;
	}
	
	/* Call decode function */
	decode(f_encoded_ptr, f_plain_text_ptr, c1, c2, c3);

	/* close encoded and plain text file */
	fclose(f_encoded_ptr);
	fclose(f_plain_text_ptr);

	return 0;
}

/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void 
swap_int(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void 
swap_char(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void
sort(char *a, int a_num, char *b, int b_num, char *c, int c_num)
{
	if( c_num > b_num )
	{
		swap_int(&c_num, &b_num);
		swap_char(c, b);
	}

	if ( b_num > a_num )
	{
		swap_int(&b_num, &a_num);
		swap_char(b, a);
	}

	if( c_num > a_num )
	{
		swap_int(&c_num, &a_num);
		swap_char(c, a);
	}
}

/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int 
is_letter(char c)
{
	int difference;
	difference = c - 'A';
	if( difference > 25 || difference < 0)
		return FALSE;
	return TRUE;
}

/*************************************************************
 * Read characters from character list file and if character *
 * is letter assign characters to c1, c2 and c3.             *
 * If file has not three letters assign NULL to input char   *
 * by order. For ex. file has two letters assign proper      *
 * letters to c1 and c2 and assign NULL to c3. If file has   *
 * four letters assign c1, c2 and c3 first three letters.    *
 * Return number of letters in character list file.          *
 * Do not forget to count only proper letters with your      *
 * is_letter function. Return number of letters not chars    *
 *************************************************************/
int 
read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3)
{
	char c;
	int counter = 0;
	*c1 = *c2 = *c3 = NULL;

	while( fscanf(f_in_ptr, "%c", &c) != EOF )
	{
		if( is_letter(c) )
		{
			++counter;
			switch(counter)
			{
				case 1: *c1 = c; break;
				case 2: *c2 = c; break;
				case 3: *c3 = c; break;
			}
		}
	}
	return counter;
}

/*************************************************************
 * Read letters from Sample file and compute frequency of    *
 * letters. Then sort it inside this function. Call sort     *
 * function. At the end make sure that *c1 keeps most        *
 * frequent used letter, *c3 keeps least frequent used       *
 * letter and *c2 keeps remained letter                      *
 *************************************************************/
void 
count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3)
{
	char c;
	int n1 = 0, n2 = 0, n3 = 0;

	while(fscanf(f_in_ptr, "%c", &c) != EOF)
	{
		if(c == *c1)
		{
			++n1;
		} else if ( c == *c2)
		{
			++n2;
		} else 
		{
			++n3;
		}
	}

	sort(c1, n1, c2, n2, c3, n3);

}

/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void 
decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3)
{
	int num_of_ones = 0, num;
	char c;

	while(fscanf(f_in_ptr, "%c", &c) != EOF)
	{
		num = c - '0';

		if (num == 1)
		{
			++num_of_ones;
		} else
		{
			switch(num_of_ones)
			{
				case 0: fprintf(f_out_ptr, "%c", c1); break;
				case 1: fprintf(f_out_ptr, "%c", c2); break;
				case 2: fprintf(f_out_ptr, "%c", c3); break;
			}
			num_of_ones = 0;
		}
	}
}