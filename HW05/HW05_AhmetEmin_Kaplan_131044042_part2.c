/*############################################################################*/
/*HW05_AhmetEmin_Kaplan_131044042_part2.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 23 Mart,2015                                   */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/*Herhangi bir array uzerinde bazi islemler yapmaya yarar                     */
/*                                                                            */
/*Inputlar:                                                                   */
/* -Bir array ve arrayin boyutu                                               */
/*                                                                            */
/*Outputlar:                                                                  */ 
/* -Arrayin maximum elemani                                                   */
/* -Arrayin ikinci maximum elemani                                            */
/* -Arrayin elemanlari toplami                                                */
/* -Arrayde herhangi bir elemanin bulunma miktari                             */
/* -Arrayde herhangi bir elemanin konumu                                      */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/






#include<stdio.h>

/*bool veri tipini enum olarak tanimladim olasi constantlar TRUE ve FALSE */

typedef enum{TRUE,FALSE} bool;

/*Fonksiyonlarin prototipleri*/

int max_array(int array[], int n);

int second_max_array(int array[], int n);

int sum_all_array (int array[], int n);

int count_array(int array[], int n, int value);

bool search_array (int array[], int n, int value);



int main()
{
	
	int my_array[9]={6,8,3,3,12,8,3,8,2};

	printf("++++++++++++++++++++\n");

	printf("Maximum array is %d\n",max_array(my_array,9));

	printf("++++++++++++++++++++\n");

	printf("Second Maximum array is %d\n",second_max_array(my_array,9));

	printf("++++++++++++++++++++\n");

	printf("Sum of All array is %d\n",sum_all_array(my_array,9));

	printf("++++++++++++++++++++\n");

	printf("Count of value 6 is %d\n",count_array(my_array,9,6));		

	printf("Count of value 3 is %d\n",count_array(my_array,9,3));		

	printf("Count of value 8 is %d\n",count_array(my_array,9,8));	

	printf("++++++++++++++++++++\n");

	search_array(my_array,9,2);	

	search_array(my_array,9,8);

	search_array(my_array,9,12);

	return 0;
}


/*Arrayin ilk elemani maximum degiskenine assign edildikten sonra 
her bir eleman kontrol edilir kontrol edilen elemanlar maximum
 degiskenden buyukse yeni maksimum degerine assign edilir
 en sonunda maximum deger return edilir*/

int max_array(int array[], int n)
{
	int i=1;

	int max_value;

	max_value=array[0];	

	while(i<n)
	{

		if(array[i]>max_value)
		{
			max_value=array[i];
					
		}

		i++;

	}

	return max_value;
}


/*Oncelikle arrayin ilk degeri maximum deger degiskenine assign edilir
 ve diger degerler sirasiyla kontrol edilir ve kontrol edilen degerler 
assign edilen degerden daha buyukse maximum degerimiz guncellenir 
ve eski maximum degerimiz second maximum degiskenine assign edilir*/


int second_max_array(int array[], int n)
{
	int i=1;

	int max_value;

	int second_max_value;

	max_value=array[0];

	while(i<n)
	{
		if(array[i]>max_value)
		{
			second_max_value=max_value;

			max_value=array[i];
					
		}

		i++;
	}

	return second_max_value;
}

/*Arrayin ilk elemani sum degiskenine assign edildikten sonra her bir eleman
 tek tek eklenir ve en son sum degeri return edilir*/

int sum_all_array (int array[], int n)
{
	int sum;

	int i;

	sum=array[0];	

	for(i=1;i<n;i++)
	{	
		sum=sum+array[i];
		
	}	

	return sum;

}


/*Fonksiyon arrayin her bir elemanini kontrol eder girilen deger ile eslestirince 
sayaci artirir ve en son sayactaki deger return edilir*/

int count_array(int array[], int n, int value)
{	
	
	int counter=0;

	int i;

    for(i=0;i<n;i++)
	{
		if(array[i]==value)
		{
			counter++;		
		}
	
	}	

	return counter;
}



bool search_array (int array[], int n, int value)

{
	/*Baslangic olarak index degerimiz -1 yani aranan deger bulunamamis gibi atama yaptim
  Arrayin butun elemanlari sirasiyla kontrol edilir eger aranan deger bulunursa index degerimize atanir */

	int index=-1;
	
	int i;
	
	for(i=0;i<n;i++)
	{
		if(value==array[i])
		{
			index=i; /*Deger bulundugu zaman i ye n atanarak donguden cikilir*/

			i=n;						
		
		}


	}


/*Eger deger bulunduysa ekrana nerede oldugu yazdirilir ve TRUE return edilir*/

	if(index!=-1)
	{
		printf("%d is at [%d]\n",value,index);

		return TRUE;
	}

/*Eger deger bulunamadiysa ekrana bulunamadigi yazdirilir ve FALSE return edilir*/

	else
	{
		printf("%d is not found\n",value);	

		return FALSE;
	}
}


/*############################################################################*/
/*                End of HW05_AhmetEmin_Kaplan_131044042_part1.c              */
/*############################################################################*/
