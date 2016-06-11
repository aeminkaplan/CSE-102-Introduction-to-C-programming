/*############################################################################*/
/*HW02_AhmetEmin_Kaplan_131044042_part1.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Ahmet Emin Kaplan on March 1, 2015                               */
/*                                                                            */
/*Description                                                                 */
/*__________                                                                  */
/*Its a guessing game                                                         */
/*Gives two chances to find the randomly chosen number which is between 1-10  */
/*                                                                            */
/*Inputs:                                                                     */
/* -First prediction                                                          */
/* -Second prediction (if the first one false )                               */
/*                                                                            */
/*Outputs:                                                                    */ 
/* -Warning messages about users predictions                                  */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

#include<stdio.h>   /*Including stdi/o library to use input output functions*/
#include<stdlib.h> /*Including std library to use rand() function */
#include<math.h>    /*Including math library to use abs() function */

int RNG();            /*Prototypes of functions which are used by program*/
int CalculateTheDifference(int x,int y);
void WarnThePlayer(int x,int y);

int main()
{
	int number; /*Defining variable prediction and random number as integer*/
	int guess;

	number=RNG();   /*Assignment for random number*/
	
	/*To show begining of the game on the screen*/
	printf("\n\n\n###Welcome to Guessing Game### !\nPlease Try your chance.>");
	
	/*Catching prediction from user*/	
	scanf("%d",&guess);
	
	/*Calling the warning function about prediction and random chosen number*/
	WarnThePlayer(guess,number);
	
	/*If number isnt found ,Game will give second chance to user*/
	if(CalculateTheDifference(guess,number)!=0)
	
	{
	/*To Warn user to use second chance*/
	printf("You have only one chance ! Try Again>");	
	
	/*Catching second prediction from user*/
	scanf("%d",&guess);
	
	/*Calling the warning function again*/	
	WarnThePlayer(guess,number);
	}
	
	/*If number isnt found,Game will be ended and the number will be showed*/	
	if(CalculateTheDifference(guess,number)!=0)
		printf("###Game Over!### The number was %d. \n\n\n",number);	
	

	return 0;

}


int RNG()    /*To Define Random number generate function*/
{
	int number;          /*Define variable for random number*/
	srand(time(NULL));   /*This function uses system time to get random number*/
	number=(rand()%10)+1; /*To set the gap between 1-10 */
	return number;     /*Function returns our random number*/
}


int CalculateTheDifference(int x,int y) /*To Define the difference function*/
{
	 /*Define temporary variable for difference */
	int temp;   
	
	/*Calculate difference with using absolute function*/
	temp=abs(x-y); 

	/*Function returns difference between prediction and random number*/
	return temp; 
}


void WarnThePlayer(int x, int y) /*Define warning function*/

{    
	/*This function warns the user in order to guide */

	
	if(CalculateTheDifference(x,y)>=5)

	/*If the difference between prediction and random number is 5 or more,
      Function prints this sentence*/	

		printf("You are too far from the number!\n");

	else if(CalculateTheDifference(x,y)>=3 && CalculateTheDifference(x,y)<5)
	
	/*If the difference between prediction and random number is 3 or more,
      Function prints this sentence*/

		printf("You are far from the number!\n");

	else if(CalculateTheDifference(x,y)<=2 && CalculateTheDifference(x,y)>0)

	/*If the difference between prediction and random number is 2 or less,
      Function prints this sentence*/	

		printf("You are close to number!\n");

	else if(CalculateTheDifference(x,y)==0)

    /*If the difference between prediction and random number is 0 ,
      Function prints this sentence*/

		printf("###Congratulation! You found the number!###\n\n\n");

}

/*############################################################################*/
/*              End of HW02_AhmetEmin_Kaplan_131044042_part1.c                */
/*############################################################################*/

