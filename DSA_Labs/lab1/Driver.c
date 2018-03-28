#include<stdio.h>
#include<stdlib.h>
#include"SeqList.h"

int main(){
/*	SeqList tryList=newList();
	Element first=(Element)malloc(sizeof(struct node));
	Element second=(Element)malloc(sizeof(struct node));
	Element third=(Element)malloc(sizeof(struct node));
	first->key=9;
	second->key=4;
	third->key=2;
	tryList=insertAtFront(tryList,first);
	tryList=insertAtEnd(tryList,third);
	tryList=insertAtFront(tryList,second);
	Element curr=tryList->front;
	while(curr!=NULL)
		{
			printf("%d",curr->key);
			curr=curr->next;
		} 
	printf("\n");
	SeqList tryList2=newList();
	Element first1=(Element)malloc(sizeof(struct node));
	Element second1=(Element)malloc(sizeof(struct node));
	Element third1=(Element)malloc(sizeof(struct node));
	first1->key=3;
	second1->key=5;
	third1->key=10;
	tryList2=insertAtFront(tryList2,first1);
	tryList2=insertAtEnd(tryList2,third1);
	tryList2=insertInOrder(tryList2,second1);
	Element curr1=tryList2->front;
	while(curr1!=NULL)
		{
			printf("%d",curr1->key);
			curr1=curr1->next;
		} 
	printf("\n");
	tryList=insertionSort(tryList);
	curr=tryList->front;
	while(curr!=NULL)
		{
			printf("%d",curr->key);
			curr=curr->next;
		} 
	printf("\n");
	tryList2=insertionSort(tryList2);
	curr1=tryList2->front;
	while(curr1!=NULL)
		{
			printf("%d",curr1->key);
			curr1=curr1->next;
		} 
	printf("\n");
	SeqList sq=merge(tryList,tryList2);
	Element curr2=sq->front;
	while(curr2!=NULL)
		{
			printf("%d",curr2->key);
			curr2=curr2->next;
		} 
	printf("\n");
*/
	SeqList tryList=newList();
	int t=1; Element curr;
	while(t!=0)
	{
		printf("Enter 1 to insert element at first\n");
		printf("Enter 2 to insert element at last\n");
		printf("Enter 3 to insert element in order\n");
		printf("Enter 4 to delete an element\n");
		printf("Enter 5 to delete the first element\n");
		printf("Enter 6 to find an element\n");
		printf("Enter 7 to display list\n");
		printf("Enter 8 to sort the list\n");
		printf("Enter 9 to exit\n");
		int n,a;
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter element to be inserted\n");
				scanf("%d",&a);
				Element first=(Element)malloc(sizeof(struct node));
				first->key=a;
				tryList=insertAtFront(tryList,first);
					
			break;
			case 2:
				printf("Enter element to be inserted\n");
				scanf("%d",&a);
				Element first1=(Element)malloc(sizeof(struct node));
				first1->key=a;
				tryList=insertAtEnd(tryList,first1);	
			break;
			case 3:
				printf("Enter element to be inserted\n");
				scanf("%d",&a);
				Element first2=(Element)malloc(sizeof(struct node));
				first2->key=a;
				tryList=insertInOrder(tryList,first2);	
			break;
			case 4:
				printf("Enter element to be deleted\n");
				scanf("%d",&a);
				Element first3=(Element)malloc(sizeof(struct node));
				first3->key=a;
				tryList=delete(tryList,first3);	
			break;			
			case 5:
				tryList=deleteAtFront(tryList);	
			break;	
			case 6:
				printf("Enter element to find\n");
				scanf("%d",&a);
				Element b;
				b=find(tryList,a);	
			break;
			case 7:
				curr=tryList->front;
				while(curr!=NULL)
				{
					printf("%d\n",curr->key);
					curr=curr->next;
				} 
			break;
			case 8:
				tryList=insertSort(tryList);
				break;
			case 9:
				t=0;
			break;
			default:
				printf("Wrong Case\n");
		}
			
	}
	
}
			










