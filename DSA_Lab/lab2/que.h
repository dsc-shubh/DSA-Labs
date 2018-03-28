struct Node{
	int tid;
	int p;
	struct Node *next;
	};
typedef struct Node* Element;

struct myList{
	int prio;
	Element front;
	Element rear;
	};
typedef struct myList* Queue;

Queue newQ();
int isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q , Element e);
int lengthQ(Queue q);
