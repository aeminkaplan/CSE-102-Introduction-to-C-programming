/*************************************************************
 *                                                           *
 * HW04 Q3                                                   *
 * Student Name: Ahmet Emin KAPLAN                           *
 * Student ID  : 131044042                                   *
 * Date        : 16.03.2015                                  *
 * Points      : 49                                          *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define CHARACTERFILE "CharacterList.txt"
#define SAMPLEFILE "Sample.txt"
#define ENCODEDFILE "XUniversityEncoded.txt"
#define PLAINTEXTFILE "HW04_AhmetEmin_Kaplan_131044042_XUniversityMessage.txt"

/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void swap_int(int *a, int *b);

/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void swap_char(char *a, char *b);

/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void sort(char *a, int a_num, char *b, int b_num, char *c, int c_num);

/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int is_letter(char c);

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
int read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3);

/*************************************************************
 * Read letters from Sample file and compute frequency of    *
 * letters. Then sort it inside this function. Call sort     *
 * function. At the end make sure that *c1 keeps most        *
 * frequent used letter, *c3 keeps least frequent used       *
 * letter and *c2 keeps remained letter                      *
 *************************************************************/
void count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3);

/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3);

/*************************************************************
 * Learns XUniversity's encoding system from given files ,   *
 * decodes their encoded messages and writes as plain text to*
 * a file                                                    *
 *************************************************************/
int main(int argc, char* argv[])
{
	FILE *f_character_list_ptr, *f_sample_file_ptr, *f_encoded_ptr,*f_plain_text_ptr;
	
	int character_number;

	char c1, c2, c3;

	f_character_list_ptr=fopen(CHARACTERFILE,"r");

/* exit program and print error if character list file could not be opened to read */

	if(f_character_list_ptr==NULL)
	{
		printf("Error! CharacterListText file could not be opened !\n");
		
		return 0;		
	}

	

	character_number=read_character_list(f_character_list_ptr,&c1,&c2,&c3);

	/* call read_character_list function and get return value *

	 * if number of letter read is not equal to three exit    *
	 * program                                                */

	
/* close character list file */

	fclose(f_character_list_ptr);

	if(character_number==3)
	{	
		f_sample_file_ptr=fopen(SAMPLEFILE,"r");


	/* exit program and print error if sample file could not be opened to read */


		if(f_sample_file_ptr==NULL)
		{
			printf("Error! SampleText file could not be opened !\n");
		
			return 0;		
		}
	
/* Call count_letters function and swap letters inside function *
	 * according to number of counts                                */	
		
		count_letters(f_sample_file_ptr,&c1,&c2,&c3);

		/* close sample file */

		fclose(f_sample_file_ptr);
	

	
		f_encoded_ptr=fopen(ENCODEDFILE,"r");

/* exit program and print error if encoded file could not be opened to read */

		if(f_encoded_ptr==NULL)
		{
			printf("Error! EncodedText file could not be opened !\n");
		
			return 0;		
		}
	
		f_plain_text_ptr=fopen(PLAINTEXTFILE,"w");

	/* exit program and print error if plain text file could not be opened to write */
		if(f_plain_text_ptr==NULL)
		{
			printf("Error! PlainText file could not be opened !\n");
		
			return 0;		
		}

	/* Call decode function */	
	
		decode(f_encoded_ptr,f_plain_text_ptr,c1,c2,c3);


	/* close encoded and plain text file */

		fclose(f_encoded_ptr);
		fclose(f_plain_text_ptr);
	

	
	}
	return 0;
}

/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void swap_int(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	
}

/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void swap_char(char *a, char *b)
{	
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void sort(char *a, int a_num, char *b, int b_num, char *c, int c_num)
{
	if(a_num<b_num)
	{
		swap_char(a,b);
		swap_int(&a_num,&b_num);
	}

	if(b_num<c_num)
	{
		swap_char(b,c);
		swap_int(&b_num,&c_num);
	}

	if(a_num<b_num)
	{
		swap_char(a,b);
		swap_int(&a_num,&b_num);
	}
	
}

/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int is_letter(char c)
{
	if(c>='A' && c<='Z')
	{
		return TRUE;
	}
	else
		return FALSE;

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
int read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3)
{	
	*c1='0';
	*c2='0';
	*c3='0';	
	int counter = 0;
	int condition;
	char character;
	while(fscanf(f_in_ptr,"%c",&character)!=EOF)
	{	
		condition=is_letter(character);

		if(condition==TRUE && counter==0)
		{
			*c1=character;
			counter++;
		}
		else if(condition==TRUE && counter==1)
		{
			*c2=character;
			counter++;
		}
		else if(condition==TRUE && counter==2)
		{
			*c3=character;
			counter++;
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
void count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3)
{	
	int a_num=0;

	int b_num=0;
	
	int c_num=0;	

	char character;


	while(fscanf(f_in_ptr,"%c",&character)!=EOF)
	{	
		if(character==*c1)
		{	
			a_num++;
		}
		else if(character==*c2)
		{
			b_num++;
		}
		else if(character==*c3)
		{	
			c_num++;
		}
	}
	
	sort(c1,a_num,c2,b_num,c3,c_num);

}

/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3)
{
	char character;

	int counter=0;


	while(fscanf(f_in_ptr,"%c",&character)!=EOF)
	{	
		if(character=='1')
		{	
			counter++;
		}
		else if(character=='0')
		{
			switch(counter)
			{
			case 0 :
				fprintf(f_out_ptr,"%c",c1);
				counter=0;
				break;
			case 1 : 
				fprintf(f_out_ptr,"%c",c2);
				counter=0;
				break;
			case 2 :
				fprintf(f_out_ptr,"%c",c3);
				counter=0;
				break;

			}	
		
		}
	
	}	
}
