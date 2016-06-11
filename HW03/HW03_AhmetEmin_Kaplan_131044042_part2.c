/*############################################################################*/
/*HW03_AhmetEmin_Kaplan_131044042_part2.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Ahmet Emin Kaplan on March 9, 2015                               */
/*                                                                            */
/*Description                                                                 */
/*__________                                                                  */
/*Calculates vertical distance of bouncing ball                               */
/*                                                                            */
/*Inputs:                                                                     */
/* -                                                                          */
/*Outputs:                                                                    */ 
/* -Number of bouncing                                                        */
/* -Total vertical distance of bouncing ball                                  */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/



#include<stdio.h>
                          /*Including libraries to use private functions*/
#include<stdlib.h>

#define LIMIT 1.0     /*To define limit as a constant macro*/

                     /*Prototypes*/

double calculate_the_new_height(double first_height,double ratio);

double calculate_the_vertical_distance(double next_height);

void report(double first_height,double ratio);

int RNG_for_first_height();

double RNG_for_ratio();


int main()
{                   /*Begining of Main*/

	double first_height;    /*Defining variables*/

	double vertical_distance;

	double ratio;

	double next_height;

	int counter;
                               /*Assignment first height randomly value*/
	first_height=(double)RNG_for_first_height();
                               
                              /*Assignment ratio randomly value*/
	ratio=RNG_for_ratio();
                                 /*Vertical distance equal to first height in first step*/
	vertical_distance=first_height;	
                                /*To show ratio on screen*/
	printf("Ratio:%.2f\n",ratio);

	counter=1;                 /*Counting number of bouncing*/
	
	printf("%d\t",counter);   /*First step is not usual to calculate so Its not in a loop*/

	printf("%7.3f\t",first_height);

	printf("%7.3f\n",vertical_distance);
	

	next_height=first_height*ratio;     /*Calculate next height*/ 
	
	while(next_height>=LIMIT)
	{	 /*As soon as the next height pass over the limit,The loop works*/        
		                     
		counter=count_the_number(counter); /*Increase the counter with function*/

        /*To show results on the screen*/
		
		printf("%d\t",counter); 

		printf("%7.3f\t",next_height);
		
		/*To update vertical distance with function */
		
		vertical_distance += calculate_the_vertical_distance(next_height);

		printf("%7.3f\n",vertical_distance);

		/*To update next height with function*/

		next_height=calculate_the_new_height(next_height,ratio);

	}
     
	/* Printing results to file with report function */
	
	report(first_height,ratio);
	return 0;

}



double calculate_the_new_height(double first_height,double ratio)
{
		/*Function calculates the new height*/
	
	double next_height;
	next_height=first_height*ratio;
	return next_height;

}

double calculate_the_vertical_distance(double next_height)
{ 
	/*Function calculates vertical_distance*/
	
	double vertical_distance=0;

	vertical_distance=(2*next_height);

	return vertical_distance;


}

int count_the_number(int counter)
{   /*Function counts number of bouncing*/
	counter++;

	return counter;

}

void report(double first_height,double ratio)

{                /*Function uses first height and ratio as parameters*/    
                  /*Opening output file with writing mode*/ 
	FILE*output;

	output=fopen("Result_table.txt","w");
	
	/*To define variables*/

	double vertical_distance;

	double next_height;

	int counter;

	vertical_distance=first_height;	 /*Vertical distance equal to first height in first step*/

	fprintf(output,"NO - The Rebouncing Height -- The Total Vertical Distance\n");

	counter=1;
                      /*First step is not usual to calculate so Its not in a loop*/
	fprintf(output,"%d\t\t",counter);

	fprintf(output,"%7.3f\t\t\t\t\t",first_height);

	fprintf(output,"%7.3f\n",vertical_distance);
	

	next_height=first_height*ratio; /*To Calculate next height*/
	
	while(next_height>=LIMIT) 
	{	
		 /*As soon as the next height pass over the limit,The loop works*/ 

		counter=count_the_number(counter);   /*Increase the counter with function*/

			/*To print results to file*/
	
		fprintf(output,"%d\t\t",counter);

		fprintf(output,"%7.3f\t\t\t\t\t",next_height);
          
            /*To update vertical distance*/
		
		vertical_distance += calculate_the_vertical_distance(next_height);

		fprintf(output,"%7.3f\n",vertical_distance);
              
             /*To update next height*/
		next_height=calculate_the_new_height(next_height,ratio);
	}
	
	fprintf(output,"The bounce is stopped and the task completed...");

	fclose(output);       /*Closing file*/
}

int RNG_for_first_height()
{              /*To generate random value for first height*/

	int first_height;

	srand(time(NULL));

	first_height=(rand()%31)+10;

	return first_height;
	
}

double RNG_for_ratio()
{
                        /*To generate random value for ratio*/
	double ratio;

	srand(time(NULL));

	ratio=((rand()%41)+40.0)/100;

	return ratio;
}


/*############################################################################*/
/*             End of HW03_AhmetEmin_Kaplan_131044042_part2.c                 */
/*############################################################################*/
