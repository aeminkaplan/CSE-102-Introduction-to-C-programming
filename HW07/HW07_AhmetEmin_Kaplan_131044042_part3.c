/*############################################################################*/
/*HW07_AhmetEmin_Kaplan_131044042_part3.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 13 Nisan,2015                                  */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/*Dosyadan alinan kare matrisin degerlerine gore labirentin yolunu cizer      */
/*                                                                            */
/*Inputlar:                                                                   */
/* -Kare matris icin 0,1 veya 2 den olusan degerler                           */
/*                                                                            */
/*Outputlar:                                                                  */ 
/* -Labirentin cikis haritasini ekrana cizer                                  */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

/*Dosyadaki degerlerin miktarina gore COL_SIZE ve RAW_SIZE duzeltilmelidir*/

#include<stdio.h>
#define COL_SIZE 5
#define RAW_SIZE 5

typedef enum{notavailable,available,right_down} Grid_t;

typedef enum{TRUE,FALSE} Bool;

void read_table(FILE *input_file,Grid_t table[][COL_SIZE]);

void print_path(char path[][COL_SIZE],int n);

Bool find_path(Grid_t table[][COL_SIZE],char path[][COL_SIZE],int size,int location_x,int location_y);


int main()
{
	int i,j;

	FILE* input;
	
	Grid_t table[RAW_SIZE][COL_SIZE];

	char path[RAW_SIZE][COL_SIZE];

	input=fopen("table.txt","r");



/*Eger dosya acilamadiysa hata mesaji vererek kullanici uyarilmaktadir*/	

	if(input==NULL)
	
	{
		printf("Hata ! table.txt dosyasi acilamadi...\n");
		
		return 0;		
	}

/*Oncelikle path arrayinin butun elemanlarina space karakteri atanmaktadir*/

	for(i=0;i<RAW_SIZE;++i)
	{
		for(j=0;j<COL_SIZE;++j)

		path[i][j]=' ';


	}


	read_table(input,table);
	
	find_path(table,path,RAW_SIZE,0,0);


	print_path(path,RAW_SIZE);
	


}

/*find_path fonksiyonu recursive olarak table arrayini kontrol etmektedir ve kontrol 
sonucu path arrayini doldurmaktadir recursive fonksiyonun bitirme kosulu arrayin 
son satirinin son elemanina erisilip erisilememedir 5-5 olan bir arrayin bitis
 noktasina erisilip erisilememe durumunu oraya erisilince cagrilmasi gerekilen 
fonksiyonun cagirilma veya cagirilmama durumuna gore kontrol etmekteyim 
eger 4-4 noktasina erisildiyse 4-5 veya 5-4 kordinati cagrilmasi gerekir eger bu 
cagri yapiliyorsa fonksiyon TRUE deger dondurur yani labirentin cikis noktasina
 erisilebilmektedir buna gore yol '*' ile doldurulur.Eger bu erisim saglanamaz
 veya 0 degeri okunursa fonksiyon FALSE dondurur yani orasi cikmaz sokaktir*/

Bool find_path(Grid_t table[][COL_SIZE],char path[][COL_SIZE],int size,int location_x,int location_y)
{
	Bool result;


	if(((location_x>=size && location_y>=COL_SIZE-1) || (location_x>=size-1 && location_y>=size) ) || table[location_y][location_x]==notavailable || ((location_x>=size && location_y<COL_SIZE-1) || (location_y>=COL_SIZE && location_x<size-1)))

	{

		if(((location_x>=size && location_y>=COL_SIZE-1) || (location_x>=size-1 && location_y>=COL_SIZE) ))

		result=TRUE;
	

		else
		result=FALSE;

	}
	else
	{
		if(table[location_y][location_x]==available)
		{
			
			result=find_path(table,path,size,location_x+1,location_y);

			if(result==TRUE)
			{

				path[location_y][location_x]='*';

				return TRUE;

			}
	
			result=find_path(table,path,size,location_x,location_y+1);

			if(result==TRUE)
			{

				path[location_y][location_x]='*';	

				return TRUE;
			}		
		
		}
		
		if(table[location_y][location_x]==right_down)
		{

			result=find_path(table,path,size,location_x+1,location_y+1);

			if(result==TRUE)
			{

				path[location_y][location_x]='*';

				return TRUE;
			}

		}
	}



	return result;
}


/*print_path fonksiyonu belirlenen yolu ekrana yazdirmaktadir*/


void print_path(char path[][COL_SIZE],int n)
{
	int i,j;

	for(i=0;i<n;++i)
	{
		printf("\n");

		for(j=0;j<COL_SIZE;++j)

			printf("%c",path[i][j]);
	}

		printf("\n");
}


/*read_table fonksiyonu dosyadaki degerleri okuyup degerleri 
table iki boyutlu arrayine yazmaktadir*/


void read_table(FILE *input_file,Grid_t table[][COL_SIZE])
{
	int i,j,temp;

	for(i=0;i<RAW_SIZE;i++)

		for(j=0;j<COL_SIZE;j++)
		{				

			fscanf(input_file,"%d",&temp);

			table[i][j]=temp;	

		}
}

/*############################################################################*/
/*                HW07_AhmetEmin_Kaplan_131044042_part3.c                     */
/*############################################################################*/
