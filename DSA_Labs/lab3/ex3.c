#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ex3.h"

extern int totspace;

List createList(int n)
{
	List Ls=(List)myalloc(sizeof(struct list));
	Node x=(Node)myalloc(sizeof(struct node));
	x->data=rand()%n;
	x->next=NULL;
	Ls->front=x;
	Ls->rear=x;
	int i;
	Node y;	
	for(i=2;i<=n;i++)
	{
		y=(Node)myalloc(sizeof(struct node));
		y->data=rand()%n;
		y->next=NULL;
		(Ls->rear)->next=y;
		Ls->rear=y;
	}
	FILE* outfile=fopen("heap.txt","w");
	fprintf(outfile,"Total heap space allocated is %d",totspace);
	fclose(outfile);
	return Ls;
}




List createCycle(List Ls,int n)
{
	int coin=rand()%2;
//	printf("%d",coin);
	Node temp;
	int r,i;
	if(coin==0)
	{
		printf("Returning the Linear List back!\n");
	}
	else
	{
		r=rand()%n;
		i=1;
		temp=Ls->front;
		while((temp!=NULL))
		{
			if((temp->data)==r)
			{
				(Ls->rear)->next=temp;
				printf("Last node now pointing to node %d\n",i);
				return Ls;
			}
		i++;
		temp=temp->next;
		}
		printf("Couldn't match r=%d with any node | Returning the Linear List back! \n",r);
	}
	return Ls;
}
		
	










































