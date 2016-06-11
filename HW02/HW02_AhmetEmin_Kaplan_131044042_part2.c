/*############################################################################*/
/*HW02_AhmetEmin_Kaplan_131044042_part2.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Ahmet Emin Kaplan on March 1, 2015                               */
/*                                                                            */
/*Description                                                                 */
/*__________                                                                  */
/*Calculates grades,letter grades and contributions of subject for 5 students */
/*                                                                            */
/*Inputs:                                                                     */
/* -2 initials (student name and surname ) for each student                   */
/* -First midterm score,second midterm score,final exam score for each student*/
/*                                                                            */
/*Outputs:                                                                    */ 
/* -2 initials (student name and surname ) for each student                   */
/* -Grades and contributions for each student                                 */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/



#include<stdio.h>  /*Including stdio library to use input output functions*/
#define PERCENTAGE1 0.3
#define PERCENTAGE2 0.3
#define PERCENTAGE3 0.4

/*Prototypes of functions the program uses*/

int ResultingGrade(int x,int y,int z); 
char LetterGrade(int x);
double Contribution(char x);



int main()

{	
	/*Defining character variables for initials*/

	char Name1,Name2,Name3,Name4,Name5; 
	char Surname1,Surname2,Surname3,Surname4,Surname5;

	/*Defining integer variables for exam scores*/

	int Midterm1_ST1,Midterm1_ST2,Midterm1_ST3,Midterm1_ST4,Midterm1_ST5;
	int Midterm2_ST1,Midterm2_ST2,Midterm2_ST3,Midterm2_ST4,Midterm2_ST5;
	int Final_ST1,Final_ST2,Final_ST3,Final_ST4,Final_ST5;

	/*Defining integer variables for resulting grades*/

	int Grade_ST1,Grade_ST2,Grade_ST3,Grade_ST4,Grade_ST5;
	
	/*Defining character variables for letter grades*/	
	
	char LetterGrade1,LetterGrade2,LetterGrade3,LetterGrade4,LetterGrade5;
	
	/*Defining double variables for resulting grade contribution to GPA*/

	double Contribution_1,Contribution_2,Contribution_3;
	double Contribution_4,Contribution_5;	
	
	/*Defining file variables*/

	FILE*input;	
	FILE*output;
	
	/*Opening input file in reading mode*/
	
	input=fopen("Students.txt","r"); 
	output=fopen("Grades.txt","w");

	/*Catching values from input file*/
	
	fscanf(input,"%c%c %d %d %d \n",&Name1,&Surname1,&Midterm1_ST1,&Midterm2_ST1,&Final_ST1);
	fscanf(input,"%c%c %d %d %d \n",&Name2,&Surname2,&Midterm1_ST2,&Midterm2_ST2,&Final_ST2);
	fscanf(input,"%c%c %d %d %d \n",&Name3,&Surname3,&Midterm1_ST3,&Midterm2_ST3,&Final_ST3);
	fscanf(input,"%c%c %d %d %d \n",&Name4,&Surname4,&Midterm1_ST4,&Midterm2_ST4,&Final_ST4);
	fscanf(input,"%c%c %d %d %d \n",&Name5,&Surname5,&Midterm1_ST5,&Midterm2_ST5,&Final_ST5);

	/*To assign grades with using Resulting grade function*/

	Grade_ST1=ResultingGrade(Midterm1_ST1,Midterm2_ST1,Final_ST1);	
	Grade_ST2=ResultingGrade(Midterm1_ST2,Midterm2_ST2,Final_ST2);	
	Grade_ST3=ResultingGrade(Midterm1_ST3,Midterm2_ST3,Final_ST3);	
	Grade_ST4=ResultingGrade(Midterm1_ST4,Midterm2_ST4,Final_ST4);	
	Grade_ST5=ResultingGrade(Midterm1_ST5,Midterm2_ST5,Final_ST5);	
	
	/*To assign letter grades with using LetterGrade function*/

	LetterGrade1=LetterGrade(Grade_ST1);
	LetterGrade2=LetterGrade(Grade_ST2);
	LetterGrade3=LetterGrade(Grade_ST3);
	LetterGrade4=LetterGrade(Grade_ST4);	
	LetterGrade5=LetterGrade(Grade_ST5);

	/*To assign Contributions with using Contribution function */

	Contribution_1=Contribution(LetterGrade1);
	Contribution_2=Contribution(LetterGrade2);
	Contribution_3=Contribution(LetterGrade3);
	Contribution_4=Contribution(LetterGrade4);
	Contribution_5=Contribution(LetterGrade5);

	/*To Print initials and grade to output file */

	fprintf(output,"%c%c %d \n",Name1,Surname1,Grade_ST1);
	fprintf(output,"%c%c %d \n",Name2,Surname2,Grade_ST2);
	fprintf(output,"%c%c %d \n",Name3,Surname3,Grade_ST3);
	fprintf(output,"%c%c %d \n",Name4,Surname4,Grade_ST4);
	fprintf(output,"%c%c %d \n",Name5,Surname5,Grade_ST5);


	/*Showing contributions on the screen*/
	
	printf("The contribution of %c%c is %f\n",Name1,Surname1,Contribution_1);
	printf("The contribution of %c%c is %f\n",Name2,Surname2,Contribution_2);
	printf("The contribution of %c%c is %f\n",Name3,Surname3,Contribution_3);
	printf("The contribution of %c%c is %f\n",Name4,Surname4,Contribution_4);
	printf("The contribution of %c%c is %f\n",Name5,Surname5,Contribution_5);
	
	/*Closing input and output files*/

	fclose(input);
	fclose(output);

	return 0;

	
}

/*This function calculates grades and returns grades as integer*/

int ResultingGrade(int x,int y,int z)  

{	int temp;
	temp=(PERCENTAGE1*x)+(PERCENTAGE2*y)+(PERCENTAGE3*z);
	return temp;
}

/*This function calculates letter grades and returns letter grades as char*/
char LetterGrade(int x)

{	char temp; /*Defining temporary variable as char*/

	if(x>=85)       /*If grades is 85 or more , Function assign 'A' to temp*/
		temp='A';
	
	if(x>=70 && x<85)     /*If grades is 70 or more and less 
					       than 85,Function assigns 'B' to temp*/
		temp='B';
	
	if(x>=65 && x<70)     /*If grades is 65 or more and less 
					       than 70,Function assigns 'C' to temp*/
		temp='C';
	
	if(x>=40 && x<65)    /*If grades is 40 or more and less 
					       than 65,Function assigns 'C' to temp*/
		temp='D';
	
	if(x<=39)           /*If grades is 39 or less,Function assign 'B' to temp*/
		temp='F';
	return temp;
}

/*This function calculates contributions and returns double */
double Contribution(char x)

{	int temp;
	double average;
	switch(x)
	{
		case 'A' : temp=4;  /*If letter grade is A,Switch assigns 4 to temp*/
			break;
		case 'B' : temp=3;  /*If letter grade is B,Switch assigns 3 to temp*/
			break;
		case 'C' : temp=2;  /*If letter grade is C,Switch assigns 2 to temp*/
			break;
		case 'D' : temp=1;  /*If letter grade is D,Switch assigns 1 to temp*/
			break;
		case 'F' : temp=0;  /*If letter grade is F,Switch assigns 0 to temp*/
			break;
	}	
	
	average=(temp*3.0)/20.0;  /*Contribution is being calculated  */
	return average;   /*Average value is returned as double*/


}



/*############################################################################*/
/*            End of HW02_AhmetEmin_Kaplan_131044042_part2.c                  */
/*############################################################################*/
