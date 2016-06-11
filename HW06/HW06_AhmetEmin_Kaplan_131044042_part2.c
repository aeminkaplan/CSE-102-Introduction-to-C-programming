/*############################################################################*/
/*HW06_AhmetEmin_Kaplan_131044042_part2.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 6 Nisan,2015                                   */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/* Turkcenin sahip oldugu bazi grammer kurallari icin fonksiyonlar icerir     */
/*                                                                            */
/*Inputlar:                                                                   */
/* -Program tam calismadigi icin  sadece fonksiyonlari icermektedir           */
/*                                                                            */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/



#include<stdio.h>
#include<string.h>

typedef enum{TRUE,FALSE} BOOL;
typedef enum{HARD,SOFT,CONSONANT} major_type;
typedef enum{FLAT,ROUND,CONSONANT2} minor_type;

BOOL is_major_vh_word(const char* word,const char* v_hard,const char* v_soft);
major_type major(const char ch1,const char* v_hard,const char* v_soft);
minor_type minor(const char ch1,const char* v_flat,const char* v_round);
major_type find_last_type(const char* word,const char* v_hard,const char* v_soft);
char* make_plural(const char* noun,char* plural_noun,const char* v_hard,const char* v_soft);

int main()
{



	/*Odevi tam olarak yazmaya zamanim yetmedi bundan dolayi 
			fonksiyonlari ve islevlerini yazdim*/


	/*Kucuk unlu uyumunu kontrol eden fonksiyon haricinde 
		diger fonksiyonlari tanimladim*/


}

/*Bu fonksiyonun girilen kelimeyi(string) buyuk unlu uyumuna uyup uymadigini
 kontrol edip TRUE veya FALSE degeri donduruyor girilen kelimenin her harfini 
tek tek kontrol edip sert unlu veya yumusak unlu sayilarini sayiyor eger sert
unlu ve yumusak unlu sayilari sifirdan farkliysa yani kelime icinde
 sert ve yumusak unlulerin her ikisindende bulunuyorsa kelime buyuk unlu uyumuna uymaz
eger kelimede sadece yumusak unluler bulunuyor sert unluler bulunmuyorsa bunlarin 
sayilarinin carpimi 0 olacaktir eger carpim sifirsa kelime buyuk unlu uyumuna uyar*/


BOOL is_major_vh_word(const char* word,const char* v_hard,const char* v_soft)
{

	int i,k,l;
	int soft_vovel_counter=0;
	int hard_vovel_counter=0;
	int consonant_counter=0;	
	
	
	k=strlen(word);

	for(i=0;i<k;++i)
	{
		
		if(major(word[i],v_hard,v_soft)==HARD)
		hard_vovel_counter++;
		if(major(word[i],v_hard,v_soft)==SOFT)
		soft_vovel_counter++;	
		if(major(word[i],v_hard,v_soft)==CONSONANT)
		consonant_counter++;	
	}


	if(soft_vovel_counter*hard_vovel_counter==0)
	return TRUE;
	else
	return FALSE;	

}


/*Bu fonksiyon girilen karakterin sert unlu veya yumusak unlu olup olmadigini return 
etmektedir karakteri sirasiyla sert unlulerle ve yumusak unlulerle kiyaslamaktadir ve 
eger eslesme bulunamazsa baslangicta tanimlanan CONSONANT degeri return etmektedir */

major_type major(const char ch1,const char* v_hard,const char* v_soft)
{

  int i,k,m;
	k=strlen(v_hard);
	m=strlen(v_soft);	
  major_type type=CONSONANT;
	
	for(i=0;i<k;i++)
	{	
		if(ch1==v_hard[i]){type=HARD;}

	}
	
	for(i=0;i<m;i++)
	{
		if(ch1==v_soft[i]){type=SOFT;}

	}
	
	return type;
}


/*Bu fonksiyon girilen karakterin duz unlu veya yuvarlak unlu olup olmadigini return 
etmektedir karakteri sirasiyla duz unlulerle ve yuvarlak unlulerle kiyaslamaktadir ve 
eger eslesme bulunamazsa baslangicta tanimlanan CONSONANT degeri return etmektedir*/


minor_type minor(const char ch1,const char* v_flat,const char* v_round)
{
	int i;
	major_type type=CONSONANT2;


	for(i=0;i<3;i++)
	{
		if(ch1==v_flat[i]){type=FLAT;}

	}

	for(i=0;i<2;i++)
	{
		if(ch1==v_round[i]){type=ROUND;}

	}


	return type;

}


/*Bu fonksiyon girilen kelimenin(string) son unlu harfinin sert veya yumusak olup olmadigini
return etmektedir girilen kelimenin her karakterini tek tek kontrol eder ve en son kontrol 
ettigi karakterin hard veya soft oldugu durumlarda last_type guncellenir */

major_type find_last_type(const char* word,const char* v_hard,const char* v_soft)
{
	int i,k;
	k=strlen(word);
	major_type type;
	major_type last_type;
	for(i=0;i<k;++i)
	{
		type=major(word[i],v_hard,v_soft);
		if(type!=CONSONANT)
		last_type=type;

	}


	return last_type;

}
/*Bu fonksiyon girilen kelimenin(string) son unlu harfinin sert veya yumusak olmasina gore 
kelimeye cogul eki eklemeye yarar*/

char* make_plural(const char* noun,char* plural_noun,const char* v_hard,const char* v_soft)
{
	int k;
	k=strlen(noun+3);
	char temp[20];
	
	if(find_last_type(noun,v_hard,v_soft)==HARD)
	{
		strcpy(temp,noun);
		strcat(temp,"lar");
		strcpy(plural_noun,temp);
	}

	else
	{
		strcpy(temp,noun);
		strcat(temp,"ler");
		strcpy(plural_noun,temp);


	}

	return plural_noun;	
}


/*############################################################################*/
/*                 HW06_AhmetEmin_Kaplan_131044042_part2.c                    */
/*############################################################################*/
