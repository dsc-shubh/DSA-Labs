#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"tree.h"

int main()
{
    srand(time(0));
    Node tree;
    tree=NULL;
    for(int i=0;i<20;i++)
    {
        Node ins=(Node)malloc(sizeof(struct node));
        ins->left=NULL;
        ins->right=NULL;
        ins->height_bal=0;
        int d=genRandom();
        printf("%d ",d);
        ins->value=d;
        tree=add(tree,ins);
        //displayTree(tree);
        printf("\n");
    }
    displayTree(tree);
    Node x=find(tree,155);
    x=find(tree,160);
    tree=delNode(tree,160);
    displayTree(tree);
    tree=delNode(tree,155);
    displayTree(tree);
}