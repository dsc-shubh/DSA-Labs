#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ex3.h"

int totspace=0;


void* myalloc(int space)
{
	totspace+=(space+4);
	void* temp=malloc(space+4);
	*(int*)temp=space;
	return (temp+4);
}

void myfree(void* del)
{
	int x=*(int*)(del-4);
	free(del-4);
	totspace-=(x+4);
}




