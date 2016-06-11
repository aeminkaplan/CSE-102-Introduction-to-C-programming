
/*-----------------------------------------------------------------*/
/*HW10_AhmetEmin_Kaplan_131044042_Test3.c                          */
/*Main fonksiyonunu icerir                                         */
/*22 Mayis 2015 Ahmet Emin Kaplan tarafindan olusturulmustur       */
/*-----------------------------------------------------------------*/


#include "HW10_AhmetEmin_Kaplan_131044042_Part3.h"


int main()
{
	

	node_t a;
	node_t b;
	node_t c;
	
	node_t* temp;
	node_t* temp2;

	a.next=&b;
	b.next=&c;
	c.next=NULL;

	a.app_id=1;
	a.patient_id=11;
	a.history="ahmet";

	b.app_id=2;
	b.patient_id=12;
	b.history="emin";

	c.app_id=3;	
	c.patient_id=13;
	c.history="kaplan";

	temp=&a;

	temp2=make_independent_copy_ll(temp);	
	
		
	temp2->app_id=9;
	temp2->patient_id=19;
	temp2->history="abcde";

	temp2->next->app_id=8;
	temp2->next->patient_id=18;
	temp2->next->history="efghj";

	temp2->next->next->app_id=7;
	temp2->next->next->patient_id=17;
	temp2->next->next->history="klmloto";

	for(temp;temp!=NULL;temp=temp->next)
	printf("temp--app_id:%d patient_id:%d s:%s \n",temp->app_id,temp->patient_id,temp->history);

	
	
	for(temp2;temp2!=NULL;temp2=temp2->next)
	printf("temp2---app_id:%d patient_id:%d s:%s\n",temp2->app_id,temp2->patient_id,temp2->history);

	

}




