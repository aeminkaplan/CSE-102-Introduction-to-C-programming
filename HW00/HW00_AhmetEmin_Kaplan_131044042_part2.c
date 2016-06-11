/*############################################################################*/
/*HW00_AhmetEmin_Kaplan_131044042.c                                           */
/*__________________________________                                          */
/*Written by Ahmet Emin Kaplan on February 15, 2015                           */
/*                                                                            */
/*Description                                                                 */
/*___________                                                                 */
/*Takes multiplication of the pair of second degree polynomials               */
/*Inputs:                                                                     */
/*  -Coefficients of the first 2nd degree polynomial                          */
/*  -Coefficients of other 2nd degree polynomial                              */
/*Outputs:                                                                    */
/*  -Multiplication of the pair of 2nd degree polynomials                     */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                          Includes                                          */
/*----------------------------------------------------------------------------*/
#include <stdio.h>


int main()
{
	double f1,f2,f3;        /*Coefficients of the first poly*/
	double s1,s2,s3;         /*Coefficients of the second poly*/
	double r1,r2,r3,r4,r5;  /*Coefficients of the resulting poly*/


    /*Get the first polynomial*/
	printf("Please Enter coefficients of the first 2nd degree polynomial.\n");
	scanf("%lf %lf %lf",&f1,&f2,&f3);
    /*Show the first polynomial the user entered*/	
	printf("The first polynomial which was entered by you is\n");
	printf("(%f)x^2 + (%f)x + (%f)\n",f1,f2,f3);

    /*Get the second polynomial*/
	printf("Please Enter coefficients of the other 2nd degree polynomial.\n");
	scanf("%lf %lf %lf",&s1,&s2,&s3);
     
    /*Show the second polynomial the user entered*/
	printf("The second polynomial which was entered by you is\n");
	printf("(%f)x^2 + (%f)x + (%f)\n",s1,s2,s3);
	
	
	r1 = (f1*s1);	 /*Calculate the coefficient of x^4 */
	r2 = (f1*s2) + (f2*s1); /*Calculate the coefficient of x^3 */
	r3 = (f1*s3) + (f3*s1) + (f2*s2); /*Calculate the coefficient of x^2 */
	r4 = (f2*s3) + (f3*s2);   /*Calculate the coefficient of x */
	r5 = (f3*s3);  /*Calculate the p(0) degree*/

    /*Output the resulting polynomial*/ 
	printf("The Resulting polynomial>\n");
	printf("(%f)x^4 + (%f)x^3 + (%f)x^2 + (%f)x + (%f)\n",r1,r2,r3,r4,r5);


 	return(0);
}




/*----------------------------------------------------------------------------*/
/*             End of HW00_AhmetEmin_Kaplan_131044042_part2.c                 */
/*----------------------------------------------------------------------------*/
