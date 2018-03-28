#include"stack.h"

struct node{
char* name;
long int empID;
};
typedef struct node* Employee;

struct list{
Employee* arr;
int count;
};
typedef struct list* List;

struct time{
double IStime;
double QStime;
};
typedef struct time* Time;


int pivot(List ls,int x,int y);		//wf
void swap(Employee* e1,Employee* e2);	//wf
int partition(List Ls,int start,int end,int pind);
List quickSort(List toSort,int lo,int hi,int S);
List insSort(List toSort,int start,int end);
List readData(FILE* infile,int nor);    //wf
Time testRun(List speed,int size);
int estCutoff(List Ls);


