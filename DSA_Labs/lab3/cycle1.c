#include<stdio.h>
#include<stdlib.h>
#include"ex3.h"


int testCyclic(List Ls)	      //0 for List, 1 for cycle
{
	Node hare=Ls->front;
	Node tort=hare;
	if(hare==NULL)
	{
		printf("List empty | Returning -1\n");
		return -1;
	}
	else if(hare->next==NULL)
		return 0;
	else if(hare->next==hare)
		return 1;
	while(hare!=NULL)
	{
		hare=hare->next;
		if(hare==NULL)
			break;
		hare=hare->next;
		if(hare==NULL)
			break;
		tort=tort->next;
		if((hare->next==tort)||(hare==tort))
			return 1;
	}
	return 0;
}
