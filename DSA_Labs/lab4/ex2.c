#include<stdio.h>
#include<stdlib.h>
#include"info.h"
#include<sys/time.h>


ListRecords insertInOrder(ListRecords ins,Record toIns,int end)
{
	int i,j;
	for(i=0;i<ins->count;ins++)
	{
		if((ins->arr[i]->cardno)>(toIns->cardno))
		{
			for(j=ins->count;j>i;j--
			{
				ins->arr[j]=ins->arr[j-1];	
			}
			ins->arr[i]=toIns;
			return ins;
		}
	}
	ins->arr[i]=toIns;
	return ins;
}


ListRecords insSort(ListRecords toSort)
{
	
