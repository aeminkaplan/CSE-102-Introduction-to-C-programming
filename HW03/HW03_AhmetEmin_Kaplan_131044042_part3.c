/*############################################################################*/
/*HW03_AhmetEmin_Kaplan_131044042_part3.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Written by Ahmet Emin Kaplan on March 9, 2015                               */
/*                                                                            */
/*Description                                                                 */
/*__________                                                                  */
/*Draws vertical diagram of bouncing ball                                     */
/*                                                                            */
/*Inputs:                                                                     */
/* -The first height of the ball                                              */
/* -The height of one feet                                                    */
/* -The character used to draw peak points of the ball                        */
/* -The character used to draw path points of the ball                        */
/*Outputs:                                                                    */ 
/* -Drawing of vertical diagram of bouncing ball                              */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/








#include<stdio.h>

int draw_diag_step(int first_height,int feet_height,char the_peak_point,char the_path_point);

int draw_diag_of_bb(int first_height,int feet_height,char the_peak_point,char the_path_point);

int finish_diag(int length);

int main()

{	int counter1,counter2,counter3;

	
	counter1=draw_diag_of_bb(3,4,'a','c');
	printf("Returns:%d\n",counter1);


	counter2=draw_diag_of_bb(5,2,'D','-');
	printf("Returns:%d\n",counter2);


	counter3=draw_diag_of_bb(6,3,'>','#');
	printf("Returns:%d\n",counter3);
	


	return 0;

}



int draw_diag_step(int first_height,int feet_height,char the_peak_point,char the_path_point)
{
	/*To define counters to set required quantities and counting characters*/

	int counter=0;
	int i=0;
	int j=0;
	int k=0;
	int z=0;
	int t;
	int m=0;
	int n=0;
	int p=0;

	t=feet_height;
                     /*This loop is for top part of diagram*/
                        /*This loop makes lines as much as first heigh*/

	for(i=0;i<first_height;i++)

	{
                             /*Each lines need "|" character for begining*/
		printf("|");
                                 
		for(k=0;k<t-feet_height;k++){printf(" ");}
/*Firstly this loop prints 0 space but in second line it prints 4 space and 4 again*/
		t=t+feet_height;

		for(j=0;j<feet_height;j++) {printf("%c",the_path_point);counter++;}
        /*This loop prints path point as much as feet height*/

		printf("\n");

	}

	for(n=0;n<1;n++)   /*This loop prints spaces for peak point*/

	{	
		printf("|");    

       /*Firstly it prints spaces as much as multiplication of first height and feet height*/

		for(p=0;p<first_height*feet_height;p++){printf(" ");}

	/*And it prints the peak point*/
		printf("%c\n",the_peak_point);counter++;		

	}

  /*This loop is for bottom part of diagram*/
	for(i=0;i<first_height;i++)

	{
		printf("|");

/*This loop prints spaces as much as multiplication of feet height and one inadequated of first height */

		for(k=(feet_height*(first_height-1));k>m;k--){printf(" ");}

        /*And the quantities of spaces are reduced as much as feet height*/

		m=m+feet_height;
      
	/*This loop prints path point as much as feet height each step*/
		for(z=0;z<feet_height;z++){printf("%c",the_path_point);counter++;}

		printf("\n");
	}


    /*The number of characters was counted and returned*/
	return counter;
}


int finish_diag(int length)

{	
 /*This function part is for finishing diagram it prints "-" as much as length*/

	int u=0;

	printf("L");

	for(u=0;u<length;u++){printf("-");}

	printf(">\n");

 /*And returns 1*/

	return 1;


}

/*This function draws completed diagram with looped draw_diag_step function */

int draw_diag_of_bb(int first_height,int feet_height,char the_peak_point,char the_path_point)

{
	/*To define variables*/
	
	int i=0;

	int counter=0;

    
	int first_height_temp;

	int feet_height_temp;

    /*Assignment first height and feet height to temporary variables to use*/
	
	first_height_temp=first_height;

	feet_height_temp=feet_height;	

	printf("^\n");
   
     /*This loop uses draw_diag_step function and lowers steps*/
	
	for(i=first_height;i>0;i--)

	/*Counting return values of each step*/
	
	{counter+=draw_diag_step(first_height,feet_height,the_peak_point,the_path_point);

		first_height=first_height-1;

	}
		
 /*And calling finish diag function and adding return value of finish function*/

	counter+=finish_diag(first_height_temp*feet_height_temp+1);

	/*Return total values returned*/

	return counter;
	
}

/*############################################################################*/
/*             End of HW03_AhmetEmin_Kaplan_131044042_part3.c                 */
/*############################################################################*/
