#include<stdio.h>
#include<stdlib.h>
#include"info.h"
#include<sys/time.h>

ListRecords read(FILE* infile)
{
	FILE* outfile=fopen("TimeTaken.txt","a");
	struct timeval t1,t2;
	double elapTime;
	gettimeofday(&t1,NULL);
	ListRecords new=(ListRecords)malloc(sizeof(struct list));
	new->arr=(Record*)malloc(11*sizeof(Record));
	int limit=10;
	int i=0;
	while(!(feof(infile)))
	{
		if(i==limit+1)
		{
			limit*=10;
			new->arr=(Record*)realloc(new->arr,(limit+1)*sizeof(Record));
		}
		new->arr[i]=(Record)malloc(sizeof(struct node));
		fscanf(infile,"%lld,%[^,],%[^,],%[^,],%s",&(new->arr[i]->cardno),new->arr[i]->bcode,new->arr[i]->expdate,new->arr[i]->fname,new->arr[i]->lname);
		i++;
	}
	gettimeofday(&t2,NULL);
	elapTime=(t2.tv_sec-t1.tv_sec)*1000.0;
	elapTime=(t2.tv_usec-t1.tv_usec)/1000.0;
	fprintf(outfile,"Time taken to write %d records is %lf ms\n",(i-1),elapTime);
	fclose(outfile);
	new->count=i-1;
	return new;
}

int main()
{
	FILE* input1=fopen("10","r");
	ListRecords RecFile=read(input1);
	for(int i=0;i<10;i++)
		printf("%s\n",RecFile->arr[i]->fname);
	fclose(input1);
	FILE* input2=fopen("100","r");
	RecFile=read(input2);
	fclose(input2);
	FILE* input3=fopen("1000","r");
	RecFile=read(input3);
	fclose(input3);
	
}
