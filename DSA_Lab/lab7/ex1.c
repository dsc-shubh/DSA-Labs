#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int hashf(char* a,int tabsize)
{
	int i=0;
	int sum=0;
	while(a[i]!='\0')
	{
		sum+=(int)a[i];
		i++;
	}
	return (sum%tabsize);
}



int collcount(char** a,int n,int tabsize)
{
	int i=0;
	int count=0;
	int* b=(int*)malloc(tabsize*sizeof(int));
	for(i=0;i<tabsize;i++)
		b[i]=-1;
	for(i=0;i<n;i++)
	{
		int x=hashf(a[i],tabsize);
		if(b[x]!=-1)
			count++;
		else
			b[x]=1;
	}
	return count;
}




char** parse(FILE* infile)
{
	int valid=0;
	char** b=(char**)malloc(sizeof(char*));
	while(!(feof(infile)))
	{
		char* a=(char*)malloc(50*sizeof(char));
		fscanf(infile,"%s",a);
		int i=0;
		int t=1;
		while(a[i]!='\0')
		{
			if(!(((a[i]>='A')&&(a[i]<='Z'))||((a[i]>='a')&&(a[i]<='z'))))
				t=0;
			i++;
		}
		if(t==1)
		{
			b=(char**)realloc(b,(valid+1)*sizeof(char*));
			b[valid]=(char*)malloc(50*sizeof(char));
			strcpy(b[valid],a);
			valid++;
		}
		free(a);
	}
	printf("Number of valid strings=%d\n",valid);
	int i;
//	for(i=0;i<100;i++)
//	{
//		printf("%s ",b[i]);
//	}
	return b;
}



int main()
{
	FILE* in=fopen("aliceinwonderland.txt","r");
	char** x=parse(in);
	fclose(in);
	int col=collcount(x,22700,5000);
	printf("No of collisions=%d\n",col);
	return 0;
}






















