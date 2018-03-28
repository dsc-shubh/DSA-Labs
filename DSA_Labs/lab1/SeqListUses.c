#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"

SeqList merge(SeqList sl1,SeqList sl2)
{
	SeqList sl=newList();
	Element temp1=sl1->front;
	Element temp2=sl2->front;
	if(temp1==NULL)
		return sl2;
	else if(temp2==NULL)
		return sl1;
	while((temp1!=NULL)||(temp2!=NULL))
	{
		if((temp1->key)<(temp2->key))
		{
			insertAtEnd(sl,temp1);
			temp1=temp1->next;
		}
		else if((temp1->key)>(temp2->key))
		{
			insertAtEnd(sl,temp2);
			temp2=temp2->next;
		}
		else
		{
			insertAtEnd(sl,temp1);
			insertAtEnd(sl,temp2);
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
	if(temp1==NULL)
	{
		while(temp2!=NULL)
		{
			insertAtEnd(sl,temp2);
			temp2=temp2->next;
		}
	}
	if(temp2==NULL)
	{
		while(temp1!=NULL)
		{
			insertAtEnd(sl,temp1);
			temp1=temp1->next;
		}
	}
	return sl;
}



SeqList insertSort(SeqList sl)
{
	SeqList new=newList();
	Element temp=sl->front;
	Element temp1=temp->next;
	temp->next=NULL;
	new=insertInOrder(new,temp);
	while(temp1!=NULL)
	{
		temp=temp1;
		temp1=temp->next;
		temp->next=NULL;
		new=insertInOrder(new,temp);
	}
	return new;
}



















