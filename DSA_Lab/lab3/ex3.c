#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node{
	int data;
	struct Node *next;
	};
typedef struct Node* Element;

struct myList{
	Element head;
	Element rear;
	};
typedef struct myList* SeqList;

void* myalloc(int x);


SeqList createList(int N)
{
	SeqList Ls=(SeqList)malloc(sizeof(struct myList));
	int i;
	Element x=(Element)malloc(sizeof(struct Node));
	x->data=rand()%N;
	Ls->head=x; Ls->rear = NULL;
	Element y;
	for(i=1;i<N;i++)
	{
		
		y=(Element)malloc(sizeof(struct Node));
		y->data=rand()%N;
		y->next=NULL;
		x->next=y;
		x=x->next;
		if(i==N-1)
		{
			Ls->rear=x;
			x->next=NULL;
		}
	}
	return Ls;
}

SeqList createCycle(SeqList Ls,int N)
{
	
	int toss=rand()%2;
	if(toss==1)
		return Ls;
	else
	{
		int r=rand()%N;
		Element x=Ls->head;
		while(x!=NULL)
		{
			printf("%d\n",x->data);
			if(x->data==r)
			{	
				if((Ls->rear)!=NULL)
				(Ls->rear)->next=x;
				return Ls;
			}
			x=x->next;
		}
		printf("No node containing the random no %d\n",r);
		return Ls;
	}
}

int testCyclic(SeqList sq)
{
	Element hare,tort;
	hare=sq->head;
	tort=sq->head;
	while(1)
	{
		if(hare==NULL)
			return 0;
		hare=hare->next;
		if(hare==tort)
			return 1;
		if(hare==NULL)
			return 0;
		hare=hare->next;
		if(hare==tort)
			return 1;
		if(hare==NULL)
			return 0;
		tort=tort->next;
	}
}


SeqList reverse(SeqList ls,Element x,Element y)
{
	if(y==ls->head)
		ls->rear=y;
	if(x->next==NULL)
	{
		ls->head=x;
		return ls;
	}
	x=x->next;
	y=y->next;
	ls=reverse(ls,x,y);
	x->next=y;
}


int main()
{
	srand(time(NULL));
	SeqList sq=createList(100);
	if(testCyclic(sq)==0)
		printf("The list is not cyclic\n");
	Element x=sq->head;
	if(x!=NULL)
	{
		printf("%d\n",x->data);
		x=x->next;
	}
/*	sq=createCycle(sq,100);
		if(testCyclic(sq)==1)
		printf("The list is cyclic\n");
		else
		printf("The list is not cyclic\n"); */
	if((sq->head)->next!=NULL)
	sq=reverse(sq,(sq->head)->next,sq->head);
	Element y=sq->head;
	if(y!=NULL)
	{
		printf("%d\n",y->data);
		y=y->next;
	}
}

