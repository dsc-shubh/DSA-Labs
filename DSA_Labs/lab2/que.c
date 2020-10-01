#include<stdio.h>
#include<stdlib.h>
#include"que.h"

Queue newQ(){
	Queue new=(Queue)malloc(sizeof(struct list));
	return new;
	}
	

int isEmptyQ(Queue q){
	Task temp=q->head;
	if(temp==NULL)
		return 1;      //pls add context for beginners too
	else
		return 0;
	}
	
	
Queue delQ(Queue q){
	Task temp=q->head;
	if(temp==NULL)
		printf("Can't delete | Queue empty!\n");
	q->head=temp->next;
	free(temp);
	return q;
	}


Task front(Queue q){
	return (q->head);
	}


Queue addQ(Queue q,Task e){
	Task temp=q->tail;
	if(temp==NULL){
		q->head=e;
		q->tail=e;
		e->next=NULL;
		return q;
		}
	else{
		temp->next=e;
		q->tail=e;
		e->next=NULL;
		return q;
		}
	}
	
	
int lengthQ(Queue q){
	int count=0;
	Task temp=q->head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
		}
	return count;
	}
		
		
		
		
		
		
		
		
		
		
	
