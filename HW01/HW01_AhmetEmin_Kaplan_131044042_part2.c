/*############################################################################*/
/*HW01_AhmetEmin_Kaplan_131044042_part2.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Ahmet Emin Kaplan on February 22, 2015                           */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/*Finds x and y with using 2 linear equations with two unknowns and f(x,y)    */
/*Inputs:                                                                     */
/* -Coefficients of linear equations                                          */
/* -Coefficients of function f(x,y)                                           */
/* -Results of linear equations                                               */
/*Outputs:                                                                    */ 
/* -Values of x and y and the result of f(x,y)                                */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

#include<stdio.h>
#include<math.h>


double f(double x,double y);  /*The prototype of function f(x,y)*/
int main()
{
	FILE*input;
	FILE*output;
	/*Opening input file with readind mode*/	
	input=fopen("EqCoefficients.txt","r"); 
	/*Opening output file with writing mode*/
	output=fopen("Results2.txt","w");
	
	/*Defining Variables for coefficients of equations and results*/
	double coX1,coY1,R1,coX2,coY2,R2,g,x,y;
	
	/*Catching values of coefficients and results from input file*/
	fscanf(input,"%lf %lf %lf %lf %lf %lf",&coX1,&coY1,&R1,&coX2,&coY2,&R2);
	printf("First Linear Equation is:(%f)x + (%f)y = %f \n", coX1,coY1,R1);
	printf("Second Linear Equation is:(%f)x + (%f)y = %f \n",coX2,coY2,R2);
	
	/*To find variable y with elimination method*/	
	y = ((coX1*R2)-(coX2*R1))/ ((coX1*coY2)-(coY1*coX2));

	/*To find variable x with using y and first equation */	
	x = (R1 - (coY1*y))/ coX1 ;
	
	/*To Assign f(x,y) to variable g */
	g = f(x,y); 

	/*Printing values of x and y and f(x,y) on console */	
	printf("x:%f y:%f f(x,y):%f\n",x,y,g);

	/*Writing values of x and y and the result of the f(x,y) to output file*/
	fprintf(output,"%f %f %f",x,y,g);
	

	fclose(input);	/*Closing input and output files*/
	fclose(output);

	
	return 0;

}


double f(double x,double y) /*Defining what the function f makes*/
{	
	FILE*input;
	
	/*Opening input file with reading mode*/
	input=fopen("FunCoefficients.txt","r");
	
	/*Defining variables for function f(x,y)*/
	double k,m,temp;

	/*Catching coefficients of x and y parameters from input file*/	
	fscanf(input,"%lf %lf",&k,&m);	

	/*Evaluates the result of function f and assign to temporary variable*/	
	temp= (k*x) + (m*y);	
	
	fclose(input);  /*Closing the input file*/
	return temp;

}



/*############################################################################*/
/*            End of HW01_AhmetEmin_Kaplan_131044042_part2.c                  */
/*############################################################################*/
