#include<stdio.h>
#include<stdlib.h>
#include"que.h"

int main(){
	Queue tryList=newQ();
	Element first=(Element)malloc(sizeof(struct Node));
	Element second=(Element)malloc(sizeof(struct Node));
	Element third=(Element)malloc(sizeof(struct Node));
	first->data=1;
	second->data=2;
	third->data=3;
	tryList=addQ(tryList,first);
	tryList=addQ(tryList,third);
	tryList=addQ(tryList,second);
	Element curr=tryList->front;
	while(curr!=NULL)
		{
			printf("%d",curr->data);
			curr=curr->next;
		} 

/*	SeqList tryList=newList();
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
		printf("Enter 8 to exit\n");
		int n,a;
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter element to be inserted\n");
				scanf("%d",&a);
				Element first=(Element)malloc(sizeof(struct Node));
				first->data=a;
				tryList=insertAtFront(tryList,first);
					
			break;
			case 2:
				printf("Enter element to be inserted\n");
				scanf("%d",&a);
				Element first1=(Element)malloc(sizeof(struct Node));
				first1->data=a;
				tryList=insertAtEnd(tryList,first1);	
			break;
			case 3:
				printf("Enter element to be inserted\n");
				scanf("%d",&a);
				Element first2=(Element)malloc(sizeof(struct Node));
				first2->data=a;
				tryList=insertInOrder(tryList,first2);	
			break;
			case 4:
				printf("Enter element to be deleted\n");
				scanf("%d",&a);
				Element first3=(Element)malloc(sizeof(struct Node));
				first3->data=a;
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
				curr=tryList->head;
				while(curr!=NULL)
				{
					printf("%d\n",curr->data);
					curr=curr->next;
				} 
			break;
			case 8:
				t=0;
			break;
			default:
				printf("Wrong Case\n");
		}
			
	} */
}
			










