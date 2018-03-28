#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ex2.h"

HashTable createHash()
{
	int size=profBest();
	HashTable h=(HashTable)malloc(sizeof(struct hash));
	h->elemCount=0;
	h->queryCost=0;
	h->insCost=0;
	h->arr=(SeqList*)malloc(size*sizeof(SeqList));
	int i;
	for(i=0;i<size;i++)
		h->arr[i]=newList();
	return h;
}


HashTable insHash(HashTable h,char** a,int n,int j)
{
	
	char* b=a[j];
	int hashind=hashf(b,7,5000);
	SeqList x=h->arr[hashind];
	Element ele=find(x,b);
	if(ele==NULL)
	{
		Element new=(Element)malloc(sizeof(struct node));
		new->word=(char*)malloc(100*sizeof(char));
		strcpy(new->word,b);
		new->indexfirst=j;
		new->count=1;
		new->next=NULL;
		h->insCost+=count(h->arr[hashind])+1;
		h->arr[hashind]=insertAtEnd(h->arr[hashind],new);
		h->elemCount++;
	}
	else
	{
		ele->count=ele->count+1;
	}
	return h;
}

		
		
int insertAll(HashTable h)
{
	FILE* in=fopen("aliceinwonderland.txt","r");
	char** x=parse(in);
	printf("Collision Count=%d\n",collcount(x,22700,7,5000));
	int n=22700;
	int i;
	for(i=0;i<22700;i++)
	{
		h=insHash(h,x,n,i);
	}
	fclose(in);
	printf("Element Count=%d\n",h->elemCount);
	return (h->insCost);
}
	
	
	
	
int main()
{
	HashTable h=createHash();
	printf("Insertion Cost=%d\n",insertAll(h));
}
	
	
	
	
	
	
	
	
	
	
	
	
