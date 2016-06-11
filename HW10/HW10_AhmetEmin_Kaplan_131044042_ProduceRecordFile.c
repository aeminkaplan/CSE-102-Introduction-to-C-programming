/*-----------------------------------------------------------------*/
/*HW10_AhmetEmin_Kaplan_131044042_ProduceRecordsFile.c             */
/*Records file olusturan programdir                                */
/*22 Mayis 2015 Ahmet Emin Kaplan tarafindan olusturulmustur       */
/*-----------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int app_id;
	int patient_id;
	int hour;
}Appointment_t;

int main()
{
	Appointment_t temp,temp2,temp3;
	int size;
	FILE* output;

	temp.app_id=5;
	temp.hour=11;
	temp.patient_id=11;

	temp2.app_id=3;
	temp2.hour=12;
	temp2.patient_id=8;

	
	temp3.app_id=6;
	temp3.hour=14;
	temp3.patient_id=9;
	
	size=3;

	
	output=fopen("Records.bin","wb");

	if(output==NULL)
	{
		printf("dosya acilamadi\n");
		exit(1);
	}	

	fwrite(&size,sizeof(int),1,output);
	fwrite(&temp,sizeof(Appointment_t),1,output);
	fwrite(&temp2,sizeof(Appointment_t),1,output);
	fwrite(&temp3,sizeof(Appointment_t),1,output);

	fclose(output);
}
