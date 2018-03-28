#include<stdio.h>
#include<stdlib.h>
#include"ex1.h"

int pivot(List ls,int x,int y)
{
	return x;
}


void swap(Employee* e1,Employee* e2)
{
	Employee temp=*e1;
	*e1=*e2;
	*e2=temp;
}


int partition(List Ls,int start,int end,int pind)
{
	swap(&(Ls->arr[pind]),&(Ls->arr[start]));
	int lt,rt;
	Employee pv;
	lt=start+1;
	rt=end;
	pv=Ls->arr[start];
	int i;
	while(lt<rt)
	{
		for(;((lt<=end)&&((Ls->arr[lt]->empID)<=(pv->empID)));lt++);
		for(;(((Ls->arr[rt]->empID)>(pv->empID)));rt--);

		if(lt<rt)
		{
			swap(&(Ls->arr[lt]),&(Ls->arr[rt]));
			lt++;
			rt--;
		}
	}
	int pPos;
	if((lt==rt))	//&&((Ls->arr[lt]->empID)<=(pv->empID))
		pPos=lt;
	else
		pPos=lt-1;
	swap(&(Ls->arr[start]),&(Ls->arr[pPos]));
	return pPos;
}


List quickSort(List toSort,int lo,int hi,int S)
{
	Element x=(Element)malloc(sizeof(struct ss));
	x->low=lo;
	x->high=hi;
	x->bottom=NULL;
	Stack s=push(newStack(),x);
	
	int p;
	
	while(!(isEmptyStack(s)))
	{
		Element y=s->top;
		lo=y->low;
		hi=y->high;
		s=pop(s);
		if((hi-lo+1)<=S)
			continue;
		while(lo<hi)
		{
			if((hi-lo+1)<=S)
				break;
			p=pivot(toSort,lo,hi);
			p=partition(toSort,lo,hi,p);
			Element z=(Element)malloc(sizeof(struct ss));
			z->low=lo;
			z->high=p-1;
			z->bottom=NULL;
			s=push(s,z);
			lo=p+1;
			
		}
	}
	return toSort;
}




List insSort(List toSort,int start,int end)
{
   int i, j;
   Employee key;
   for (i = start+1; i <=end; i++)
   {
       key = toSort->arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while ((j >= start) && ((toSort->arr[j]->empID) > (key->empID)))
       {
           
           toSort->arr[j+1] = toSort->arr[j];
           j = j-1;
       }
       toSort->arr[j+1] = key;
   }
   return toSort;
}


































	

