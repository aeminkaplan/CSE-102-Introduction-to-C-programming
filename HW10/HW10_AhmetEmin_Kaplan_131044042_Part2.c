/*-----------------------------------------------------------------*/
/*HW10_AhmetEmin_Kaplan_131044042_Part2.c                          */
/*Header filede prototipi bulunan fonksiyonlarin tanimlarini icerir*/
/*22 Mayis 2015 Ahmet Emin Kaplan tarafindan olusturulmustur       */
/*-----------------------------------------------------------------*/
#include "HW10_AhmetEmin_Kaplan_131044042_Part2.h"


/*linkedlist te son bulunan degerleri belirtilen formatta dosyaya yazar*/
void write_accepted_app(node_t* head,const Files_t* files)
{
	node_t* temp;
	FILE* output;
	int i=1;
	temp=head;
	output=fopen(files->accepted_appo_file_n,"w");
	if(output==NULL)
	{
		printf("accepted_appo_file_n acilamadi!\n");
		exit(1);
	}
	#if defined(DEBUG)
	printf("no;id;patient_id;name;history;hour\n\n");
	#endif	
	fprintf(output,"no;id;patient_id;name;history;hour\n\n");

	for(temp;temp!=NULL;temp=temp->next)
	{
	fprintf(output,"%d;%d;%d;%s;%s;%d\n\n",i,temp->app_id,temp->patient_id,temp->name,temp->history,temp->hour);

	#if defined(DEBUG)
	printf("%d;%d;%d;%s;%s;%d\n\n",i,temp->app_id,temp->patient_id,temp->name,temp->history,temp->hour);
	#endif	
	++i;
	}

	fclose(output);

}

/*delete filedan okunan degerleri linklist uzerinde arar eger aranan deger linkistin ilk nodundaysa ilk nodun nexti linkiste head olarak atanir eger deger ortadaysa bir onceki nod bir sonrakine baglanir*/

int delete_appointments(node_t** head,const Files_t* files)
{
	node_t* first=*head;
	node_t* previous;	
	int counter=0;
	int number;
	FILE* input;
	input=fopen(files->delete_file_n,"r");
	
	if(input==NULL)
	{
		printf("delete_file_n acilamadi!\n");
		exit(1);
	}

	while(fscanf(input,"%d",&number)!=EOF)
	{
		if(first->app_id==number)
		{	
			*head=first->next;
			free(first);			
			++counter;
		}

		else	
		{
			for(first;first!=NULL;first=first->next)
			{
				if(first->app_id==number)
				{
					previous->next=first->next;
					free(first);
					++counter;
				}
					
				previous=first;
			}

		}


		first=*head;
	}

	fclose(input);
	return counter;
}
/*linked listte bulunan name ve history memberlarina dosyadan okunan degerleri atar dosyadan okumayi karakter karakter yapar </Records> tagi okuma islemini bitiren degerdir */
void add_personal_data(node_t* head,const Files_t* files)
{	
	node_t* first=head;
	FILE* input;

	char temp_name[20];
	char temp_history[150];
	char temp_id[10];
	char junk[50];
	char one;
	int i;
	int patient_id;
	input=fopen(files->patients_file_n,"r");
	if(input==NULL)
	{
		printf("patient_file_n acilamadi!\n");
		exit(1);
	}	
	
	fscanf(input,"%s",junk);
	fscanf(input,"%s",junk);
	while(strcmp(junk,"</Records>")!=0)
	{
		fscanf(input,"%c",&one);
		while(one!='>')
		fscanf(input,"%c",&one);
		
		i=0;
		
		fscanf(input,"%c",&temp_id[i]);
		while(temp_id[i]!='<')
		{
			++i;
			fscanf(input,"%c",&temp_id[i]);
			
		}
		temp_id[i]='\0';

		sscanf(temp_id,"%d",&patient_id);

		fscanf(input,"%c",&one);
		while(one!='\n')
		fscanf(input,"%c",&one);

		fscanf(input,"%c",&one);
		while(one!='>')
		fscanf(input,"%c",&one);
		
		i=0;
		fscanf(input,"%c",&temp_name[i]);
		while(temp_name[i]!='<')
		{
			++i;
			fscanf(input,"%c",&temp_name[i]);
			
		}
		temp_name[i]='\0';
	
		

		fscanf(input,"%c",&one);
		while(one!='\n')
		fscanf(input,"%c",&one);

		fscanf(input,"%c",&one);
		while(one!='>')
		fscanf(input,"%c",&one);
		
		i=0;
		fscanf(input,"%c",&temp_history[i]);
		while(temp_history[i]!='<')
		{
			++i;
			fscanf(input,"%c",&temp_history[i]);
			
		}
		temp_history[i]='\0';
	
		

		fscanf(input,"%c",&one);
		while(one!='\n')
		fscanf(input,"%c",&one);

		for(first;first!=NULL;first=first->next)
		{
			if(first->patient_id==patient_id)
			{
				strcpy(first->name,temp_name);
				first->history=(char*)malloc(sizeof(char)*(strlen(temp_history)+1));
				strcpy(first->history,temp_history);			
			}		

		}

		first=head;

		fscanf(input,"%s",junk);
		fscanf(input,"%s",junk);
	}

	fclose(input);
}

/*Fonksiyona parametre olarak yollanan arrayin elemanlarinin randevu saatleri kontrol edilerek calisma saatleri araliginde olup olmadigi kontrol edilir eger calisma saatinin disindaysa veya dolu bir randevu saatindeyse o arrayin hour memberina 999 atanir ve array kendi icinden kucukten buyuge siralaninca bu degerler silinmis olur geriye kalan arrayin elemanlari hicin linkedlist olusturulur*/

node_t* build_ll(Appointment_t appointments[],int size,Working_hours_t* hours)
{
	int i,k,deleted=0;
	int delete=999;
	Appointment_t temp;
	node_t* first;	
	node_t* head;

	for(i=0;i<size;++i)
	{
		if(appointments[i].hour<(hours->start) || appointments[i].hour>=(hours->end))
		{
			appointments[i].hour=delete;
			++deleted;
		}


		for(k=0;k<i;++k)
		{
			if(appointments[i].hour==appointments[k].hour && appointments[i].hour!=delete)
			{
				appointments[i].hour=delete;
				++deleted;
			}
		}

	}

	for(i=0;i<size;++i)
		for(k=i+1;k<size;++k)
		{
			if(appointments[i].hour>appointments[k].hour)
			{
				temp=appointments[i];
				appointments[i]=appointments[k];
				appointments[k]=temp;
				
			}
		}




	size=size-deleted;
	
	#if defined(DEBUG)
	printf("\nCalisma saatlerine uymadigindan veya dolu randevu saati sebebiyle silinen kayit sayisi:%d\n",deleted);	
	#endif
	if(size>0)
	{
		first=(node_t*)malloc(sizeof(node_t));
		first->app_id=appointments[0].app_id;
		first->hour=appointments[0].hour;
		first->patient_id=appointments[0].patient_id;
		first->next=NULL;
		head=first;

		for(i=1;i<size;++i)
		{
			first->next=(node_t*)malloc(sizeof(node_t));
			first->next->app_id=appointments[i].app_id;
			first->next->hour=appointments[i].hour;
			first->next->patient_id=appointments[i].patient_id;
			first=first->next;
			first->next=NULL;
		}



	}

	else
		head=NULL;

	return head;

}




/*Butun linklist icin ayrilan alani free eder*/

void free_list(node_t* head)
{
	node_t* temp;
	temp=head;
	for(temp;temp!=NULL;temp=temp->next)
	{
		free(temp);
		free(temp->history);
	}
}

