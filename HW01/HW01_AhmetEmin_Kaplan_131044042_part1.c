/*############################################################################*/
/*HW01_AhmetEmin_Kaplan_131044042_part1.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Ahmet Emin Kaplan on February 22, 2015                           */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/*Evaluates the resultant of given functions ( g(f(x)) and f(g(x)) )          */
/*Inputs:                                                                     */
/* -Value of variable X                                                       */
/* -Y is constant macro                                                       */
/*Outputs:                                                                    */ 
/* -The Value of gof(x) and fog(x)                                            */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>
#define Y 8.0  /*Defining Y as a constant macro*/

double f(double x); /*The prototype of function f(x)*/
double g(double x); /*The prototype of function g(x)*/

int main()
{	
	FILE*input;
	FILE*output;
	input=fopen("Variables.txt","r"); /*Opening input file with reading mode*/
	output=fopen("Results1.txt","w"); /*Opening output file with writing mode*/

	double x,a,b;  /*Defining variables to use for assignments*/
	fscanf(input,"%lf",&x);   /*Catching the Value of X from the input file*/
	
	a=g(f(x)); /*The assignment for value of gof(x)*/
	b=f(g(x)); /*The assignment for value of fog(x)*/

    /*To show the results on console*/
	printf("GoF(%f)=%f \nFoG(%f)=%f \n",x,a,x,b); 
	fprintf(output,"%f   %f",a,b);  /*To write results to output file*/
	

	fclose(input);  /*Closing input file*/
	fclose(output);  /*Closing output file*/

	
	return 0;
}



double f(double x)  /*Defining the instructions of f(x) function*/ 
{
	double temp;	/*Defining Temporary variable for the result of process*/
	/*This function makes a lot of arithmetic operation*/	
	temp=sin(pow(((x+Y)/x)+pow(log10(pow(3,x)/(2*x+1)),0.5),2.5));
	
	return temp;

}


double g(double x) /*Defining the instructions of g(x) function*/
{	
	double temp2;	/*Defining Temporary variable for the result of process*/
	/*This function makes instructions which was defined*/	
	temp2 = x+pow(x+(Y/(2*x)),-1); 
	return temp2;

}


/*############################################################################*/
/*              End of HW01_AhmetEmin_Kaplan_131044042_part1.c                */
/*############################################################################*/

