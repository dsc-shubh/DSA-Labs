#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include"ex1.h"

Time testRun(List speed,int size)
{
	struct timeval t1,t2;
	double elT1,elT2;
	
	gettimeofday(&t1,NULL);
	List l1=quickSort(speed,0,size-1,0);
	gettimeofday(&t2,NULL);
	elT1=(t2.tv_sec-t1.tv_sec)*1000.0;
	elT1+=(t2.tv_usec-t1.tv_usec)/1000.0;
	
	
	gettimeofday(&t1,NULL);
	List l2=insSort(speed,0,size-1);
	gettimeofday(&t2,NULL);
	elT2=(t2.tv_sec-t1.tv_sec)*1000.0;
	elT2+=(t2.tv_usec-t1.tv_usec)/1000.0;
	
	Time t=(Time)malloc(sizeof(struct time));
	t->IStime=elT2;
	t->QStime=elT1;
	return t;
}
	
	
	
	

int estCutoff(List Ls)
{
	int i;
	for(i=(Ls->count)-1;i>=1;i--)
	{
		Time x=testRun(Ls,i);
//		printf("Quick Sort time %lf ms.\n",x->QStime);
//		printf("Insertion Sort time %lf ms.\n",x->IStime);
		if((x->QStime)<(x->IStime))
			return i;
	}
	return -1;
}



























