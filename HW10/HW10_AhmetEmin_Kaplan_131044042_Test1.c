/*-----------------------------------------------------------------*/
/*HW10_AhmetEmin_Kaplan_131044042_Test1.c                          */
/*Main fonksiyonunu icerir                                         */
/*22 Mayis 2015 Ahmet Emin Kaplan tarafindan olusturulmustur       */
/*-----------------------------------------------------------------*/


#include "HW10_AhmetEmin_Kaplan_131044042_Part1.h"



int main(int argc,char *argv[])
{
	int size,i;


	Appointment_t* appointments;

	Files_t files;

	Working_hours_t hours;

	get_main_arguments(argc,argv,&hours,&files);
	

	appointments=getRequests(&files,&size);


	#if defined(DEBUG)
		
	printf("%s dosyasindan okunan degerler->\n\n",files.records_file_n);	
	printf("size:%d\n",size);
	for(i=0;i<size;++i)
	{
		printf("App_id:%d ",appointments[i].app_id);
		printf("Hour:%d ",appointments[i].hour);
		printf("Patient_id:%d\n",appointments[i].patient_id);
	}
	printf("\n");
	#endif


	write_appointments(appointments,size,&files);


	print_parameters(&files,&hours);
}


/**********HW10_AhmetEmin_Kaplan_131044042_Test1.c****************/

