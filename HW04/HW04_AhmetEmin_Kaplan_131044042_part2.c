/*************************************************************
 *                                                           *
 * HW04 Q2                                                   *
 * Student Name: Ahmet Emin KAPLAN                           *
 * Student ID  : 131044042                                   *
 * Date        : 16.03.2015                                  *
 * Points      : 30                                          *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define PLAINTEXTFILE "HW04_AhmetEmin_Kaplan_131044042_ReceivedMessage.txt"
#define ENCODEDFILE "HW04_AhmetEmin_Kaplan_131044042_EncodedInput.txt"
#define CRYPTEDINPUT "CryptedInput.txt"

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/
void decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/
int decode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/
int decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Reads encrypted text and creates encoded and              *
 * plain text files                                          *
 *************************************************************/



int main(int argc, char* argv[])
{
	FILE *f_plain_ptr, *f_encoded_ptr, *f_crypted_ptr;
	
	f_crypted_ptr=fopen(CRYPTEDINPUT,"r");

	f_encoded_ptr=fopen(ENCODEDFILE,"w");
	
	
	/* exit program and print error if encrypted text file could not be opened to read */

	if(f_crypted_ptr==NULL)
	
	{
		printf("Error! CryptedText file could not be opened !\n");
		
		return 0;		
	}

	/* exit program and print error if encoded text file could not be opened to write */
	
	if(f_encoded_ptr==NULL)
	{
		printf("Error! EncodedText file could not be opened !\n");
		
		return 0;		
	}
	
	decrypt_message(f_crypted_ptr, f_encoded_ptr);

	/* close encrypted and encoded files */

	fclose(f_crypted_ptr);

	fclose(f_encoded_ptr);

	f_encoded_ptr=fopen(ENCODEDFILE,"r");
	
	f_plain_ptr=fopen(PLAINTEXTFILE,"w");	

	if(f_encoded_ptr==NULL)
	{
		
		printf("Error! EncodedText file could not be opened !\n");
		
		return 0;		
	}
	
/* exit program and print error if plain text file could not be opened to write */

	if(f_encoded_ptr==NULL)
	{
		
		printf("Error! EncodedText file could not be opened !\n");
		
		return 0;		
	}



	decode_message(f_encoded_ptr, f_plain_ptr);

	/* close encoded and plain files */

	fclose(f_encoded_ptr);

	fclose(f_plain_ptr);


	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/

void decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones)
{
	switch(number_of_ones)
	{
		case 0:fprintf(f_out_ptr,"E");
		break;
		case 1:fprintf(f_out_ptr,"I");
		break;
		case 2:fprintf(f_out_ptr," ");
		break;
		case 3:fprintf(f_out_ptr,"T");
		break;
		case 4:fprintf(f_out_ptr,"C");
		break;
		case 5:fprintf(f_out_ptr,"N");
		break;
		case 6:fprintf(f_out_ptr,"A");
		break;
		case 7:fprintf(f_out_ptr,"G");
		break;
		case 8:fprintf(f_out_ptr,"B");
		break;
		case 9:fprintf(f_out_ptr,"Z");
		break;
		case 10:fprintf(f_out_ptr,"H");
		break;
		case 11:fprintf(f_out_ptr,"L");
		break;
		case 12:fprintf(f_out_ptr,"U");
		break;
		case 13:fprintf(f_out_ptr,"V");
		break;
		case 14:fprintf(f_out_ptr,"R");
		break;
		case 15:fprintf(f_out_ptr,"S");
		break;
		case 16:fprintf(f_out_ptr,"Y");
		break;

	}	
	
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/

int decode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{	
	
	int counter=0;
	char character;

	while(fscanf(f_in_ptr,"%c",&character)!=EOF)
		{	
			if(character=='1')
			{
				counter++;
			}

			else if(character=='0')
			{

				decode_and_write_to_file(f_out_ptr,counter);counter=0;
			}			

		}
	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/

int decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{

	char character;

	int counter = 0;

	while(fscanf(f_in_ptr,"%c",&character)!=EOF)
	{
		if(character=='*')
		{
			fprintf(f_out_ptr,"1");
		}
		
		else if(character=='_')
		{
			fprintf(f_out_ptr,"0");
		}
		
		counter++;
	}	
	
	
	return counter;
}
