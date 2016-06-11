/*############################################################################*/
/*HW01_AhmetEmin_Kaplan_131044042_part3.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Ahmet Emin Kaplan on February 22, 2015                           */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/*Finds the total fuel costs of 3 Cars                                        */
/*Inputs:                                                                     */
/* -Amount(lt) of fuel consumed per KM for each car                           */
/* -Price of fuel(1lt) for each car                                           */
/* -Total KM's taken by cars                                                  */
/*Outputs:                                                                    */ 
/* -Total fuel cost for each car                                              */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>


int main()
{	
	FILE*input;
	FILE*output;
	
	/*Opening input file with reading mode*/	
	input=fopen("Cars.txt","r");

	/*Opening output file with writing mode*/	
	output=fopen("TotalFuelCosts.txt","w");

	/*Defining CarNumbers and Variables for assignment*/	
	int CarNumber1,CarNumber2,CarNumber3,a,b,c,d,e,f;

	/*Defining Prices of Fuel variables for Cars*/	
	double PriceOfFuel1,PriceOfFuel2,PriceOfFuel3;

	/*Defining variables to using for informations*/
	double AmountOfFuelConsumedPerKM1,AmountOfFuelConsumedPerKM2;
	double AmountOfFuelConsumedPerKM3;
	double TotalKmTakenByCar1,TotalKmTakenByCar2,TotalKmTakenByCar3;
	double TotalCostForCar1,TotalCostForCar2,TotalCostForCar3;
	

	/*Catching data's from input file for first car*/
	fscanf(input,"%d",&CarNumber1);
	fscanf(input,"%lf",&PriceOfFuel1);
	fscanf(input,"%lf",&AmountOfFuelConsumedPerKM1);
	fscanf(input,"%lf",&TotalKmTakenByCar1);

	/*Catching data's from input file for second car*/
	fscanf(input,"%d",&CarNumber2);
	fscanf(input,"%lf",&PriceOfFuel2);
	fscanf(input,"%lf",&AmountOfFuelConsumedPerKM2);
	fscanf(input,"%lf",&TotalKmTakenByCar2);

	/*Catching data's from input file for third car */
	fscanf(input,"%d",&CarNumber3);
	fscanf(input,"%lf",&PriceOfFuel3);
	fscanf(input,"%lf",&AmountOfFuelConsumedPerKM3);
	fscanf(input,"%lf",&TotalKmTakenByCar3);
	/*Evaluate Total costs for each car*/
	TotalCostForCar1=PriceOfFuel1*AmountOfFuelConsumedPerKM1*TotalKmTakenByCar1;
	TotalCostForCar2=PriceOfFuel2*AmountOfFuelConsumedPerKM2*TotalKmTakenByCar2;
	TotalCostForCar3=PriceOfFuel3*AmountOfFuelConsumedPerKM3*TotalKmTakenByCar3;
	/*Writing results to output file*/
	fprintf(output,"%d %0.2f\n",CarNumber1,TotalCostForCar1);
	fprintf(output,"%d %0.2f\n",CarNumber2,TotalCostForCar2);
	fprintf(output,"%d %0.2f\n",CarNumber3,TotalCostForCar3);

	/*To make results integer*/
	a=(int)TotalCostForCar1;
	b=(int)TotalCostForCar2;
	c=(int)TotalCostForCar3;
	
	/*To make remainders integer with using fmod() function*/
	d=(int)(fmod(TotalCostForCar1,1.0)*100);
	e=(int)(fmod(TotalCostForCar2,1.0)*100);
	f=(int)(fmod(TotalCostForCar3,1.0)*100);

	/*Writing results on console(Liras and Kurus divorced)*/
	printf("The total fuel cost of the car 1 is %d TL and %d  Kurus.\n",a,d);
	printf("The total fuel cost of the car 2 is %d TL and %d  Kurus.\n",b,e);
	printf("The total fuel cost of the car 3 is %d TL and %d  Kurus.\n",c,f);
	
	
	 /*Closing files*/
	fclose(input);  
	fclose(output);
	return 0;

}

/* #NOTE#
  Between the outputs there are maybe little bit differences.%0.2f operator
rounds off remainders but we find Liras and Kurus divorced without to round off
I could fix with catching rounded off values from output file but I thought
It wasnt unnecessery */

/*############################################################################*/
/*           End of HW01_AhmetEmin_Kaplan_131044042_part3.c                   */
/*############################################################################*/


