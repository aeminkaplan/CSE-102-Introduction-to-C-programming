/*************************************************************
 *                                                           *
 * HW04 Q1                                                   *
 * Student Name: Ahmet Emin KAPLAN                           *
 * Student ID  : 131044042                                   *
 * Date        : 16.03.2015                                  *
 * Points      : 20                                          *
 *                                                           *
 *************************************************************/
#include<stdio.h>
#include<stdlib.h>

#define PLAINTEXTFILE "PlainMessagesToSent.txt"
#define ENCODEDFILE "HW04_AhmetEmin_Kaplan_131044042_EncodedMessages.txt"
#define CRYPTEDFILE "HW04_AhmetEmin_Kaplan_131044042_CryptedMessages.txt"

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void encode_and_write_to_file(FILE *f_out_ptr, char character);

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int encode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return encoded character number                           *
 *************************************************************/
int crypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Reads plane text, creates encoded and crypted text files  *
 *************************************************************/
int main(int argc, char* argv[])
{	
	FILE *f_plain_ptr, *f_encoded_ptr, *f_crypted_ptr;
	f_plain_ptr=fopen(PLAINTEXTFILE,"r");
	f_encoded_ptr=fopen(ENCODEDFILE,"w");
	
	/* exit program and print error if plain text file could not be opened to read */

	if(f_plain_ptr==NULL)
	{
		printf("Error! PlainText file could not be opened !\n");
		
		return 0;		
	}

	

	/* exit program and print error if encoded text file could not be opened to write */
	
	if(f_encoded_ptr==NULL)
	{
		printf("Error! EncodedText file could not be opened !\n");

		return 0;
	}

	encode_message(f_plain_ptr, f_encoded_ptr);

	/* close plain and encoded files */	
	
	fclose(f_plain_ptr);

	fclose(f_encoded_ptr);

	

	f_crypted_ptr=fopen(CRYPTEDFILE,"w");

	
	f_encoded_ptr=fopen(ENCODEDFILE,"r");
	

	/* exit program and print error if crypted text file could not be opened to write */
	
	if(f_crypted_ptr==NULL)
	{
		
		printf("Error! CryptedText file could not be opened !\n");
		return 0;

	}

	/* exit program and print error if encoded text file could not be opened to read */

	if(f_encoded_ptr==NULL)
	{
		printf("Error! EncodedText file could not be opened !\n");
		return 0;
	}



	crypt_message(f_encoded_ptr, f_crypted_ptr);

	fclose(f_crypted_ptr);

	fclose(f_encoded_ptr);

	/* close crypted and encoded files */
	
	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void encode_and_write_to_file(FILE *f_out_ptr, char character)
{
	
	int counter;
	int i;
	switch(character)
	
	{

	case 'E':
		counter=0;
		break;
	case 'I':
		counter=1;
		break;
	case ' ':
		counter=2;
		break;
	case 'T':
		counter=3;
		break;
	case 'C':
		counter=4;
		break;
	case 'N':
		counter=5;
		break;
	case 'A':
		counter=6;
		break;
	case 'G':
		counter=7;
		break;
	case 'B':
		counter=8;
		break;
	case 'Z':
		counter=9;
		break;
	case 'H':
		counter=10;
		break;
	case 'L':
		counter=11;
		break;
	case 'U':
		counter=12;
		break;
	case 'V':
		counter=13;
		break;
	case 'R':
		counter=14;
		break;
	case 'S':
		counter=15;
		break;
	case 'Y':
		counter=16;
		break;

	default :
		counter=-1;

	}
	
	for(i=0;i<counter;i++)
		{
			fprintf(f_out_ptr,"1");
		}

	if(counter!=-1)
		{
			fprintf(f_out_ptr,"0");

		}


}


/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int encode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	
	int counter = 0;
	
	char character;

	while(fscanf(f_in_ptr,"%c",&character)!= EOF)

	{
		encode_and_write_to_file(f_out_ptr,character);
		
		counter++;
	}

	return counter;
	
}
/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return number of characters read from encoded text file   *
 *************************************************************/

int crypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	
	int counter = 0;
	
	int t=0;

	int i=5;	

	char character;

	while(fscanf(f_in_ptr,"%c",&character)!= EOF)
	{	

		if(character=='1')
		{
			fprintf(f_out_ptr,"*");
		}

		else if(character=='0')
		{
			fprintf(f_out_ptr,"_");
		}

		counter++;

		t++;

		if(t==i)
		{
			fprintf(f_out_ptr,"-");
			
			i--;
	
			t=0;
	
			if(i<1)
			{
				i=5;
			}
		}	
		
	}

	return counter;
}
