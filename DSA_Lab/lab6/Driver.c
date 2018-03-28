#include<stdio.h>
#include<stdlib.h>
#include"ex1.h"

List readData(FILE* infile,int nor)
{
	List new=(List)malloc(sizeof(struct list));
	new->arr=(Employee*)malloc(nor*sizeof(Employee));
	int i=0;
	while(!feof(infile))
	{
		new->arr[i]=(Employee)malloc(sizeof(struct node));
		new->arr[i]->name=(char*)malloc(11*sizeof(char));
		fscanf(infile,"%s %ld",new->arr[i]->name,&(new->arr[i]->empID));
		i++;
	}
	new->count=i;
	return new;
}


int main()
{

/*	int i;
	for(i=0;i<ls->count;i++)
	{
		printf("%s %ld\n",ls->arr[i]->name,ls->arr[i]->empID);
	}

	ls=quickSort(ls,0,(ls->count)-1,10);


	Stack s=newStack();
	Element e1=(Element)malloc(sizeof(struct ss));
	e1->low=2;
	e1->high=3;
	e1->bottom=NULL;
	Element e2=(Element)malloc(sizeof(struct ss));
	e2->low=1;
	e2->high=7;
	e2->bottom=NULL;
	Element e3=(Element)malloc(sizeof(struct ss));
	e3->low=4;
	e3->high=7;
	e3->bottom=NULL;
	s=push(s,e1);
	showStack(s);
	s=push(s,e2);
	showStack(s);
	s=push(s,e3);
	showStack(s);
	s=pop(s);
	showStack(s);
	s=pop(s);
	showStack(s);
	printf("%d",isEmptyStack(s));
	
	
*/	
	
	
	FILE* input=fopen("data.txt","r");
	List ls=readData(input,2000);
	fclose(input);
	
/*	printf("%s %s\n",ls->arr[0]->name,ls->arr[1]->name);
	swap(&(ls->arr[0]),&(ls->arr[1]));
	printf("%s %s\n",ls->arr[0]->name,ls->arr[1]->name);
	


		
		
	int p=partition(ls,0,9,0);
	printf("%d\n",p);	
*/	
/*	ls=quickSort(ls,0,(ls->count)-1,25);
	ls=insSort(ls,0,(ls->count)-1);
	FILE* out=fopen("sorted.txt","w");
	int i;
	for(i=0;i<ls->count;i++)
	{
		fprintf(out,"%s %ld\n",ls->arr[i]->name,ls->arr[i]->empID);
	}
	fclose(out);
*/



	printf("Cutoff is %d\n",estCutoff(ls));
	
	
	
	
	
	
	
		
	


}
