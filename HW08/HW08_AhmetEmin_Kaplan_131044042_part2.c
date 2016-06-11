/*############################################################################*/
/*HW08_AhmetEmin_Kaplan_131044042_part2.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 22 Nisan,2015                                  */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/*Randevu sisteminde cakisan uygun olmayan  randevuyu iptal eder              */
/*                                                                            */
/*Inputlar:                                                                   */
/*Randevuların yil,ay,gun ve saati                                            */
/*Randevu sahiplerinin TCkimlik numaralari,isimleri,soyisimleri ve cinsiyetler*/
/*Outputlar:                                                                  */ 
/* -Onaylanan randevular ve randevu sahiplerinin bilgileri                    */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
#define MAX_SIZE 20
typedef enum{MALE,FEMALE}
Gender_t;

typedef enum{JUNK,JANUARY,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER}
Months_t;

typedef struct
{
	int hour;
	int minute;
}
Time_t;

typedef struct
{
	int first_half;
	int second_half;
}
TCId_no_t;

typedef struct
{
	TCId_no_t id_no;
	char name[30];
	char surname[30];
	Gender_t gender;
}
People_t;

typedef struct
{
	int year;
	Months_t month;
	int day;
	Time_t time;
}
Date_t;

typedef struct
{
	People_t people;
	Date_t date;
}
Appointment_t;

int get_people(const char *file_name, People_t people[], int max_size);
int get_appointments(const char *file_name, Appointment_t appointments[],int max_size);
void write_names(Appointment_t appointments[], int size_app, const People_t people[],int size_people);
int check_appointments(Appointment_t appointments[], int size);
void sort_appointments(Appointment_t appointments[], int size);
void write_appointments(const char *file_name, Appointment_t appointments[],int size);


int main()
{
	int i,size_people,size_app,new_size_after_deletion;

	People_t people[MAX_SIZE];

	Appointment_t appointments[MAX_SIZE];
	
	size_people=get_people("People.txt",people,MAX_SIZE);

	size_app=get_appointments("AppointmentReqs.txt",appointments,MAX_SIZE);

	if(size_people!=size_app)
	{
		printf("Randevu ve Kisi bilgileri sayisi eslesmedi\n");

		return 0;
	}	
	
	write_names(appointments,size_app,people,size_people);

	new_size_after_deletion=check_appointments(appointments,size_app);

	sort_appointments(appointments,new_size_after_deletion);
	
	write_appointments("Appointments.txt",appointments,new_size_after_deletion);	


	return 0;
	
}


int get_people(const char *file_name,People_t people[],int max_size)
{
	FILE* input;

	int i=0;

	char junk;

	char gend;

	input=fopen(file_name,"r");
	
	if(input==NULL)
	{
	printf("Dosya acilamadi ! \n");

	}
	
	while(fscanf(input,"%6d",&(people[i].id_no.first_half))!=EOF && i<max_size)
	{	

		fscanf(input,"%5d",&(people[i].id_no.second_half));		

		fscanf(input,"%s",people[i].name);

		fscanf(input,"%s",people[i].surname);

		fscanf(input,"%c",&junk);

		fscanf(input,"%c",&gend);
	
		if(gend=='M')
		people[i].gender=MALE;

		if(gend=='F')
		people[i].gender=FEMALE;
				
		i++;
	}

	return i;
}


int get_appointments(const char *file_name,Appointment_t appointments[],int max_size)
{
	FILE* input;

	int i=0;

	int month_temp;

	char junk;

	input=fopen(file_name,"r");

	if(input==NULL)
	{
	printf("Dosya acilamadi ! \n");

	}

	while(fscanf(input,"%6d",&(appointments[i].people.id_no.first_half))!=EOF && i<max_size)
	{

		fscanf(input,"%5d",&(appointments[i].people.id_no.second_half));

		fscanf(input,"%d",&(appointments[i].date.year));

		fscanf(input,"%d",&month_temp);

		appointments[i].date.month=month_temp;

		fscanf(input,"%d",&(appointments[i].date.day));	

		fscanf(input,"%d",&(appointments[i].date.time.hour));

		fscanf(input,"%c",&junk);		

		fscanf(input,"%2d",&(appointments[i].date.time.minute));

		i++;	
	}

	return i;
}



void write_names(Appointment_t appointments[],int size_app,const People_t people[],int size_people)
{
	int i;
	if(size_app!=size_people)
	printf("Okuma hatası!\n");

	for(i=0;i<size_app;++i)
	{
		appointments[i].people.id_no.first_half=people[i].id_no.first_half;
		
		appointments[i].people.id_no.second_half=people[i].id_no.second_half;

		strcpy(appointments[i].people.name,people[i].name);

		strcpy(appointments[i].people.surname,people[i].surname);

		appointments[i].people.gender=people[i].gender;

	}

}


int check_appointments(Appointment_t appointments[],int size)
{
	int i,j,counter=0,delete=-1;
	Appointment_t temp;
	/*Butun randevular her saat basi veya saat ortasinda baslamak zorunda oldugu
 icin dakika degeri uymayan randevular silinir*/


	for(i=0;i<size;++i)
	{
		if(appointments[i].date.time.minute!=30 && appointments[i].date.time.minute!=0)
		{
			counter++;
			appointments[i].date.year=delete;
		}

	}

	/*Eger randevu bilgilerinin butun bilesenleri esit ise 2.olan randevu bilgisini
 silmem gerekiyor silme islemini kolay yapmak icin sildigim yil degerinin yerine -1 atiyorum
	ve counter ile silinen randevu sayisini tutuyorum */
	for(j=0;j<size;++j)
	{	for(i=j+1;i<size;++i)
		{
							
			if(((appointments[j].date.year)==(appointments[i].date.year)) && 
			   ((appointments[j].date.month)==(appointments[i].date.month)) &&
				((appointments[j].date.day)==(appointments[i].date.day)) &&
				((appointments[j].date.time.minute)==(appointments[i].date.time.minute)) &&
				((appointments[j].date.time.hour)==(appointments[i].date.time.hour)))
			{
			
				counter++;
				appointments[i].date.year=delete;
	
			}
		}

	}

/*Siralama fonksiyonuna gondermeden once yil bilgilerine gore buyukten kucuge siraliyorum
 boylelikle sildigim yani -1 atadigim deger sona dusecek */

	for(i=0;i<size;++i)
	{
		for(j=i+1;j<size;++j)
		{
			if(appointments[i].date.year<appointments[j].date.year)
			{
				
				temp=appointments[i];
				
				appointments[i]=appointments[j];
	
				appointments[j]=temp;				

			}

		}	


	}

	return size-counter;
}


void sort_appointments(Appointment_t appointments[],int size)
{
	int control=0,i,j,l,m;

	Appointment_t temp;
	
	int month_temp1,month_temp2;

	for(i=0;i<size;++i)
	{
		for(j=i+1;j<size;++j)
		{
			if(appointments[i].date.year>appointments[j].date.year)
			{	
				temp=appointments[i];
				appointments[i]=appointments[j];
				appointments[j]=temp;
				

			}

		}	


	}

	for(i=0;i<size;++i)
	{
		for(j=i+1;j<size;++j)
		{
			if(appointments[i].date.year==appointments[j].date.year)
			{	
				if(appointments[i].date.month>appointments[j].date.month)
				{
					temp=appointments[i];
					appointments[i]=appointments[j];
					appointments[j]=temp;

				}
			}
		}

	}


	for(i=0;i<size;++i)
	{
		for(j=i+1;j<size;++j)
		{
			if(appointments[i].date.month==appointments[j].date.month &&
			 appointments[i].date.year==appointments[j].date.year)
			{
				if(appointments[i].date.day>appointments[j].date.day)
				{
					temp=appointments[i];
					appointments[i]=appointments[j];
					appointments[j]=temp;

				}
			}
		}


	}
	
	for(i=0;i<size;++i)
	{
		for(j=i+1;j<size;++j)
		{
			if(appointments[i].date.day==appointments[j].date.day &&
			 appointments[i].date.month==appointments[j].date.month &&
			 appointments[i].date.year==appointments[j].date.year)
			{
				if(appointments[i].date.time.hour>appointments[j].date.time.hour)
				{
					temp=appointments[i];
					appointments[i]=appointments[j];
					appointments[j]=temp;

				}
			}
		}


	}

	for(i=0;i<size;++i)
	{
		for(j=i+1;j<size;++j)
		{
			if(appointments[i].date.time.hour==appointments[j].date.time.hour &&
 			   appointments[i].date.day==appointments[j].date.day && 
			appointments[i].date.month==appointments[j].date.month &&
				 appointments[i].date.year==appointments[j].date.year)
			{
				if(appointments[i].date.time.minute>appointments[j].date.time.minute)
				{
					temp=appointments[i];
					appointments[i]=appointments[j];
					appointments[j]=temp;

				}
			}
		}


	}	

}


void write_appointments(const char *file_name,Appointment_t appointments[],int size)
{
	FILE* input;
	int i;	
	input=fopen(file_name,"w");
	
	for(i=0;i<size;++i)
	{
	
		fprintf(input,"%d ",appointments[i].date.year);

		fprintf(input,"%d ",appointments[i].date.month);

		fprintf(input,"%d ",appointments[i].date.day);

		fprintf(input,"%d:",appointments[i].date.time.hour);

		if(appointments[i].date.time.minute==0)
		fprintf(input,"%d",appointments[i].date.time.minute);

		fprintf(input,"%d ",appointments[i].date.time.minute);

		fprintf(input,"%d",appointments[i].people.id_no.first_half);

		fprintf(input,"%d ",appointments[i].people.id_no.second_half);		

		fprintf(input,"%s ",appointments[i].people.name);

		fprintf(input,"%s ",appointments[i].people.surname);

		if(appointments[i].people.gender==MALE)
		fprintf(input,"M\n");

		else
		fprintf(input,"F\n");

	}

}

/*############################################################################*/
/*                HW08_AhmetEmin_Kaplan_131044042_part2.c                     */
/*############################################################################*/
