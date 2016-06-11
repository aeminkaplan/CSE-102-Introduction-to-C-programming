/*############################################################################*/
/*HW05_AhmetEmin_Kaplan_131044042_part1.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 23 Mart,2015                                   */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/*Birbirine dogru yol alan iki arabanin carpisma simulatorudur                */
/*                                                                            */
/*Inputlar:                                                                   */
/* -Her araba için agirlik , hiz ve isim degerleri                            */
/*                                                                            */
/*Outputlar:                                                                  */ 
/* -Arabalarin hizina gore konumlari,carpisma noktalari ve enkazin konumu     */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/





#include<stdio.h> /*Math.h kutuphanesini import ettim fmod() fonksiyonunu kullanmak icin*/
#include<math.h>

/*Yolun uzunlugunu baslangic noktasi ve bitis noktasini macro olarak tanimladim*/

#define ROAD_LENGTH 50  
#define BEGINING_POINT 0
#define ENDING_POINT 49

typedef enum{PLAY,CRASH,END} object_state; /*Simulatorun olasi durumlarini enum olarak tanimladim*/


/*Bu fonksiyonun icin arabalarin hareket islemlerini yaptim ve
 print_game_state fonksiyonunu da bu fonksiyonun icinde kullandim*/

void make_move(char *object1, double *position1, double *speed1, int weight1,
char *object2, double *position2, double *speed2, int weight2, object_state
*game_state);


/*Bu fonksiyon arabalarin carpisacaklari zamani hesaplayip return eder*/

double car_crash_time(double position1, double position2, double speed1, double
speed2);

/*Bu fonksiyon arabalarin konumlarini,carpisma noktalarini ve 
enkazin durumunu ekrana yazdirir*/

void print_game_state(char object1, double position1, char object2, double position2,
object_state game_state);








int main()
{	

/*Kullanacagim degiskenleri tanimladim */
	object_state game_state;

	int weight1,weight2;

	char object1,object2;

	double position1,position2,speed1,speed2;
	
/*Arabalarin ilk konumlari baslangic noktamiz ve bitis noktamizda*/

	position1=BEGINING_POINT;

	position2=ENDING_POINT;


/*Kullanicidan tanimladigim degiskenler icin degerler isteniyor
Eger girilen degerler istenen aralikta degilse uyari verilip tekrar isteniyor
kullanici dogru deger girene kadar*/

	printf("Enter the name of 1st car\n");

	scanf("%c",&object1);	

	printf("Enter the name of 2nd car\n");

	scanf(" %c",&object2);	

	do
	{	printf("Enter the speed of 1st car\n");

		scanf("%lf",&speed1);

		if(speed1<=0)
		{

			printf("Speed of 1st car mustn't be negative or zero!\n");

		}	

	}while(speed1<=0);

	do
	{	

		printf("Enter the speed of 2nd car\n");

		scanf("%lf",&speed2);

		if(speed2>=0)
		{

			printf("Speed of 2nd car mustn't be positive or zero!\n");
		}		

	}while(speed2>=0);



	do
	{	
		printf("Enter the weight of 1st car\n");

		scanf("%d",&weight1);;

		if(weight1<=0)
		{

			printf("Weight of 1st car mustn't be negative or zero!\n");
		}	

	}while(weight1<=0);



	do
	{	
		printf("Enter the weight of 2nd car\n");

		scanf("%d",&weight2);		

		if(weight2<=0)
		{
			printf("Weight of 2nd car mustn't be negative or zero!\n");
		}	

	}while(weight2<=0);	
	

/*İlk olarak simulatorun baslangic durumu Play modunda
	 ve bu moda gore make_move fonksiyonunu cagirdim*/
	
	game_state=PLAY;

	make_move(&object1,&position1,&speed1,weight1,&object2,&position2,&speed2,weight2,&game_state);

	


}



/*Make_move fonksiyonu cagirildigi moda gore donguyle print fonksiyonunu cagirmaktadir*/

void make_move(char *object1, double *position1, double *speed1, int weight1,
char *object2, double *position2, double *speed2, int weight2, object_state
*game_state)
{
	int p;
	int y=1;
	double car_crash;
	int positionXtemp;
	double positionX;
	double speedX;	

/*Araclarin carpisacagi an car_crash_time fonksiyonuyla belirlenmektedir*/
	car_crash=car_crash_time(*position1,*position2,*speed1,*speed2);


/*Araclar carpisana kadar konumlari guncellenip donguyle print fonksiyonu cagirilmaktadir*/
	
	for(p=0;p<car_crash;p++)
	{
		print_game_state(*object1,*position1,*object2,*position2,*game_state);


		*position1=*position1+*speed1;

/*ikinci aracin pozisyonu bir kereye mahsus 0.99 eklenerek kusuratli kisim
tam hale getirilerek print fonksiyonu dongu icinde cagiriliyor ve pozisyonlar
her hareket sirasinda guncelleniyor*/

		if(y==1)
		{
			*position2=*position2+*speed2+0.99;
			 y=0;
		}	

		else 
		{
			*position2=(*position2+*speed2);
		}

	}


/*Araclar carpisana kadar hareket edeceklerdir carpismadan once carpisma konumunu belirlenip
game state guncellendikten sonra print fonksiyonu crash modunda cagirilmaktadir*/

	*game_state=CRASH;


	(*position1)=(*speed1)*(car_crash);

	(*position2)=(-*speed2)*(car_crash);



	print_game_state(*object1,*position1,*object2,*position2,*game_state);

/*Araclar carpistiktan sonra game state end moduna guncellenip enkazin konumu belirleniyor*/	
	*game_state=END;


/*Eger birinci aracin konumunun kusurati fazlaysa veya ikinci araca esitse
birinci aracin konumu enkazin konumuna assign edilir.Degilse ikinci aracin konumu
enkazin konumuna assign edilir*/

	if(fmod(*position1,1)>=fmod(*position2,1))
	{
		positionXtemp=(int)*position1;
	}

	else
	{
		positionXtemp=(int)ENDING_POINT-(*position2);
	}
	
	positionX=positionXtemp;


	/*Enkazin hizi esnek olmayan carpismaya gore hesaplanir*/

	speedX=(((*speed1) * weight1)+((*speed2) * weight2))/(weight1+weight2);	
	
	/*Eger enkazin hizi pozitifse enkaz + yonde ne kadar hareket edecegi hesaplanir.
	Eger negatifse - yonde hareketi hesaplanir.0 ise enkaz durgun kalacaktir ve 1 kere
konumunun test edilmesi gereklidir*/
	
	if(speedX>0)
	{
		car_crash=((ENDING_POINT-positionX)/speedX);
	}

	if(speedX<0)
	{
		car_crash=(((positionX)/speedX)*-1);
	}
	
	if(speedX==0)
	{
		car_crash=1;
	}
	
/*Enkazin hareket sayisi kadar dongu print fonksiyonunu end modunda cagirmaktadir
ve her seferinde enkazin konumu guncellenmektedir*/

	for(p=0;p<=car_crash;p++)
	{

	print_game_state(*object1,positionX,*object2,*position2,*game_state);

	positionX=positionX+speedX;
	
	}


/*Enkazin hareket sayisi kusuratliysa kusuratli kisim hareket edilmeyecegi icin
 enkazin duvara carptigi an  ekrana bastirilir */
	if(fmod(car_crash,1)>0)
	{
		if(speedX>0)
		{
			positionX=ENDING_POINT;
		}
		else
		{
			positionX=BEGINING_POINT;
		}
			
		print_game_state(*object1,positionX,*object2,*position2,END);

	}
}


void print_game_state(char object1, double position1, char object2, double position2,
object_state game_state)
{
	/*Ekrana basacagim konumlar integer olmasi gerektigi icin
 integer olarak cast edecegim degiskenleri tanimladim*/

	int positionA;

	int positionB;

	int positionX;

/*Dongulerde kullanmak icin degiskenler tanimladim*/
	int i;

	int k=1;


/*Butun yolu ekrana bastirmak icin yol uzunlugumuz 
buyuklugunde karakter arrayi tanimladim*/
	char Road_array[ROAD_LENGTH];

	for(i=0;i<ROAD_LENGTH;i++)
	{
		Road_array[i]='_';
	}


		
/*Eger print fonksiyonu play modunda cagirilirsa fonksiyona
 gelen arabalarin konum degerleri integera cast edilip ekrana basilir*/
	if(game_state==PLAY)
	{
		positionA=(int)position1;

		positionB=(int)(position2);

		Road_array[positionA]=object1;

		Road_array[positionB]=object2;

		for(i=0;i<ROAD_LENGTH;i++)
		{
			printf("%c",Road_array[i]);
		}

		printf("\n");

/*Araclarin aldigi yolu gozle gorulur hale getirmek icin 50 karakterlik numaralama*/
		for(i=0;i<ROAD_LENGTH;i++)
		{
			printf("%d",k);

			k++;

			if(k>9)

			{
				k=0;
			}
		}

		printf("\n");	
	}
/*Eger print fonksiyonu crash modunda cagirilirsa fonksiyona gelen konum
 degerlerinin kusurati buyuk olanin degeri integera cast edilip enkazin konumu belirlenir*/	
	if(game_state==CRASH)
	{

		if(fmod(position1,1)>=fmod(position2,1))
		{
			positionX=(int)(position1);
		}

		else
		{
			positionX=(int)ENDING_POINT-(position2);
		}

		Road_array[positionX]='X';
		
		for(i=0;i<ROAD_LENGTH;i++)
		{
			printf("%c",Road_array[i]);
		}

		printf("\n");

		for(i=0;i<ROAD_LENGTH;i++)
		{
			printf("%d",k);k++;
			if(k>9)
			{
				k=0;
			}
		}
		
		printf("\n");


	}

/*Eger print fonksiyonu END modunda cagirilirsa fonksiyona gelen deger 
enkazin konumu olacaktir ve enkazin konumu ekrana basilir*/

	if(game_state==END)
	{

		positionA=(int)position1;

		Road_array[positionA]='X';

		for(i=0;i<ROAD_LENGTH;i++)
		{
			printf("%c",Road_array[i]);
		}

		printf("\n");

		for(i=0;i<ROAD_LENGTH;i++)
		{	
			printf("%d",k);k++;

			if(k>9)
			{
				k=0;
			}
		}

		printf("\n");
				


	}

}




/*Bu fonksiyon 2 arabanin birbirine dogru hareket ettikleri
 durumda carpisacaklari sureyi hesaplar*/

double car_crash_time(double position1, double position2, double speed1, double speed2)
{

	double temp;

	temp=(position2-position1)/(speed1-speed2);	
	
	return temp;

}


/*############################################################################*/
/*                    End of HW05_AhmetEmin_Kaplan_131044042_part1.c          */
/*############################################################################*/
