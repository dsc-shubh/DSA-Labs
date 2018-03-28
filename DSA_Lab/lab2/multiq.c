#include<stdio.h>
#include<stdlib.h>
#include"multiq.h"

MultiQ createMQ(int num1)
{
	MultiQ mq=(MultiQ)malloc(sizeof(struct mulq));
	mq->num=num1;
	mq->arr=(Queue*)malloc(num1*sizeof(Queue));
	int i;
	for(i=0;i<num1;i++)
	{
		mq->arr[i]=(Queue)malloc(sizeof(struct myList));
		(mq->arr[i])->prio=i+1;
	}
	return mq;
}

MultiQ addMQ(MultiQ mq,Element t1)
{
	int i=0;
	Queue* arr2=mq->arr;
	while(i<mq->num)
	{
		if(((mq->arr[i])->prio)==(t1->p))
		{
			mq->arr[i]=addQ(mq->arr[i],t1);
			return mq;
		}
		i++;
	}
}


Element nextMQ(MultiQ mq)
{
	int highest=(mq->arr[0])->prio;
	int x=0;
	int i;
	for(i=1;i<mq->num;i++)
	{
		if(((mq->arr[i])->prio)>highest)
		{
			highest=(mq->arr[i])->prio;
			x=i;
		}
	}
	return ((mq->arr[x])->front);
}


MultiQ delNextMQ(MultiQ mq)
{
	int highest=(mq->arr[0])->prio;
	int x=0;
	int i;
	for(i=1;i<mq->num;i++)
	{
		if(((mq->arr[i])->prio)>highest)
		{
			highest=(mq->arr[i])->prio;
			x=i;
		}
	}
	mq->arr[x]=delQ(mq->arr[x]);
	return mq;
}


int isEmptyMQ(MultiQ mq)
{
	int i=0;
	int t=1;
	for(i=0;i<mq->num;i++)
	{
		if(!(isEmptyQ(mq->arr[i])))
		{
			t=0;
			break;
		}
	}
	return t;
}


int sizeMQ(MultiQ mq)
{
	int count=0,i;
	for(i=0;i<mq->num;i++)
		count+=lengthQ(mq->arr[i]);
	return count;
}


int sizeMQbyPriority(MultiQ mq,int priority)
{
	int i;
	for(i=0;i<mq->num;i++)
	{
		if(((mq->arr[i])->prio)==priority)
			return lengthQ(mq->arr[i]);
	}
}


Queue getQueueFromMQ(MultiQ mq,int priority)
{
	int i;
	for(i=0;i<mq->num;i++)
	{
		if(((mq->arr[i])->prio)==priority)
			return mq->arr[i];
	}
}
