#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct
{
	int app_id;
	int patient_id;
	int hour;
}Appointment_t;

typedef struct node_s
{
	int app_id;
	int patient_id;
	char name[50];
	char* history;
	int hour;
	struct node_s* next;

}node_t;

extern node_t* make_independent_copy_ll(node_t* head);
