/*-----------------------------------------------------------------*/
/*HW10_AhmetEmin_Kaplan_131044042_Test2.c                          */
/*Main fonksiyonunu icerir                                         */
/*22 Mayis 2015 Ahmet Emin Kaplan tarafindan olusturulmustur       */
/*-----------------------------------------------------------------*/

#include "HW10_AhmetEmin_Kaplan_131044042_Part2.h"
/*PART1 deki fonksiyonlardan bazilarini icerdigi icin part1 ile beraber compile edilmelidir*/

int main(int argc,char *argv[])
{	
	Appointment_t* appointments;
	int size;
	node_t* list;
	Files_t files;
	Working_hours_t hours;
	int deleted;

	get_main_arguments(argc,argv,&hours,&files);

	appointments=getRequests(&files,&size);


	list=build_ll(appointments,size,&hours);

	add_personal_data(list,&files);

	deleted=delete_appointments(&list,&files);

	#if defined(DEBUG)
	printf("%s dosyasindan okunan degerler dogrultusunda silinen kayit sayisi:%d\n\n",files.delete_file_n,deleted);
	#endif
	write_accepted_app(list,&files);

	free_list(list);
}
