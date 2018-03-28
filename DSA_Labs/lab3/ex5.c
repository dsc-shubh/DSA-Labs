#include<stdio.h>
#include<stdlib.h>
#include"ex3.h"

extern int totspace;

List makeCircularList(List Ls)
{
	int check=testCyclic(Ls);
	if(check==-1)
	{
		printf("List Empty | Returning the same list back\n");
	}
	else if(check==0)
	{
		(Ls->rear)->next=Ls->front;
	}
	else if(check==1)
	{
		Node temp=(Ls->rear)->next;
		Node temp2=Ls->front;
		int i=0;
		while(temp2!=temp)
		{
			Node temp1=temp2;
			Ls->front=temp2->next;
			temp2=temp2->next;
			myfree(temp1);
			i++;
			printf("Total heap space after deleting %d nodes=%d\n",i,totspace);
		}
	}
	return Ls;
}
	
		
