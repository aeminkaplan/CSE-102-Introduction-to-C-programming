/*############################################################################*/
/*HW03_AhmetEmin_Kaplan_131044042_part1.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Ahmet Emin Kaplan on March 9, 2015                               */
/*                                                                            */
/*Description                                                                 */
/*__________                                                                  */
/*Its a guessing game                                                         */
/*Gives infinite chances to find the randomly chosen number between 1-10      */
/*                                                                            */
/*Inputs:                                                                     */
/* -Choice to play or exit                                                    */
/* -Infinite prediction chances until find the number                         */
/*Outputs:                                                                    */ 
/* -Warning messages about users predictions                                  */
/* -Number of guesses                                                         */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/



#include<stdio.h>   /*Including libraries to use private functions*/

#include<stdlib.h>

#include<math.h>

int WarnThePlayer();           /*Prototypes of functions*/

int RNG();

int CalculateTheDifference(int x,int y);


int main()                   /*Begining of Main*/
{	
	char choice;   /*Define choice variable as a char*/

	
	
	printf("To Play game press 'P' or 'p' and To Exit press 'E' or 'e'\n");

	scanf("%c",&choice);        /*Get choice from user*/

	while(choice!='E' && choice!='e')    /*If choice 'e' or 'E' , program ends*/

	{

	if(choice=='P' || choice=='p')    /*If choice 'p' or 'P' , game starts */

		{	

		WarnThePlayer();  /*After the game,program asks again the users choice*/

		printf("To Play game press 'P' or 'p' and To Exit press 'E' or 'e'\n");

		scanf(" %c",&choice);

		}
	
	else{         /*Else the program warns the user and asks again*/

		printf("You pressed wrong button\n");

		printf("To Play game press 'P' or 'p' and To Exit press 'E' or 'e'\n");

		scanf(" %c",&choice);	

		}	

	}

	printf("The Program was ended.\n");

	return 0;
	
}


int WarnThePlayer()      /*Game function*/

{   

	int guess;	

	int number;            /*To define variables as integer*/

	int counter=0;          /*Variable for counting number of guesses*/

	number=RNG();             /*Get random number with RNG() function*/
	
	while(1)   /*Everytime this loop continues*/
	{	

		printf("Enter your prediction");	

		scanf(" %d",&guess);          /*To get user prediction*/

	 	counter=counter+1;            /*Counting predictions*/
	

		if(CalculateTheDifference(number,guess)>=5)	

			printf("You are too far from the number!\n");

		else if(CalculateTheDifference(number,guess)>=3 && CalculateTheDifference(number,guess)<5)

			printf("You are far from the number!\n");

		else if(CalculateTheDifference(number,guess)<=2 && CalculateTheDifference(number,guess)>0)

			printf("You are close to number!\n");

		else if(CalculateTheDifference(number,guess)==0)

			{		

			printf("###Congratulation! You found the number! The number of guesses:%d ###\n\n\n",counter);

			return 0;

			}
	
	}
}       /*When the number is found,Loop ends and number of guesses is shown*/

	
/*Absolute function to calculate the difference between prediction and number*/

int CalculateTheDifference(int number,int guess) 
{	

	int temp;

	temp=abs(number-guess);

	return temp;
}

int RNG()    /*To generate random number between 1-10*/
{

	int number;

	srand(time(NULL));

	number=(rand()%10)+1;

	return number;
}




/*############################################################################*/
/*            End of HW03_AhmetEmin_Kaplan_131044042_part1.c                  */
/*############################################################################*/

