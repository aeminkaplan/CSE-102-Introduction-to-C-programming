/*############################################################################*/
/*HW09_AhmetEmin_Kaplan_131044042_part3.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 29 Nisan,2015                                  */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/*Dosyadan alınan degerler arasında arama yapmaya yarar                       */
/*                                                                            */
/*Inputlar:                                                                   */
/* -Eslesme icin aranacak combinasyon bilesenleri                             */
/*Outputlar:                                                                  */ 
/* -Esleme bulundugu durumda bilesenleri iceren veriler                       */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include<stdio.h>

#define MAXSIZE 10  /*load ve into binary fonksiyonlarinin bir kerede kac okuma yapacagini
 belirleyen degeri macro olarak tanimladim*/

/*Okuma yapacagim input text dosyasinin ismi bacteria.txt dir odevde belirtilmedigi
 icin ben rasgele bir isim yazdim*/

#define ROWSIZE 17/*Dosyadaki toplam satir sayisini macro olarak tanimladim*/

typedef struct
{
 	int first;
	int second;
	int third;	

}triplet_t;

typedef struct
{
	int mpn;
	triplet_t combinations;
	int lower;
	int upper;
}Row;

void Into_Binary(FILE *text_input,FILE *binary_output);

int Load_Mpn_table(FILE *binary_input_file,Row mpn_table[],int maxsize);

void search(Row mpn_table[],int actual_size,const triplet_t triplet_to_search);

triplet_t get_params();

int main()
{
	int actual_size,i;

	triplet_t triplet_to_search;

	FILE *text_input;

	FILE *binary_output;

	FILE *binary_input_file;

	Row mpn_table[ROWSIZE];

	text_input=fopen("bacteria.txt","r");

	if(text_input==NULL)
	{
		printf("bacteria.txt input text file couldnt be opened ! \n");
		return 0;	
	}
	binary_output=fopen("converted.bin","wb");

	if(binary_output==NULL)
	{	
		printf("converted.bin output binary file couldnt be opened ! \n");
		return 0;
	}

	triplet_to_search=get_params();

	for(i=0;i<ROWSIZE;i=i+10)
		Into_Binary(text_input,binary_output);
	
	fclose(text_input);

	fclose(binary_output);
	
	binary_input_file=fopen("converted.bin","rb");

	if(binary_input_file==NULL)
	{
		printf("converted.bin input binary file couldnt be opened ! \n");
		return 0;	
	}

	actual_size=Load_Mpn_table(binary_input_file,mpn_table,MAXSIZE);

	for(i=0;i<ROWSIZE-10;i=i+10)	
		actual_size=actual_size+Load_Mpn_table(binary_input_file,&mpn_table[actual_size],MAXSIZE);


	fclose(binary_input_file);

	for(i=0;i<ROWSIZE;++i)
	{
		printf("%d %d %d %d %d %d\n",mpn_table[i].combinations.first
									,mpn_table[i].combinations.second
									,mpn_table[i].combinations.third
									,mpn_table[i].mpn
									,mpn_table[i].lower
									,mpn_table[i].upper);
	}

	search(mpn_table,actual_size,triplet_to_search);

	return 0;
}

/*Text filedan okunan degerler structa atandıktan sonra bu veriler binary file a yazilir*/

void Into_Binary(FILE *text_input,FILE *binary_output)
{
	int i=0;

	Row temp;

	char junk;

	while(i<10 && fscanf(text_input,"%1d",&temp.combinations.first)!=EOF)
	{
	
		fscanf(text_input,"%c",&junk);

		fscanf(text_input,"%1d",&temp.combinations.second);

		fscanf(text_input,"%c",&junk);

		fscanf(text_input,"%1d",&temp.combinations.third);

		fscanf(text_input,"%d",&temp.mpn);

		fscanf(text_input,"%d",&temp.lower);

		fscanf(text_input,"%d",&temp.upper);		
		
		fwrite(&temp,sizeof(Row),1,binary_output);
	}
}

/*Bu fonksiyon ile binary filedan okunan veriler mpn_table arrayine yazılır vea actual size degeri return edilir yani fonksiyon tekrar cagirilmaya baslaninca arrayin hangi elemanindan itibaren okuyacagi bu return degeriyle belirlenir*/
int Load_Mpn_table(FILE *binary_input_file,Row mpn_table[],int maxsize)
{
	int i=0;
	while(i<maxsize && fread(&mpn_table[i],sizeof(Row),1,binary_input_file)!=0 )
	{
		i++;	
	}
	
	return i;
}

/*Kullaniciden arama parametrelerini alan fonksiyon */
triplet_t get_params()
{
	triplet_t temp;

	char junk;

	char input[10];

	scanf("%s",input);

	sscanf(input,"%1d%c%1d%c%1d",&temp.first,&junk,&temp.second,&junk,&temp.third);	

	return temp;
}
/*Bu fonksiyon struct arrayi uzerinde arama yapar eger aranan veriler bulunduysa bunlar icin
 mpn ,lower ve upper degerlerini ekrana basar*/

void search(Row mpn_table[],int actual_size,const triplet_t triplet_to_search)
{
	int i,found=-1;

	for(i=0;i<actual_size;++i)
	{

		if(mpn_table[i].combinations.first==triplet_to_search.first &&

		mpn_table[i].combinations.second==triplet_to_search.second &&

		mpn_table[i].combinations.third==triplet_to_search.third  )

				found=i;

	}
	
	if(found==-1)
	{
		printf("Record couldnt be found ! \n");

	}
	
	else
	{
		printf("MPN=%d; 95%% of samples contain between %d and %d bacteria/ml.\n",mpn_table[found].mpn
		,mpn_table[found].lower,mpn_table[found].upper);	
	
	}

}


/*############################################################################*/
/*                 HW09_AhmetEmin_Kaplan_131044042_part3.c                    */
/*############################################################################*/
