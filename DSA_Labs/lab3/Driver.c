#include<stdio.h>

#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include"ex3.h"

extern int totspace;

int main()
{
	srand(time(0));
	int M=10000+(rand()%15000);
	int* A=(int*)myalloc(M*sizeof(int));
	printf("Address of A[0]-%u\n",A);
	printf("Address of A[M-1]-%u\n",(A+M-1));
	printf("Space=%d\n",totspace);
	myfree(A);
	printf("Space after deletion=%d\n",totspace);
	
	
	List ls=createList(100);
/*	int check1=testCyclic(ls);
	if(check1==-1)
		printf("Can't check if list is cyclic | List empty!\n");
	else if(check1==0)
		printf("List is linear\n");
	else if(check1==1)
		printf("List is cyclic\n");
*/	
	struct timeval t1,t2;
	double time;
	
	ls=createCycle(ls,100);
	gettimeofday(&t1,NULL);
	int check2=testCyclic(ls);
	gettimeofday(&t2,NULL);
	time=(t2.tv_sec-t1.tv_sec)*1000.0;
	time+=(t2.tv_usec-t1.tv_usec)/1000.0;
	printf("Time taken to check cyclic or not is %lf ms\n",time);
	if(check2==-1)
		printf("Can't check if list is cyclic | List empty!\n");
	else if(check2==0)
		printf("List is linear\n");
	else if(check2==1)
		printf("List is cyclic\n");
		
	
	
	ls=makeCircularList(ls);
	
	
	
	
	
	
	
	
	
	
	
	
	
		
}

