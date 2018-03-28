#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int totalspace;


void* myalloc(int x)
{
//totalspace+=x;
return malloc(x);
}


void myfree(void* x)
{
free(x);
}


/*int main()
{
time_t t;
srand((unsigned)time(&t));
int m=10000+(rand()%15000);
printf("%d\n",m);
int* a;
a=myalloc(m*sizeof(int));
printf("%u\n%u",a,a+m-1);
myfree(a);
}
*/
