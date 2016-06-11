/*############################################################################*/
/*HW07_AhmetEmin_Kaplan_131044042_part1.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 13 Nisan,2015                                  */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/*Girilen stringin boyutunu return eden fonksiyon icerir                      */
/*Girilen iki stringin ilkinin icinde kac tane ikinci stringin oldugunu return*/
/*eden fonksiyon icerir                                                       */
/*Inputlar:                                                                   */
/* -Boyu olculecek string                                                     */
/* -Birbiri icinde arama yapilacak iki string                                 */
/*Outputlar:                                                                  */ 
/* -Stringin boyutu,ve iki stringin birbiri icinde tekrar sayisi              */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/


#include<stdio.h>
#include<string.h>

int find_size(const char* string);
int char_number(const char* string,const char* wish_to_find);


int main()
{
	

	/*Fonksiyonlar parametre olarak const string aldigi icin degerleri scanf ile girememekteyiz */

	const char str[50]="ahmeteminkaplan-kaplanahmetemin-abcdefg-emin";

	const char str2[50]="emin";

	printf("Stringin boyutu:%d\n",find_size(str));


	printf("Birinci stringin icinde ikinci stringin bulunma miktari:%d\n",char_number(str,str2));
	
	
	return 0;
}

/*find_size fonksiyonu parametre olarak yollanan stringin boyutunu return eder*/
int find_size(const char* string)
{
	int result;
	if(string[0]=='\0')
	result=0;

	else
	result=1+find_size(&string[1]);

	return result;
}


/*2 tane string parametre alan char_number fonksiyonu birinci parametre stringin
 icinde kac tane ikinci parametre string oldugunu return eder*/
int char_number(const char* string,const char* wish_to_find)
{
	int result;
	int size_string=find_size(string);
	int size_wish_to_find=find_size(wish_to_find);	

	if(size_wish_to_find > size_string)
	{

		result=0;
	
	}
	
	else{

		if(strncmp(string,wish_to_find,size_wish_to_find)==0)
		result=1+char_number(&string[1],wish_to_find);		


		else
		result=char_number(&string[1],wish_to_find);			
		
	}
	return result;
}


/*############################################################################*/
/*                *HW07_AhmetEmin_Kaplan_131044042_part1.c                    */
/*############################################################################*/
