/*-----------------------------------------------------------------*/
/*HW10_AhmetEmin_Kaplan_131044042_Part1.c                          */
/*Header filede prototipi bulunan fonksiyonlarin tanimlarini icerir*/
/*22 Mayis 2015 Ahmet Emin Kaplan tarafindan olusturulmustur       */
/*-----------------------------------------------------------------*/


#include "HW10_AhmetEmin_Kaplan_131044042_Part1.h"

const char* records_file="Records.bin";
const char* patients_file="Patients.xml";
const char* delete_file="Delete.txt";
const char* readable_records_file="Records.xml";
const char* accepted_appo_file="Appointments.csv";
const char* parameters_file="Parameters.txt";

/*Fonksiyona parametre olarak gonderilen files_t* tipindeki degisken ile records_file_n dosyasi okunur okunan ilk  deger integer olan size degeridir okunan size degeri kadar heap de yer olusturulur ve size degeri kadar appointment_t tipinde veri okuyup icine okuma yaptigi appointmen_t arrayinin ilk elemanini return eder*/

Appointment_t* getRequests(const Files_t* files,int* size)
{
	FILE* input;
	int i;

	
	Appointment_t* temp;
	
	input=fopen(files->records_file_n,"rb");

	if(input==NULL)
	{
		printf("Dosya acma hatasi!\n");
		exit(1);
	}
	
	
	fread(size,sizeof(int),1,input);
	
	temp=(Appointment_t*)malloc((*size)*sizeof(Appointment_t));

	for(i=0;i<*size;++i)
	{
		fread(&temp[i],sizeof(Appointment_t),1,input);	
	}
	
	fclose(input);

	return temp;
}


/*Odevde belirtilen formatta readable_records_file_n dosyasina yazma islemi yapilir*/
void write_appointments(Appointment_t appointments[],int size,const Files_t* files)
{
	FILE* output;

	int i;



	output=fopen(files->readable_records_file_n,"w");

	if(output==NULL)
	{
		printf("Dosya acma hatasi!\n");
		exit(1);
	}

	fprintf(output,"<Size>%d</Size>\n",size);

	fprintf(output,"<Records>\n");

	for(i=0;i<size;++i)
	{
		fprintf(output,"\t<Appointment>\n");
		fprintf(output,"\t\t<app_id>%d</app_id>\n",appointments[i].app_id);
		fprintf(output,"\t\t<patient_id>%d</patient_id>\n",appointments[i].patient_id);
		fprintf(output,"\t\t<hour>%d</hour>\n",appointments[i].hour);
		fprintf(output,"\t</Appointment>\n");
	}


	fprintf(output,"</Records>\n");
	

	fclose(output);
}

/*Main fonksiyonun argumanlarini kullanarak default olarak verilen dosya isimlerini degistirir oncelikle default degerleri dosya isimlerine atadiktan sonra komut satirindan maine arguman yollanip yollanmadigi kontrol eder eger arguman yollanmissa bu argumani analiz edip dosya ismini degistirir*/

void get_main_arguments(int argc,char *argv[],Working_hours_t* hours,Files_t* files)
{
	int i;	
	hours->start=START;
	hours->end=END;
	files->records_file_n=records_file;
	files->readable_records_file_n=readable_records_file;
	files->parameters_file_n=parameters_file;
	files->delete_file_n=delete_file;
	files->accepted_appo_file_n=accepted_appo_file;
	files->patients_file_n=patients_file;

	if(argc>1)
	{
		for(i=1;i<argc;++i)
		{
			if(i%2==1)
			{
				if(strcmp(argv[i],"-s")==0)
					sscanf(argv[i+1],"%d",&(hours->start));
				else if(strcmp(argv[i],"-e")==0)
					sscanf(argv[i+1],"%d",&(hours->end));
				else if(strcmp(argv[i],"-r")==0)
					files->records_file_n=argv[i+1];
				else if(strcmp(argv[i],"-x")==0)
					files->readable_records_file_n=argv[i+1];
				else if(strcmp(argv[i],"-t")==0)
					files->parameters_file_n=argv[i+1];				 
				else if(strcmp(argv[i],"-p")==0)
					files->patients_file_n=argv[i+1];
				else if(strcmp(argv[i],"-d")==0)
					files->delete_file_n=argv[i+1];
				else if(strcmp(argv[i],"-c")==0)
					files->accepted_appo_file_n=argv[i+1];

			}			
		}
	}
}

/*Program tarafindan kullanilan dosyalarin isimlerini ve baslangic-bitis parametrelerini dosyaya yazar*/
void print_parameters(const Files_t* files,const Working_hours_t* hours)
{

	FILE* output;

	


	output=fopen(files->parameters_file_n,"w");

	if(output==NULL)
	{
		printf("Dosya acma hatasi!\n");
		exit(1);
	}

	
	fprintf(output,"%s\n",files->parameters_file_n);

	fprintf(output,"%s\n",files->patients_file_n);

	fprintf(output,"%s\n",files->delete_file_n);

	fprintf(output,"%s\n",files->readable_records_file_n);

	fprintf(output,"%s\n",files->accepted_appo_file_n);

	fprintf(output,"%s\n",files->parameters_file_n);

	fprintf(output,"%d\n",hours->start);

	fprintf(output,"%d\n",hours->end);

	fclose(output);

	#if defined(DEBUG)
	printf("Program tarafindan kullanilan dosya ve parametreler->\n\n");		

	printf("records_file_n:%s\n\n",files->records_file_n);

	printf("patients_file_n:%s\n\n",files->patients_file_n);

	printf("delete_file_n:%s\n\n",files->delete_file_n);

	printf("readable_records_file_n:%s\n\n",files->readable_records_file_n);

	printf("accepted_appo_file_n:%s\n\n",files->accepted_appo_file_n);

	printf("parameters_file_n:%s\n\n",files->parameters_file_n);

	printf("Start:%d\n\n",hours->start);

	printf("End:%d\n\n",hours->end);

	#endif
}


/***************HW10_AhmetEmin_Kaplan_131044042_Part1.c*******************/

