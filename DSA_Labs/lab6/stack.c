#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

Stack newStack()
{
	Stack s=(Stack)malloc(sizeof(struct stack));
	s->top=NULL;
	return s;
}

int isEmptyStack(Stack s)
{
	if(s->top==NULL)
		return 1;
	return 0;
}

Stack pop(Stack s)
{
	Element temp=s->top;
	if(temp==NULL)
	{
		printf("Stack empty | Can't pop!\n");
		return s;
	}
	s->top=temp->bottom;
	free(temp);
	return s;
}

Stack push(Stack s , Element e)
{
	Element temp=s->top;
	if(temp==NULL)
	{
		s->top=e;
		e->bottom=NULL;
	}
	else
	{
		e->bottom=s->top;
		s->top=e;
	}
	return s;
}

int lengthS(Stack s)
{
	Element temp=s->top;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->bottom;
	}
	return count;
}

void showStack(Stack s)
{
	Element temp=s->top;
	while(temp!=NULL)
	{
		printf("(%d,%d)\n",temp->low,temp->high);
		temp=temp->bottom;
	}
	printf("\n");
}











