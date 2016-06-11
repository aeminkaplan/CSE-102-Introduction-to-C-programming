/*############################################################################*/
/*HW08_AhmetEmin_Kaplan_131044042_part1.c                                     */
/*                                                                            */
/*__________________________________                                          */
/*                                                                            */
/*Ahmet Emin Kaplan tarafindan 22 Nisan,2015                                  */
/*                                                                            */
/*Tanim                                                                       */
/*__________                                                                  */
/*2 Boyutlu bir arrayde maksimum toplam elemana sahip dikdortgeni bulur       */
/*                                                                            */
/*Inputlar:                                                                   */
/*2 Boyutlu array                                                             */
/*Outputlar:                                                                  */ 
/* -Maksimum toplam elemana sahip dikdortgenin kose kordinatlari              */
/* -Maksimum toplam elemana sahip dikdortgenin elemanlari toplami             */
/*############################################################################*/
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                 Includes                                   */
/*----------------------------------------------------------------------------*/


#include<stdio.h>

typedef struct
{
	int x;

	int y;
} Point_t;
typedef struct
{
	Point_t left_up;

	Point_t right_down;

	double sum;
} Rectangle_t;

#define COL_COUNT 8
#define ROW_CAP 10

Point_t construct_point(int x, int y);

Rectangle_t construct_rectangle(Point_t left_up, Point_t right_down);

void print_rectangle(const Rectangle_t *rectangle);

void getArray(FILE* inFile, double table[][COL_COUNT], int* nRow);

void getSum(double table[][COL_COUNT], Rectangle_t *rectangle);

Rectangle_t maxSumConstPoint(double table[][COL_COUNT], int nRow, Point_t left_up);

Rectangle_t maxSumRec(double table[][COL_COUNT], int nRow);

int main()
{

	double table[ROW_CAP][COL_COUNT];
	FILE* inFile;
	int nRow;

	Rectangle_t Max_rectangle;

	Point_t Origin;

	Origin=construct_point(0,0);

	inFile=fopen("Table1.txt", "r");

	getArray(inFile, table, &nRow);

	Max_rectangle=maxSumConstPoint(table, nRow,Origin);

	printf("MaxSum Rectangular starting from origin is %.2f. Its right down coordinate (y,x) is %d,%d\n",Max_rectangle.sum, Max_rectangle.right_down.y,Max_rectangle.right_down.x);
	
	Max_rectangle=maxSumRec(table, nRow);

	printf("MaxSum Rectangular is %.2f Its left upper coordinate (y,x) is %d, %d, right down coordinate is %d, %d\n", Max_rectangle.sum,Max_rectangle.left_up.y,Max_rectangle.left_up.x,Max_rectangle.right_down.y,Max_rectangle.right_down.x);



	fclose(inFile);
	return 0;
}

/*Reads the table from a file into a 2D array*/
void getArray(FILE* inFile, double table[][COL_COUNT], int* nRow){
	int row=0;
	int col;
	int status=EOF+1;/*Different from EOF*/

	/*one more row will be read but the values will not be recorded into the table
	therefore, it is safe to use a table having just enough capasity to hold the data*/
	while(status!=EOF){
		for(col=0; col<COL_COUNT; col++)
			status=fscanf(inFile, "%lf", &table[row][col]);
		++row;
	}

	*nRow=row-1;/*one more row read*/
}

/*Returns the sum inside a given rectangular*/
void getSum(double table[][COL_COUNT], Rectangle_t *rectangle)
{	
	
	int row, col;
	double e;

	rectangle->sum=0;
	
	e=rectangle->sum;

	for(row=rectangle->left_up.y;row<=rectangle->right_down.y; ++row)
		for(col=rectangle->left_up.x; col<=rectangle->right_down.x; ++col)
	
			e=e+table[row][col];
			
		
	rectangle->sum=e;
}

/*Finds the rectangular left uppper point of which is specified having the max sum inside*/
Rectangle_t maxSumConstPoint(double table[][COL_COUNT], int nRow, Point_t left_up)
{
	int rDX;	/*x coordinate of the right down corner of the rec*/

	int rDY;	/*y coordinate of the right down corner of the rec*/
	/*initialize the rectangular with the one including only one point*/

	Rectangle_t Result;	

	Rectangle_t temp;

	Result.sum=table[left_up.x][left_up.y];

	temp.left_up.y=left_up.y;

	temp.left_up.x=left_up.x;

	/*Try all feasible rectangulars by changing the right down corner*/
	for(rDY=left_up.y; rDY<nRow; ++rDY)
	{
		for(rDX=left_up.x; rDX<COL_COUNT; ++rDX)
		{
			temp.right_down.y=rDY;

			temp.right_down.x=rDX;

			getSum(table,&temp);

			if(temp.sum>Result.sum)
			{
				/*a better rectangular is found, perform an update */
				Result=temp;			
			}
		}
	}

	return Result;
}


Rectangle_t maxSumRec(double table[][COL_COUNT], int nRow)
{

	Point_t Reference;

	int lUY, lUX;	/*coordinates of the left upper corner*/

	int rDY, rDX;	/*coordinates of the right down corner*/

	/*initialize the rectangular with the one including only origin point*/

	Rectangle_t Result;

	Rectangle_t temp;

	Result.sum=table[0][0];		

	Result.left_up.y=0;

	Result.left_up.x=0;

	Result.right_down.x=0;

	Result.right_down.y=0;
	/*For all feasible starting points call maxSumConstPoint*/
	for(lUY=0; lUY<nRow; ++lUY)
	{
		for(lUX=0; lUX<COL_COUNT; ++lUX)
		{
			
			Reference=construct_point(lUX,lUY);

			temp=maxSumConstPoint(table, nRow,Reference);
						
			if(temp.sum>Result.sum)
			{
				/*a better rectangular found, perform an update*/
				Result.sum=temp.sum;

				Result.left_up.y=lUY;

				Result.left_up.x=lUX;

				Result.right_down.y=temp.right_down.y;

				Result.right_down.x=temp.right_down.x;

			}
		}
	
	}	
	return Result;
}

Point_t construct_point(int x, int y)
{
	Point_t temp;
	
	temp.x=x;

	temp.y=y;

	return temp;
}



Rectangle_t construct_rectangle(Point_t left_up, Point_t right_down)
{
	Rectangle_t temp;
	
	temp.left_up=left_up;
	
	temp.right_down=right_down;

	return temp;
}
/*############################################################################*/
/*                HW08_AhmetEmin_Kaplan_131044042_part1.c                     */
/*############################################################################*/
