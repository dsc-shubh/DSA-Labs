#include<stdio.h>
#include<stdlib.h>
#include"ex3.h"

int testCyclic(List Ls)	      //0 for List, 1 for cycle
{
	Node temp1=Ls->front;
	if(temp1==NULL)
	{
		printf("List empty | Returning -1\n");
		return -1;
	}
	else if(temp1->next==NULL)
		return 0;
	else if(temp1->next==temp1)
		return 1;
	Node temp2=temp1->next;
	Node temp3=temp2->next;
	
	while(temp3!=NULL)
	{
		temp2->next=temp1;
		temp1=temp2;
		temp2=temp3;
		temp3=temp3->next;
		if(temp3==Ls->front)
			return 1;
	}
	return 0;
}
		
