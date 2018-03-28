#include<stdio.h>
#include<stdlib.h>

int bits;

void h()
{
	int hyd;
	printf("Address of hyd-%u\n",&hyd);
}

void g()
{
	int goa;
	printf("Address of goa-%u\n",&goa);
}

void p(int x)
{
	int pilani;
	printf("Address of pilani-%u\n",&pilani);
	if(x!=0)
		p(x-1);
}



void d()
{
	int dubai;
	printf("Address of dubai-%u\n",&dubai);
}

int main()
{
p(10);
g();
h();
d();
}
