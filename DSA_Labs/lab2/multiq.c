#include<stdio.h>
#include<stdlib.h>
#include"multiq.h"


MultiQ createMQ(int num)
{
	MultiQ new=(MultiQ)malloc(sizeof(struct multi));
	new->count=num;
	new->arr=(Queue*)malloc(num*sizeof(Queue));
	return new;
}


MultiQ addMQ(MultiQ mq,Task t)
{
	int i;
	for(i=0;i<mq->count;i++)
	{
		if(((mq->arr[i])->priority)==(t->p))
		{
			mq->arr[i]=addQ(mq->arr[i],t);
			return mq;
		}
	}
	printf("Such priority doesn't exist | Not added!\n");
	return mq;
}



Task nextMQ(MultiQ mq)
{
	int highest=0,highesti=0,i=0;
	Queue temp=mq->arr[0];
	while((temp->head==NULL)&&(i<mq->count))
	{
		i++;
		temp=mq->arr[i];
	}
	highest=temp->priority;
	highesti=i;
	while(i<mq->count)
	{
		if(temp->head!=NULL)
		{
			if((temp->priority)>highest)
			{
				highest=temp->priority;
				highesti=i;
			}
		}
		i++;
	}
	return front(mq->arr[highesti]);
}


MultiQ delNextMQ(MultiQ mq)
{
	int highest=0,highesti=0,i=0;
	Queue temp=mq->arr[0];
	while((temp->head==NULL)&&(i<mq->count))
	{
		i++;
		temp=mq->arr[i];
	}
	highest=temp->priority;
	highesti=i;
	while(i<mq->count)
	{
		if(temp->head!=NULL)
		{
			if((temp->priority)>highest)
			{
				highest=temp->priority;
				highesti=i;
			}
		}
		i++;
	}
	mq->arr[highesti]=delQ(mq->arr[highesti]);
	return mq;
}


int isEmptyMQ(MultiQ mq)
{
	int i=0;
	Queue temp=mq->arr[0];
	while((temp->head==NULL)&&(i<mq->count))
	{
		i++;
		temp=mq->arr[i];
	}
	if(i==mq->count)
		return 1;
	else
		return 0;
}


int sizeMQ(MultiQ mq)
{
	return mq->count;
}


int sizeMQbyPriority(MultiQ mq,int prio)
{
	int i=0;
	while((i<mq->count))
	{
		if(((mq->arr[i])->priority)==prio)
			return lengthQ(mq->arr[i]);	
		i++;
	}
	printf("Such priority doesn't exist | Returning -1\n");
	return -1;
}


Queue getQueueFromMQ(MultiQ mq,int prio)
{
	int i=0;
	while((i<mq->count))
	{
		if(((mq->arr[i])->priority)==prio)
			return mq->arr[i];	
		i++;
	}
	printf("Such priority doesn't exist | Returning NULL\n");
	return NULL;
}








	







		
		
		
		
		
		
		
		
		
		
		
