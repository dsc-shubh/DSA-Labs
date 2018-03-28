struct ss{
	int low;
	int high;
	struct ss* bottom;
	};
typedef struct ss* Element;


struct stack{
	Element top;
	};
typedef struct stack* Stack;



Stack newStack();
int isEmptyStack(Stack s);
Stack pop(Stack s);
Stack push(Stack s , Element e);
int lengthS(Stack s);
void showStack(Stack s);
