/*############################################################################*/
/*HW06_AhmetEmin_Kaplan_131044042_part1.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 5 Nisan,2015                                   */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/* 4 Isci icin her gun 1 is olmak uzere 28 isi adaletli bir sekilde dagitir   */
/*                                                                            */
/*Inputlar:                                                                   */
/* -Dosyadan alinmak uzere 28 is icin 28 enerji degeri                        */
/*                                                                            */
/*Outputlar:                                                                  */ 
/* -Schedule matrisi gunlere gore is dagilimi                                 */
/* -Her gun icin en cok is yapan eleman                                       */
/* -Haftanin en cok is yapan elemani                                          */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/





#include<stdio.h>
#include<string.h>
#define NUM_EMPLOYEES 4
#define NUM_DAYS 7





/*Calisanlari ve Haftanin gunlerini yeni birer tipte tanimladim*/

typedef enum{Ali,Ayse,Fatma,Mehmet} employee;

typedef enum{Monday,Tuesday,Wednesday,Thursday,
Friday,Saturday,Sunday} day;


/*Fonkisyon prototipleri*/

void read_matrix(const char* file_name,int m[NUM_EMPLOYEES][NUM_DAYS]);

void create_work_plan(int job_schedule[NUM_EMPLOYEES][NUM_DAYS],int m[NUM_EMPLOYEES][NUM_DAYS]);

employee find_the_employer_of_the_day(int work_schedule[NUM_EMPLOYEES][NUM_DAYS],day day_name);

employee find_the_employer_of_the_week(int work_schedule[NUM_EMPLOYEES][NUM_DAYS]);

void report(const char* file_name,int job_scheduling[][NUM_DAYS]);






int main()
{
	int i,k;
   	int job_energies[NUM_EMPLOYEES][NUM_DAYS];
	int job_schedule[NUM_EMPLOYEES][NUM_DAYS];
	employee emp;
	day day_name=Monday;

/*Oncelikle schedule edecegim matrisin butun elemanlarini sifir yaptim*/

	for(i=0;i<NUM_EMPLOYEES;++i)
	{

		for(k=0;k<NUM_DAYS;++k)
		{
			job_schedule[i][k]=0;
		}
		
	}
	
	/*Dosyadan Enerji degerlerini okuyoruz*/

	read_matrix("Energies.txt",job_energies);


	/*Okudugumuz enerji degerlerini bu fonksiyonun icinde kullanarak 
		schedule matrisine atayacagiz*/
	create_work_plan(job_schedule,job_energies);


	/*Schedule matrisini doldurduktan sonra dosyaya 
	yazmasi gerekenleri report fonksiyonu yazacak*/
	report("Report.txt",job_schedule);	
	
}





void create_work_plan(int job_schedule[NUM_EMPLOYEES][NUM_DAYS],int m[NUM_EMPLOYEES][NUM_DAYS])
{

	int temp;

	int tmp;

	int i,k,t,z,n,f,g;

	int total_work[NUM_EMPLOYEES];

	int total_work_sort[NUM_EMPLOYEES]={0,1,2,3};

	/*Oncelikle okudugum enerji degerlerinin icinde barindiran 
	matrisin her sutununu buyukten kucuge dizdim kolayca atama yapmak icin*/
	
	for(t=0;t<NUM_DAYS;++t)
	{
		for(i=0;i<NUM_EMPLOYEES-1;++i)
		{
		
			for(k=i+1;k<NUM_EMPLOYEES;++k)
			{	
				if(m[k][t]>m[i][t])
				{
					temp=m[i][t];
					m[i][t]=m[k][t];
					m[k][t]=temp;
				}
			}
		}	
	}




for(z=0;z<NUM_DAYS;++z)
{

/*Her gun icin iscilerin o gune kadar toplam harcadigi enerjiyi hesapliyorum*/

	for(i=0;i<NUM_EMPLOYEES;++i)
	{
		total_work[i]=0;

		for(k=0;k<NUM_DAYS;++k)
		{
			total_work[i]=total_work[i]+job_schedule[i][k];

		}



	}

/*Her işçinin yaptığı toplam işe göre küçükten büyüğe  sıralanınca direk ekleyecem*/

/*Dongu her dondugunde indexler hic degistirilmemis gibi assign ediyorum  */

			total_work_sort[0]=0;
			total_work_sort[1]=1;
			total_work_sort[2]=2;
			total_work_sort[3]=3;



	for(n=0;n<NUM_EMPLOYEES;++n)
	{

		

		for(f=n+1;f<NUM_EMPLOYEES;++f)
		{
			


			/*Toplam yapilan isleri kucukten buyuge siraliyorum cunkü atanacak 
			yeni isler buyukten kucuge siralanmis durumda ve yeni atanacak islerin 
			adreslerini degistiriyorum*/
			if(total_work[n]>total_work[f])
			{
				temp=total_work[n];

				tmp=total_work_sort[n];

				total_work[n]=total_work[f];

				total_work_sort[n]=total_work_sort[f];
	
				total_work[f]=temp;

				total_work_sort[f]=tmp;
				
			}
			

		}


	}
	
	/*Yeni atanacak islerin minimum toplam is yapan kisiye maksimum isin atanmasi isin siraladigim toplam is indexlerini kullaniyorum burada dolayisiyla adaletli is dagitimi yapiliyor*/
	for(g=0;g<NUM_EMPLOYEES;++g)
	{
		
		job_schedule[total_work_sort[g]][z]=m[g][z];
	}



}


}

/* Gunun en cok is yapan elemanini return eden fonksiyon schedule matrisinde
 ayni sutunun butun satirlarini kontrol edip maksimum is yapan elemani buluyor*/


employee find_the_employer_of_the_day(int work_schedule[NUM_EMPLOYEES][NUM_DAYS],day day_name)
{

	employee hard_working;

	int max_energy=0;

	int max_index;

	int i;

	for(i=0;i<NUM_EMPLOYEES;++i)
	{
		if(work_schedule[i][day_name]>max_energy)
		{
			max_energy=work_schedule[i][day_name];

			max_index=i;
		
		}

	}
	
	hard_working=(employee)max_index;

	return hard_working;
}
/*Her elemanin hafta boyunca yaptigi toplam isleri kiyaslayip 
maksimum toplam ise sahip elemani bulan fonksiyon*/

employee find_the_employer_of_the_week(int work_schedule[NUM_EMPLOYEES][NUM_DAYS])
{	
	employee hard_working;

	int i,k;

	int max_total_work=0;

	int max_Emp=0;

	int total_work;

	for(i=0;i<NUM_EMPLOYEES;++i)
	{	
		total_work=0;

		for(k=0;k<NUM_DAYS;++k)
		{
			total_work=total_work+work_schedule[i][k];
					
		}
		if(total_work>max_total_work)
		{
			max_total_work=total_work;	

			max_Emp=i;
		}
	}
	hard_working=(employee) max_Emp;
	
	return hard_working;
}
/*Her gun icin bulunan maksimum is yapan elemani ic ice switch case ile dosyaya yazdiriyorum
ve gun bilgisini tutan degisken her seferinde 1 artarak bir gun sonra icin sonuc veriyor
*/


void report(const char* file_name,int job_scheduling[][NUM_DAYS])
{
	int i,k,z=1;

	day day_name=Monday;

	employee employee_day,employee_week;

	FILE* output;
	output=fopen(file_name,"w");

	fprintf(output,"Report:\n\n");

	fprintf(output,"  \tMonday Tuesday Wednesday Thursday Friday Saturday Sunday\n");
	
	for(i=0;i<NUM_EMPLOYEES;++i)
	{	
		if(i==0)
			fprintf(output,"Ali");
		else if(i==1)
			fprintf(output,"Ayse");
		else if(i==2)
			fprintf(output,"Fatma");
		else if(i==3)
			fprintf(output,"Mehmet");
		
		for(k=0;k<NUM_DAYS;++k)
		{	
			
			if(z==1){fprintf(output,"\t"); z=0;}
			fprintf(output,"\t%d\t",job_scheduling[i][k]);
		
		}
			
		fprintf(output,"\n");	
	}

	for(i=0;i<NUM_DAYS;++i)
	{

		employee_day=find_the_employer_of_the_day(job_scheduling,day_name);

		switch(day_name)
		{
			case(Monday):switch(employee_day){
							case(Ali):fprintf(output,"The best employee of Monday: Ali\n");
									break;
							case(Ayse):fprintf(output,"The best employee of Monday: Ayse\n");
									break;
							case(Fatma):fprintf(output,"The best employee of Monday: Fatma\n");
									break;
							case(Mehmet):fprintf(output,"The best employee of Monday: Mehmet\n");
							}
			break;
			case(Tuesday):switch(employee_day){
							case(Ali):fprintf(output,"The best employee of Tuesday: Ali\n");
									break;
							case(Ayse):fprintf(output,"The best employee of Tuesday: Ayse\n");
									break;
							case(Fatma):fprintf(output,"The best employee of Tuesday: Fatma\n");
									break;
							case(Mehmet):fprintf(output,"The best employee of Tuesday: Mehmet\n");
							}
			break;
			case(Wednesday):switch(employee_day){
							case(Ali):fprintf(output,"The best employee of Wednesday: Ali\n");
									break;
							case(Ayse):fprintf(output,"The best employee of Wednesday: Ayse\n");
									break;
							case(Fatma):fprintf(output,"The best employee of Wednesday: Fatma\n");
									break;
							case(Mehmet):fprintf(output,"The best employee of Wednesday: Mehmet\n");
							}
	
			case(Thursday):switch(employee_day){
							case(Ali):fprintf(output,"The best employee of Thursday: Ali\n");
									break;
							case(Ayse):fprintf(output,"The best employee of Thursday: Ayse\n");
									break;
							case(Fatma):fprintf(output,"The best employee of Thursday: Fatma\n");
									break;
							case(Mehmet):fprintf(output,"The best employee of Thursday: Mehmet\n");
							}
			break;
			case(Friday):switch(employee_day){
							case(Ali):fprintf(output,"The best employee of Friday: Ali\n");
									break;
							case(Ayse):fprintf(output,"The best employee of Friday: Ayse\n");
									break;
							case(Fatma):fprintf(output,"The best employee of Friday: Fatma\n");
									break;
							case(Mehmet):fprintf(output,"The best employee of Friday: Mehmet\n");
							}
			break;
			case(Saturday):switch(employee_day){
							case(Ali):fprintf(output,"The best employee of Saturday: Ali\n");
									break;
							case(Ayse):fprintf(output,"The best employee of Saturday: Ayse\n");
									break;
							case(Fatma):fprintf(output,"The best employee of Saturday: Fatma\n");
									break;
							case(Mehmet):fprintf(output,"The best employee of Saturday: Mehmet\n");
							}
	
			break;
			case(Sunday):switch(employee_day){
							case(Ali):fprintf(output,"The best employee of Sunday: Ali\n");
									break;
							case(Ayse):fprintf(output,"The best employee of Sunday: Ayse\n");
									break;
							case(Fatma):fprintf(output,"The best employee of Sunday: Fatma\n");
									break;
							case(Mehmet):fprintf(output,"The best employee of Sunday: Mehmet\n");
							}
	
		}
	
	
			day_name=day_name+1;
		
		}
	
	employee_week=find_the_employer_of_the_week(job_scheduling);

	switch(employee_week)
	{	
		case Ali:
			fprintf(output,"The best employee of week: Ali ... Congratulations Ali !!\n");
			break;
		case Ayse:
			fprintf(output,"The best employee of week: Ayse ... Congratulations Ayse !!\n");
			break;
		case Fatma:
			fprintf(output,"The best employee of week: Fatma ... Congratulations Fatma !!\n");
			break;
		case Mehmet:
			fprintf(output,"The best employee of week: Mehmet ... Congratulations Mehmet !!\n");
					
	}
	
	fclose(output);
}


/* read_matrix fonksiyonu dosyadan enerji degerlerini 
 belirliten matrisin üzerine okuyacak */

void read_matrix(const char* file_name,int m[NUM_EMPLOYEES][NUM_DAYS])
{
	int i,k;

	FILE* input;

	input=fopen(file_name,"r");

	for(i=0;i<NUM_DAYS;++i)
	{

		for(k=0;k<NUM_EMPLOYEES;++k)
		{
			fscanf(input,"%d",&m[k][i]);
		}
	
	}

	fclose(input);
}



/*############################################################################*/
/*				HW06_AhmetEmin_Kaplan_131044042_part1.c                       */
/*############################################################################*/
