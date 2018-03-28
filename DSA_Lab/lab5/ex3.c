#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ex1.h"

void readByK(int k)
{
	FILE *infile=fopen("10240.txt","r");
	FILE* outfile=fopen("SortedByK.txt","w");
	int i,j;
	for(i=0;i<1024;i=i+k)
	{
			Element* Ls1=(Element*)malloc(k*sizeof(Element));
			for(j=0;j<k;j++)
			{
				Ls1[j]=(Element)malloc(sizeof(struct Node));
				fscanf(infile,"%s , %f",Ls1[j]->name,&(Ls1[j]->cgpa));
				printf("%s\n",Ls1[j]->name);
				printf("%f\n",Ls1[j]->cgpa);
				//fflush(stdin);
			}
			iterMergeSort(Ls1,k);
			for(j=0;j<k;j++)
			{
				fprintf(outfile,"%f\n",Ls1[j]->cgpa);
			}
	}
}




int main()
{
	readByK(16);
}

