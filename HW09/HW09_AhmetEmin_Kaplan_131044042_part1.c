/*############################################################################*/
/*HW09_AhmetEmin_Kaplan_131044042_part1.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 29 Nisan,2015                                  */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/*Dosyadan alınan isci veya ogretim uyelerinin maaslarina zam yapar           */
/*                                                                            */
/*Inputlar:                                                                   */
/* -Isci veya ogretim uyesinin isim,soyisim,ders,departman ve maas bilgisi    */
/*Outputlar:                                                                  */ 
/* -Guncellenmis maas ve kisi bilgileri                                       */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/
#include<stdio.h>

#include<string.h>

#define NUMBER_OF_PEOPLE 5
/*insan sayisini macro olarak tanimladim*/

typedef struct
{
	char name[20];
	char surname[20];
	char department[30];
	char class1[30];
	char class2[30];
	double salary;
} type_I;

typedef struct
{
	char name[20];
	char surname[20];
	double salary;
	char department[30];
	char degree;
} type_E;

typedef union
{
	type_I Instructor;
	type_E Employee;
} Unitype;

typedef struct
{
	Unitype people;
	char type;
} combine_type;



combine_type salary_rise(combine_type person_info);

void get_information_and_update_salary(const char* input_file_name,const char* output_file_name);

int main()
{


	get_information_and_update_salary("person_information.txt","Updated_informations.bin");
	return 0;	
}


/*Dosyadan verileri fgets fonksiyonuyla aldiktan sonra strtok ile boluyorum her virgul
 araliklari ayri parcalar seklinde*/
void get_information_and_update_salary(const char* input_file_name,const char* output_file_name)
{
	FILE *input;
	
	FILE *output;

	int i;

	combine_type person[NUMBER_OF_PEOPLE];

	char temp[80];

	char* temp2;

	input=fopen(input_file_name,"r");
	
	if(input==NULL)
	{
		printf("File couldnt be opened !\n");
	
	}

	output=fopen(output_file_name,"wb");
	
	if(output==NULL)	
	{
		printf("File couldnt be opened !\n");

	}


	
	for(i=0;i<NUMBER_OF_PEOPLE;++i)
	{
		fgets(temp,80,input);

		temp2=strtok(temp,",");

		if(temp2[0]=='I')
		{

			person[i].type='I';

			temp2=strtok(NULL," ");

	 		strcpy(person[i].people.Instructor.name,temp2);

			temp2=strtok(NULL,",");
		
			strcpy(person[i].people.Instructor.surname,temp2);

			temp2=strtok(NULL,",");

			strcpy(person[i].people.Instructor.department,temp2);

			temp2=strtok(NULL,",");

			strcpy(person[i].people.Instructor.class1,temp2);

			temp2=strtok(NULL,",");

			strcpy(person[i].people.Instructor.class2,temp2);

			temp2=strtok(NULL,"\n");

			sscanf(temp2,"%lf",&person[i].people.Instructor.salary);	

			person[i]=salary_rise(person[i]);

		/*Maas guncellendiktensonra ekrana basiyorum kolayla tahlil edebilmek icin*/

			printf("%s %s %s %s %s %.2f\n",person[i].people.Instructor.name
									,person[i].people.Instructor.surname
								,person[i].people.Instructor.department
							,person[i].people.Instructor.class1
							,person[i].people.Instructor.class2
							,person[i].people.Instructor.salary	);


	/*Binary file yazma islemi*/

	fwrite(person[i].people.Instructor.name,sizeof(char),strlen(person[i].people.Instructor.name),output);

	fwrite(person[i].people.Instructor.surname,sizeof(char),strlen(person[i].people.Instructor.surname),output);

	fwrite(person[i].people.Instructor.department,sizeof(char),strlen(person[i].people.Instructor.department),output);

	fwrite(&person[i].people.Instructor.class1,sizeof(char),strlen(person[i].people.Instructor.class1),output);

	fwrite(&person[i].people.Instructor.class2,sizeof(char),strlen(person[i].people.Instructor.class2),output);

 	fwrite(&person[i].people.Instructor.salary,sizeof(double),1,output);
	
	}
		
		if(temp2[0]=='E')
		{
		person[i].type='E';
		
		temp2=strtok(NULL," ");

		strcpy(person[i].people.Employee.name,temp2);

		temp2=strtok(NULL,",");

		strcpy(person[i].people.Employee.surname,temp2);

		temp2=strtok(NULL,",");

		sscanf(temp2,"%lf",&person[i].people.Employee.salary);

		temp2=strtok(NULL,"\n");

		sscanf(temp2,"%c",&person[i].people.Employee.degree);	

		person[i]=salary_rise(person[i]);

		printf("%s %s %.2f %c\n",person[i].people.Employee.name
							,person[i].people.Employee.surname
							,person[i].people.Employee.salary
							,person[i].people.Employee.degree);	

		fwrite(person[i].people.Employee.name,sizeof(char),strlen(person[i].people.Employee.name),output);

		fwrite(person[i].people.Employee.surname,sizeof(char),strlen(person[i].people.Employee.surname),output);

		fwrite(&person[i].people.Employee.salary,sizeof(double),1,output);

		fwrite(&person[i].people.Employee.degree,sizeof(char),1,output);

		}

		
	}


	fclose(input);
	fclose(output);




}

/*Maaslari guncelledigim fonksiyon*/

combine_type salary_rise(combine_type person_info)
{
	
	double temp;
	combine_type result;

	result=person_info;	

	if(person_info.type=='I')
	{
		temp=person_info.people.Instructor.salary;
		temp=temp*(105.3/100)*(105.0/100);	
		result.people.Instructor.salary=temp;

	}


	if(person_info.type=='E')
	{
		temp=person_info.people.Employee.salary;
		if(person_info.people.Employee.degree=='a')
			temp=temp*(117.5/100);
		else if(person_info.people.Employee.degree=='b')
			temp=temp*(112.0/100);	
		else if(person_info.people.Employee.degree=='c')
			temp=temp*(109.0/100);

		result.people.Employee.salary=temp;
	}
	
	return result;
	
}


/*############################################################################*/
/*              HW09_AhmetEmin_Kaplan_131044042_part1.c                       */
/*############################################################################*/
