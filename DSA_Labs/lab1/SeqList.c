#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"

SeqList newList()
{
	SeqList new=(SeqList)malloc(sizeof(struct list));
	new->front=NULL;
	new->rear=NULL;
	return new;
}


SeqList insertAtFront(SeqList sl, Element e)
{
	if(sl->front==NULL)
	{
		sl->front=e;
		sl->rear=e;
		e->next=NULL;
	}
	else
	{
		e->next=sl->front;
		sl->front=e;
	}
	return sl;
}


SeqList insertAtEnd(SeqList sl,Element e)
{
	if(sl->front==NULL)
	{
		sl->front=e;
		sl->rear=e;
		e->next=NULL;
	}
	else
	{
	(sl->rear)->next=e;
	sl->rear=e;
	e->next=NULL;
	}
	return sl;
}


SeqList insertInOrder(SeqList sl,Element e)
{
	if(sl->front==NULL)
	{
		sl->front=e;
		sl->rear=e;
		e->next=NULL;
		return sl;
	}
	else
	{
		Element prev=NULL;
		Element curr=sl->front;
		if((e->key)<(curr->key))
		{
			insertAtFront(sl,e);
			return sl;
		}
		while(curr!=NULL)
		{
			if((curr->key)>(e->key))
			{
				prev->next=e;
				e->next=curr;
				return sl;
			}
			prev=curr;
			curr=curr->next;
		}
		insertAtEnd(sl,e);
		return sl;
	}
}


SeqList delete(SeqList sl,Element e)
{
	if(sl->front==NULL)
	{
		printf("Can't delete | List Empty\n");
		return NULL;
	}
	else
	{
		Element prev=sl->front;
		Element curr=prev->next;
		if((prev->key)==(e->key))
		{
			sl->front=curr;
			free(prev);
			return sl;
		}
		while(curr!=NULL)
		{
			if((curr->key)==(e->key))
			{
				prev->next=curr->next;
				free(curr);
				return sl;
			}
		}
		printf("Can't delete | Element not found\n");
		return NULL;
	}
}



SeqList deleteAtFront(SeqList sl)
{
	if(sl->front==NULL)
	{
		printf("Can't delete | List Empty\n");
		return NULL;
	}
	else
	{
		if(((sl->front)->next)==NULL)
		{
			free(sl->front);
			sl->front=NULL;
			sl->rear=NULL;
			return sl;
		}
		Element temp=sl->front;
		sl->front=temp->next;
		free(temp);
		return sl;
	}
}


Element find(SeqList sl,int k)
{
	if(sl->front==NULL)
	{
		printf("Can't delete | List Empty\n");
		return NULL;
	}
	else
	{
		Element curr=sl->front;
		while(curr!=NULL)
		{
			if((curr->key)==k)
			{
				return curr;
			}
		}
		printf("Can't delete | Element not found\n");
		return NULL;
	}
}

		

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

