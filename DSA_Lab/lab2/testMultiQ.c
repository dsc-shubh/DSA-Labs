#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include"multiq.h"


MultiQ loadData(MultiQ mq)
{
char c;
int taskid,prio,i;
for(i=0;i<50;i++)
{
	scanf("%d %c %d",&taskid,&c,&prio);
	Element t2=(Element)malloc(sizeof(struct Node));
	t2->tid=taskid;
	t2->p=prio;
	t2->next=NULL;
	mq=addMQ(mq,t2);
}
return mq;
}



int main()
{
MultiQ mq=createMQ(10);
	struct timeval t1, t2;
	double elapsedTime;
	// start timer
	gettimeofday(&t1, NULL);
	
	mq=loadData(mq);
	
	// stop timer
	gettimeofday(&t2, NULL);
	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	printf("Total time is %lf ms.\n",elapsedTime);
printf("Successfully added\n");
Queue try=getQueueFromMQ(mq,4);
Element e1=try->front;
while(e1!=NULL)
{
printf("%d\n",e1->tid);
e1=e1->next;
}


}
