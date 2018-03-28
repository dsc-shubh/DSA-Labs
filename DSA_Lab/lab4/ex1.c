#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/time.h>

struct record{
long long int cardno;
char* bankcode;
char* expdate;
char* fname;
char* lname;
};
typedef struct record* CardInfo;

//The tokenizer part is wrong
CardInfo* read(FILE *infile, CardInfo* info)
{
	info=malloc(sizeof(struct record*)*10);
	int flag;
	char x[25];
	char* token;
	info[0]=malloc(sizeof(struct record));
	info[0]->bankcode=malloc(sizeof(char)*6);
	info[0]->expdate=malloc(sizeof(char)*8);
	info[0]->fname=malloc(sizeof(char)*6);
	info[0]->lname=malloc(sizeof(char)*6);
	fscanf(infile,"%lld , %s , %s , %s , %s",&(info[0]->cardno),info[0]->bankcode,info[0]->expdate,info[0]->fname,info[0]->lname);
	fflush(stdin);
/*	token=strtok(x,",");
	info[0]->bankcode=token;
	token=strtok(NULL,",");
	info[0]->expdate=token;
	token=strtok(NULL,",");
	info[0]->fname=token;
	token=strtok(NULL,",");
	info[0]->lname=token;
	info[0]->bankcode=strtok(x,",");
	info[0]->expdate=strtok(NULL,",");
	info[0]->fname=strtok(NULL,",");
	info[0]->lname=strtok(NULL,",");    */
	int count=0;	
	int limit=10;

	while(flag!=EOF)
	{
		if(count+1==limit)
		{
			limit*=10;
			info=realloc(info,sizeof(struct record)*limit);
		}
		count++;
		info[count]=malloc(sizeof(struct record));
		info[count]->bankcode=malloc(sizeof(char)*6);
		info[count]->expdate=malloc(sizeof(char)*8);
		info[count]->fname=malloc(sizeof(char)*6);
		info[count]->lname=malloc(sizeof(char)*6);
		flag=fscanf(infile,"%lld , %s , %s , %s , %s",&(info[count]->cardno),info[count]->bankcode,info[count]->expdate,info[count]->fname,info[count]->lname);
		fflush(stdin);
	/*	info[count]->bankcode=strtok(x,",");
		info[count]->expdate=strtok(x,",");
		info[count]->fname=strtok(NULL,",");
		info[count]->lname=strtok(NULL,",");     */
		
	}
	printf("Successfully read %d records\n",count);
	return info;
}

void write()
{
	FILE *ofile=fopen("TimeToRead.txt","w");
	double elapsedTime;
	CardInfo* try;
	struct timeval t1, t2;
	
	FILE *inputfile=fopen("10","r");
	gettimeofday(&t1,NULL);
	try=read(inputfile,try);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	fprintf(ofile,"Total time for 10 is %lf ms.\n",elapsedTime);
	
	inputfile=fopen("100","r");
	gettimeofday(&t1,NULL);
	try=read(inputfile,try);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	fprintf(ofile,"Total time for 100 is %lf ms.\n",elapsedTime);
	
	inputfile=fopen("1000","r");
	gettimeofday(&t1,NULL);
	try=read(inputfile,try);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	fprintf(ofile,"Total time for 1000 is %lf ms.\n",elapsedTime);
	
	inputfile=fopen("10000","r");
	gettimeofday(&t1,NULL);
	try=read(inputfile,try);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	fprintf(ofile,"Total time for 10000 is %lf ms.\n",elapsedTime);
	
/*	inputfile=fopen("100000","r");
	gettimeofday(&t1,NULL);
	try=read(inputfile,try);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	fprintf(ofile,"Total time for 100000 is %lf ms.\n",elapsedTime);		*/			
	
}			


CardInfo* insertInOrder(CardInfo* insinto,CardInfo toins,int end)
{
//	int size=sizeof(insinto)/sizeof(CardInfo);
	int i,j;
	CardInfo temp=(CardInfo)malloc(sizeof(struct record));
	temp->bankcode=malloc(sizeof(char)*6);
	temp->expdate=malloc(sizeof(char)*8);
	temp->fname=malloc(sizeof(char)*6);
	temp->lname=malloc(sizeof(char)*6);
	temp->cardno=toins->cardno;
	temp->bankcode=*(toins->bankcode);
	temp->expdate=*(toins->expdate);
	temp->fname=*(toins->fname);
	temp->lname=*(toins->lname);
	for(i=0;i<=end;i++)
	{
		if((insinto[i]->cardno)>(toins->cardno))
		{
			for(j=end+1;j>i;j--)
				insinto[j]=insinto[j-1];
			insinto[i]=temp;
			return insinto;
		}
	}
	return insinto;
}


CardInfo* insSort(CardInfo* tosort, int size)
{
	int i;
	for(i=1;i<size;i++)
	{
		tosort=insertInOrder(tosort,tosort[i],i-1);
	}
	return tosort;
}




void timeToSort()
{
	FILE *ofile=fopen("TimeToSort.txt","w");
	double elapsedTime;
	CardInfo* try;
	struct timeval t1, t2;
	
	FILE *inputfile=fopen("10","r");
	try=read(inputfile,try);
	gettimeofday(&t1,NULL);
	try=insSort(try,10);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	fprintf(ofile,"Total time for 10 is %lf ms.\n",elapsedTime);
	fclose(inputfile);
	
	FILE *inputfile1=fopen("100","r");
	try=read(inputfile1,try);
	gettimeofday(&t1,NULL);
	try=insSort(try,100);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	fprintf(ofile,"Total time for 100 is %lf ms.\n",elapsedTime);
	fclose(inputfile1);
	
	FILE *inputfile2=fopen("1000","r");
	try=read(inputfile2,try);
	gettimeofday(&t1,NULL);
	try=insSort(try,1000);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	fprintf(ofile,"Total time for 1000 is %lf ms.\n",elapsedTime);
	fclose(inputfile2);
	
	FILE *inputfile3=fopen("10000","r");
	try=read(inputfile3,try);
	gettimeofday(&t1,NULL);
	try=insSort(try,10000);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	fprintf(ofile,"Total time for 10000 is %lf ms.\n",elapsedTime);
	fclose(inputfile3);
	
	fclose(ofile);
	
	
/*	inputfile=fopen("100000","r");
	try=read(inputfile,try);
	gettimeofday(&t1,NULL);
	try=insSort(try);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	fprintf(ofile,"Total time for 100000 is %lf ms.\n",elapsedTime);
	fclose(inputfile);
*/

}






int main()
{
	CardInfo* information;
	int norec;
	FILE *inputfile=fopen("100","r");
	if(inputfile==NULL)
		printf("Can't input properly\n");
	else
	{
		information=read(inputfile,information);
		printf("%lld\n",information[99]->cardno);
		printf("%s\n",information[99]->bankcode);
	//	int size=sizeof(information);
	//	printf("Size of list is %d\n",size);
	}
	write();
	information=insSort(information,100);
	timeToSort();
}
