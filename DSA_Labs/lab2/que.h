struct node{
	int tid;
	int p;
	struct node* next;
	};
typedef struct node* Task;


struct list{
	int priority;
	Task head;
	Task tail;
	};
typedef struct list* Queue;



Queue newQ();
int isEmptyQ(Queue q);
Queue delQ(Queue q);
Task front(Queue q);
Queue addQ(Queue q , Task e);
int lengthQ(Queue q);
