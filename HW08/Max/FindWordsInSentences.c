#include<stdio.h>
#include<string.h>

#define MAX_WORD_LEN 30
#define MAX_SENTENCE_LEN 200
#define MAX_NUM_OF_WORDS 100

/*Finds the number of occurances of a word in a sentence*/
int find__num_of_word_in_sentence(const char word[], const char sentence[]);

/*Finds the number of occurances of each word in all sentences*/
/*words: words to be searched*/
/*sentences: sentences  in which the words will be searched*/
/*occurances: array to be filled indicating the number of occurances of each word in all sentences*/
void find_num_of_all_words_in_all_sentences(char words[][MAX_WORD_LEN], int word_count, char sentences[][MAX_SENTENCE_LEN], int sentence_count, int occurances[]);

int main(){
	char words[][MAX_WORD_LEN] =  {"ali", "ahmet", "s"}; 
	int num_of_words = 3; 
	char sentences[][MAX_SENTENCE_LEN] = {"ali ahmet ayse italy s2 ali", "evren ahmet ahmet", "cat", "selim ali", "ahmet"};
	int num_of_sentences = 5;
	int occurances[MAX_NUM_OF_WORDS];
	int i;


	find_num_of_all_words_in_all_sentences(words, num_of_words, sentences, num_of_sentences, occurances);

	/*output the number of occurances*/
	for(i=0; i<num_of_words; ++i)
		printf("%s occurs %d times.\n", words[i], occurances[i]);
	

	printf("%d\n", find_num_of_word_in_sentence("ali", "ahmet ali veli ali"));



	return 0;
}

/*Finds the number of occurances of a word in a sentence*/
int find_num_of_word_in_sentence(const char word[], const char sentence[])
{
	char str[MAX_WORD_LEN];
	int count=0;
	int length=0;
	int i=0;
	int j=0;

	/*Loop until yheend of the sentece*/
	while((str[j]=sentence[i])!='\0'){
		if(str[j]==' '){
			/*a space character is met; 
			check if the ending word in the sentence is the same as the search word*/
			if(strncmp(str, word, length)==0)
				/*a word is found in the sentence update the count*/
				count++;
			/*update the index and the length of the new word*/
			length=0;
			j=0;
		}
		else{
			j++;
			length++;
		}
	i++;
	}

	/*check the last word in the sentence*/
	if(strncmp(str, word, length)==0)
		count++;

	return count;
}

/*Finds the number of occurances of each word in all sentences*/
void find_num_of_all_words_in_all_sentences(char words[][MAX_WORD_LEN], int word_count, char sentences[][MAX_SENTENCE_LEN], int sentence_count, int occurances[])
{
	int i, j;
	int total = 0;

	for(i=0; i<word_count; ++i){
		for(j=0; j<sentence_count; ++j)
			/*find the num of occurances of word[i] in all sentences*/
			total += find_num_of_word_in_sentence(words[i], sentences[j]);
		/*record the num of occurance and reset the total to find the num of occ of the next word*/
		occurances[i] = total;
		total = 0;
	}
}