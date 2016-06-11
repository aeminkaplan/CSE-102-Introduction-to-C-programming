/*############################################################################*/
/*HW07_AhmetEmin_Kaplan_131044042_part2.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 13 Nisan,2015                                  */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/*Girilen basamak sayisinin her adimda 1 veya 2 basamak cikilarak kac farkli  */
/*sekilde cikilabilecegini bulan fonksiyonu icerir bulur                      */
/*                                                                            */
/*Inputlar:                                                                   */
/* -Cikilacak basamak sayisi                                                  */
/*Outputlar:                                                                  */ 
/* -Butun basamak cikis sekillerinin sayisi                                   */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/




#include<stdio.h>



int combination(int n,int k);

int ways(int n);

int ways_rec(int n,int k);

int main()
{

	int number_of_steps;

	scanf("%d",&number_of_steps);

	printf("%d\n",ways(number_of_steps));



	return 0;
}


int combination(int n,int k)
{
	int result;
	
	if(k==0 || k==n)
	{
		result=1;
	}

	else
	{
		result=combination(n-1,k-1)+combination(n-1,k);
	}

	return result;
}


int ways(int n)
{
	int result,k=0;

	result=ways_rec(n,k);

	return result;
}


int ways_rec(int n,int k)
{
	int result;

	if(k>n)
	{
	result=0;
	}

	else
	{
	result=combination(n,k)+ways_rec(n-1,k+1);

	}

	return result;
}


/*############################################################################*/
/*              HW07_AhmetEmin_Kaplan_131044042_part2.c                       */
/*############################################################################*/
