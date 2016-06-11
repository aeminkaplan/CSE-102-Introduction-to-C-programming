/*----------------------------------------------------------*/
/*HW10_AhmetEmin_Kaplan_131044042_part1.h                   */
/*Fonksiyon prototipleri,kutuphane include lari icerir      */
/*22 Mayis 2015 Ahmet Emin Kaplan tarafindan olusturulmustur*/
/*----------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define START 9
#define END 17
#define DEBUG

typedef struct
{
	int app_id;
	int patient_id;
	int hour;
}Appointment_t;

typedef struct
{
	int start;
	int end;

}Working_hours_t;

typedef struct
{
	const char* records_file_n;
	const char* patients_file_n;
	const char* delete_file_n;
	const char* readable_records_file_n;
	const char* accepted_appo_file_n;
	const char* parameters_file_n;
}Files_t;

/*Global degisken olarak tanimlanan dosya isimleri*/

extern const char* records_file;
extern const char* patients_file;
extern const char* delete_file;
extern const char* readable_records_file;
extern const char* accepted_appo_file;
extern const char* parameters_file;	

/*Fonksiyon prototipleri*/

extern Appointment_t* getRequests(const Files_t* files,int* size);
extern void write_appointments(Appointment_t appointments[],int size,const Files_t* files);
extern void get_main_arguments(int argc,char *argv[],Working_hours_t* hours,Files_t* files);
extern void print_parameters(const Files_t*,const Working_hours_t* hours);


/***********HW10_AhmetEmin_Kaplan_131044042_part1.h***************/
