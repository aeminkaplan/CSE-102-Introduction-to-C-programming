/*-----------------------------------------------------------------*/
/*HW10_AhmetEmin_Kaplan_131044042_Part3.c                          */
/*Header filede prototipi bulunan fonksiyonlarin tanimlarini icerir*/
/*22 Mayis 2015 Ahmet Emin Kaplan tarafindan olusturulmustur       */
/*-----------------------------------------------------------------*/
node_t* make_independent_copy_ll(node_t* head)
{
	node_t* temp=head;
	node_t* copyfirst;
	node_t* copyhead;
	

	if(temp!=NULL)
	{
	
		copyfirst=(node_t*)malloc(sizeof(node_t));

		copyfirst->app_id=temp->app_id;

		copyfirst->patient_id=temp->patient_id;
	
		copyfirst->hour=temp->hour;

		strcpy(copyfirst->name,temp->name);

		copyfirst->history=(char*)malloc(sizeof(char)*(strlen(temp->history)+1));

		strcpy(copyfirst->history,temp->history);

		copyfirst->next=NULL;

		copyhead=copyfirst;
		temp=temp->next;

		for(temp;temp!=NULL;temp=temp->next)	
		{
					
			copyfirst->next=(node_t*)malloc(sizeof(node_t));
			copyfirst->next->app_id=temp->app_id;
			copyfirst->next->patient_id=temp->patient_id;
			copyfirst->next->hour=temp->hour;
			strcpy(copyfirst->next->name,temp->name);
			copyfirst->next->history=(char*)malloc(sizeof(char)*(strlen(temp->history)+1));
			strcpy(copyfirst->next->history,temp->history);
			copyfirst=copyfirst->next;
			copyfirst->next=NULL;
		}
	
	}
	
	else
		copyhead=NULL;


	return copyhead;	
}
