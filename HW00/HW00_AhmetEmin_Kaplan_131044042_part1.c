/*############################################################################*/
/*HW00_AhmetEmin_Kaplan_131044042_part1.c                                     */
/*__________________________________                                          */
/*Written by Ahmet Emin Kaplan on February 14, 2015                           */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/*Takes the integral of a given 1st degree polynomial                         */
/*Inputs:                                                                     */
/*  -Coefficients of the 1st degree polynomial                                */
/*  -Zero input value of the resulting polynomial                             */
/*Outputs:                                                                    */
/*  -Resulting 2nd degree polynomial                                          */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                          Includes                                          */
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#define CORRECTION_FOR_COEFFICIENT 0.5


int main()
{
	double ia0,ia1;            /*Coefficients of the input poly*/
	double p0;                 /*P(0) value of the resulting poly*/
	double ra1,ra2;        /*Coefficients of the resulting poly*/
	
	/*Get the 1st degree input polynomial*/
	printf("Enter the coefficients of the polynomial (higher to lower order)>");
	scanf("%lf%lf",&ia1,&ia0);
	printf("Your input polynomial is\n%fx + (%f) .\n",ia1,ia0);

	/*Get the zero input value of the resulting poly*/
	printf("Enter p(0) value for the resulting polynomial>");
	scanf("%lf",&p0);
	
	/*Calculate the resulting poly*/
	ra1 = ia0;
	ra2 = ia1*CORRECTION_FOR_COEFFICIENT;
	
	/*Output the resulting poly*/
	printf("The resulting polinomial is\n");
	printf("%5.3fx^2 + (%5.3f)x + (%5.3f) .\n",ra2,ra1,p0);
		
 	return(0);
}

/*############################################################################*/
/*              End of HW00_AhmetEmin_Kaplan_131044042_part1.c                */
/*############################################################################*/
