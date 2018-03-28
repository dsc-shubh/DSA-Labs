struct node{
    int value;
    struct node* left;
    struct node* right;
    int height_bal : 2;
};
typedef struct node* Node;


int genRandom();
Node add(Node tree,Node insert);
Node find(Node tree,int key);
Node delNode(Node tree,int key);
void displayTree(Node tree);
Node findParent(Node tree,Node del);