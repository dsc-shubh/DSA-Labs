#include<stdio.h>
#include<stdlib.h>
#include"que.h"

int main()
{
	Queue q=newQ();
	Task one1=(Task)malloc(sizeof(struct node));
	Task one2=(Task)malloc(sizeof(struct node));
	Task one3=(Task)malloc(sizeof(struct node));
	Task one4=(Task)malloc(sizeof(struct node));
	Task one5=(Task)malloc(sizeof(struct node));
	one1->tid=2;
	one2->tid=5;
	one3->tid=6;
	one4->tid=1;
	one5->tid=9;
	q=addQ(q,one1);
	q=addQ(q,one2);
	q=addQ(q,one3);
	printf("Number of Tasks-%d\n",lengthQ(q));
	q=delQ(q);
	printf("Number of Tasks-%d\n",lengthQ(q));
}
	
