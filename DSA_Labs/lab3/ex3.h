struct node
{
int data;
struct node* next;
};
typedef struct node* Node;


struct list
{
Node front;
Node rear;
};
typedef struct list* List;





List createList(int n);
List createCycle(List Ls,int n);
void* myalloc(int space);
void myfree(void* del);
int testCyclic(List Ls);
List makeCircularList(List Ls);
