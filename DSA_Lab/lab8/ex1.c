#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"tree.h"

int genRandom()
{
    return (150+(rand()%21));
}

Node add(Node tree,Node insert)
{
    if(tree==NULL)
    {
        tree=insert;
    }
    else if((tree->value)<(insert->value))
    {
        if((tree->right)==NULL)
        {
            tree->right=insert;
        }
        else
        {
            tree->right=add(tree->right,insert);
        }
    }
    else if((tree->value)>(insert->value))
    {
        if((tree->left)==NULL)
        {
            tree->left=insert;
        }
        else
        {
            tree->left=add(tree->left,insert);
        }
    }
 //   else
 //   {
 //       //handle duplicates later
 //   }
    return tree;
}

Node find(Node tree,int key)
{
    if(tree==NULL)
    {
        printf("Key %d not found\n",key);
        return NULL;
    }
    int r=tree->value;
    if(r==key)
    {
        printf("Found %d\n",key);
        return tree;
    }
    else if(r<key)
        return find(tree->right,key);
    else
        return find(tree->left,key);
}


Node findParent(Node tree,Node del)
{
    Node x=tree;
    if((((x->left)!=NULL)&&(((x->left)->value)==(del->value)))||(((x->right)!=NULL)&&(((x->right)->value)==(del->value))))
        return x;
    else if((tree->value)<(del->value))
    {
        return findParent(tree->right,del);
    }
    else
        return findParent(tree->left,del);
}





Node delNode(Node tree,int key)
{
    Node del=find(tree,key);
    Node par;
    par=NULL;
    if(del!=NULL)
        if(((del->value)!=(tree->value)))
            par=findParent(tree,del);
    if(par==NULL)
        par=(Node)malloc(sizeof(struct node));
    if(del==NULL)
    {
        printf("Can't delete\n");
    }
    else if((del->left==NULL)&&(del->right==NULL))
    {
        if(((par->left)!=NULL)&&(((par->left)->value)==(del->value)))
            par->left=NULL;
        else
            par->right=NULL;
        free(del);
    }
   else if((del->left==NULL)||(del->right==NULL))
    { 
        Node x=del;
        int t=del->value;
        if(del->left==NULL)
            del=del->right;
        else
            del=del->left;
        if(((par->left)!=NULL)&&(((par->left)->value)==t))
            par->left=del;
        else
            par->right=del;
        free(x);
    }
    else
    {
        Node x=del->right;
        while(x->left!=NULL)
        {
            x=x->left;
        }
        int t=x->value;
        x->value=del->value;
        del->value=t;
        if((x->left==NULL)&&(x->right==NULL))
        {
            free(x);
        }
        else
        {
            Node y=x;
            x=x->right;
            free(y);
        }
    }
    return tree;
}




void displayTree(Node tree)
{
    if(tree==NULL)
        return;
    printf("%d ",tree->value);
    displayTree(tree->left);
//    displayTree(tree->right);
}









