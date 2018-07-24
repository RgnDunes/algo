#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;


struct node
{
        int data;
        node* lptr;
        node* rptr;
};

void levelOrder(node* tree)
{
        queue<node*> q;
        q.push(tree);
        while(!q.empty())
        {
                node* a=q.front();
                if(a->lptr!=NULL)
                q.push(a->lptr);
                if(a->rptr!=NULL)
                q.push(a->rptr);
                q.pop();
                cout<<a->data<<" ";
        }
        return ;
}


void bt(node*& tree,int i,int a[],int n)
{
        if(2*i+1<n)
        {
                node* temp =(node*) malloc(sizeof(node));
                temp->lptr=NULL;
                temp->rptr=NULL;
                temp->data=a[2*i+1];
                tree->lptr=temp;
                cout<<temp->data<<endl;
                bt(tree->lptr,2*i+1,a,n);
        }
        if(2*i+2<n)
        {
                node* temp =(node*) malloc(sizeof(node));
                temp->lptr=NULL;
                temp->rptr=NULL;
                temp->data=a[2*i+2];
                tree->rptr=temp;
                cout<<temp->data<<endl;
                bt(tree->rptr,2*i+2,a,n);
        }
        return ;
}


int main()
{
        int n=9;
        int i=0;
        node* tree = NULL;
        node* news= (node*) malloc(sizeof(node));
        int a[]={20,40,13,85,53,97,32,58,74};
         news->data=a[0];
        news->lptr=NULL;
        news->rptr=NULL;
        tree=news;

        bt(tree,i,a,n);

        cout<<"Level order: ";levelOrder(tree);
        return 0;
}
