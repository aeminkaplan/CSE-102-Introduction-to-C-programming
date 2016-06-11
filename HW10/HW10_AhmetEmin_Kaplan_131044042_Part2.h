#include "HW10_AhmetEmin_Kaplan_131044042_Part1.h"

typedef struct node_s
{
	int app_id;
	int patient_id;
	char name[50];
	char* history;
	int hour;
	struct node_s* next;

}node_t;


extern node_t* build_ll(Appointment_t appointments[],int size,Working_hours_t* hours);
extern void add_personal_data(node_t* head,const Files_t* files);
extern int delete_appointments(node_t** head,const Files_t* files);
extern void write_accepted_app(node_t* head,const Files_t* files);
extern void free_list(node_t* head);

