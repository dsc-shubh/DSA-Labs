#include<stdio.h>
#include<stdlib.h>

int bits;

void p(int n)
{
int pilani;
printf("In function p\n");
printf("%u\n",&n);
if(n==0)
return;
p(n-1);
}

void g()
{
int goa;
printf("In function g\n");
printf("%u\n",&goa);
}

void h()
{
int hyd;
printf("In function h\n");
printf("%u\n",&hyd);
}

void d()
{
int dub;
printf("In function d\n");
printf("%u\n",&dub);
}


int main()
{
p(10);
g();
h();
d();
}
