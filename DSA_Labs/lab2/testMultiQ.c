#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include"multiq.h"

MultiQ loadData(FILE* infile)
{
	MultiQ mq=createMQ(10);
	int i;
	for(i=0;i<10;i++)
	{
		mq->arr[i]=(Queue)malloc(sizeof(struct list));
		(mq->arr[i])->priority=i+1;
	}
	Task x;
	while(!(feof(infile)))
	{
		int a,b;
		fscanf(infile,"%d,%d",&a,&b);
		//printf("%d,%d\n",a,b);
		x=(Task)malloc(sizeof(struct node));
		x->tid=a;
		x->p=b;
		x->next=NULL;
		mq=addMQ(mq,x);
	}
	return mq;
}


int main()
{
	FILE* in=fopen("input100.txt","r");
	MultiQ new;
	struct timeval t1,t2;
	double elapTime;
	
	gettimeofday(&t1,NULL);
	new=loadData(in);
	gettimeofday(&t2,NULL);
	elapTime=(t2.tv_sec-t1.tv_sec)*1000.0;
	elapTime+=(t2.tv_usec-t1.tv_usec)/1000.0;
	printf("Total time to read 100 tasks is %lf\n",elapTime);
	printf("Number of tasks with priority 5 = %d\n",sizeMQbyPriority(new,5));
	fclose(in);
	
	FILE* in1=fopen("input10000.txt","r");
	gettimeofday(&t1,NULL);
	new=loadData(in1);
	gettimeofday(&t2,NULL);
	elapTime=(t2.tv_sec-t1.tv_sec)*1000.0;
	elapTime+=(t2.tv_usec-t1.tv_usec)/1000.0;
	printf("Total time to read 10000 tasks is %lf\n",elapTime);
	printf("Number of tasks with priority 5 = %d\n",sizeMQbyPriority(new,5));
	fclose(in1);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
