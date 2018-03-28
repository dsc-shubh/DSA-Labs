#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ex1.h"

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[])
{
	int i=0,j,k;
	j=0;
	k=0;
	while((i<sz1)&&(i<sz2))
	{
		if((Ls1[j]->cgpa)<(Ls2[k]->cgpa))
		{
			strcpy(Ls[i]->name,Ls1[j]->name);
			Ls[i]->cgpa=Ls1[j]->cgpa;
			i++;
			j++;
		}
		else
		{
			strcpy(Ls[i]->name,Ls2[k]->name);
			Ls[i]->cgpa=Ls2[k]->cgpa;
			i++;
			k++;
		}
	}
	if(i==sz1)
	{
		while(k<sz2)
		{
			strcpy(Ls[i]->name,Ls2[k]->name);
			Ls[i]->cgpa=Ls2[k]->cgpa;
			i++;
			k++;	
		}
	}
	else
	{
		while(j<sz1)
		{
			strcpy(Ls[i]->name,Ls1[j]->name);
			Ls[i]->cgpa=Ls1[j]->cgpa;
			i++;
			j++;	
		}
	}
}	






void recMergeSort(Element Ls[],int st,int en)
{
	if((en-st)<1)
		return;
	int mid=(st+en)/2;
	recMergeSort(Ls,st,mid);
	recMergeSort(Ls,mid+1,en);
	
	Element* Ls1=(Element*)malloc((mid-st+1)*sizeof(Element));
	for(int i=0;i<(mid-st+1);i++)
	{
		Ls1[i]=(Element)malloc(sizeof(struct Node));
		*Ls1[i]=*Ls[i+st];
//		strcpy(Ls1[i]->name,Ls[i+st]->name);
//		Ls1[i]->cgpa=Ls[i+st]->cgpa;
//		printf("%s\n",Ls1[i]->name);
//		printf("%f\n",Ls1[i]->cgpa);
	}
	
	
	Element* Ls2=(Element*)malloc((en-mid)*sizeof(Element));
	for(int i=0;i<(en-mid);i++)
	{
		Ls2[i]=(Element)malloc(sizeof(struct Node));
		*Ls2[i]=*Ls[i+mid+1];
//		strcpy(Ls2[i]->name,Ls[i+mid+1]->name);
//		Ls2[i]->cgpa=Ls[i+mid+1]->cgpa;
	}
	
	Element* Ls3=(Element*)malloc((en-st+1)*sizeof(Element));
	for(int i=0;i<(en-st+1);i++)
		Ls3[i]=(Element)malloc(sizeof(struct Node));
		
	merge(Ls1,mid-st+1,Ls2,en-mid,Ls3);
	for(int i=st;i<=en;i++)
		*Ls[i]=*Ls3[i-st];
}



void iterMergeSort(Element Ls[],int n)
{
	int maxSlSz;
	int st1,slSz,st2,en2;
	int last=n-1;
	for(maxSlSz=1;maxSlSz<n;maxSlSz*=2) ;
	/* Postcondition: maxSlSz/2 < n <= maxSlSz */
	maxSlSz /= 2;
	/* Postcondition: maxSlSz < n <= 2*maxSlSz */
	for (slSz=1; slSz<=maxSlSz; slSz*=2) {
		for (st1=0; st1<=last; st1=st1+2*slSz) {
			st2=st1+slSz;
			en2=st2+slSz-1;
			if (st2 > last) { // Handle uneven-sized sublists
				en2 = last;
				if (st2-1 > last) { st2=last+1; }
			}
			
			Element* Ls1=(Element*)malloc((st2-st1)*sizeof(Element));
			for(int i=0;i<(st2-st1);i++)
			{
				Ls1[i]=(Element)malloc(sizeof(struct Node));
				*Ls1[i]=*Ls[i+st1];
			}
		
			Element* Ls2=(Element*)malloc((en2-st2+1)*sizeof(Element));
			for(int i=0;i<(en2-st2+1);i++)
			{
				Ls2[i]=(Element)malloc(sizeof(struct Node));
				*Ls2[i]=*Ls[i+st2];
			}
	
			Element* Ls3=(Element*)malloc((en2-st1+1)*sizeof(Element));
			for(int i=0;i<(en2-st1+1);i++)
				Ls3[i]=(Element)malloc(sizeof(struct Node));
						
			merge(Ls1,st2-st1,Ls2,en2-st2+1,Ls3);
			for(int i=st1;i<=en2;i++)
				*Ls[i]=*Ls3[i-st1];
		}
	}
}



























	














































	
	
