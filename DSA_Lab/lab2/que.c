#include<stdio.h>
#include<stdlib.h>
#include"que.h"

Queue newQ()
{
	Queue myQ=(Queue)malloc(sizeof(struct myList));
	myQ->front=NULL;
	myQ->rear=NULL;
	return myQ;
}


int isEmptyQ(Queue q)
{
	if(q->front==NULL)
		return 1;
	else
		return 0;
}


Queue delQ(Queue q)
{
	Element temp=q->front;
	q->front=(q->front)->next;
	free(temp);
	return q;
}


Element front(Queue q)
{
	return (q->front);
}


Queue addQ(Queue q,Element e)
{
	if(isEmptyQ(q))
	{
		q->front=e;
		q->rear=e;
		e->next=NULL;
		return q;
	}
	(q->rear)->next=e;
	q->rear=e;
	e->next=NULL;
	return q;
}


int lengthQ(Queue q)
{
	Element temp=q->front;
	int len=0;
	while(temp!=NULL)
	{
		len++;
		temp=temp->next;
	}
	return len;
}			








