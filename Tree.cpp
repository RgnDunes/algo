#include <list>
#include <iostream>
using namespace std;

struct bstnode
{
	int val;
	 bstnode* bstleft;
	 bstnode* bstright;
};
bstnode* getNewNode(int data)
{
	bstnode* newNode=new bstnode();
	newNode->val=data;
	newNode->bstleft=NULL;
	newNode->bstright=NULL;
	return newNode;
}
bool search(bstnode* root,int data)
{
	if(root==NULL)return false;
	else if(root->val==data)return true;
	else if(data>=root->val) return search(root->bstright,data);
	else return search(root->bstleft,data);
}
bstnode* insert(bstnode* root,int data)
{
	if(root==NULL)
	{
		root=getNewNode(data);
	}
	else if(root->val<=data)
	{
		root->bstright=insert(root->bstright,data);
	}
	else
	{
		root->bstleft=insert(root->bstleft,data);
	}
	return root;
}
int main()
{
	int arr[6]={2,4,7,5,6,3};
 	struct bstnode* rootptr;
 	rootptr=NULL;
 	int i=0;
 	while(i<6)
 	{
 	 	rootptr=insert(rootptr,arr[i]);
		  i++;	   
    }
	if(search(rootptr,22)==true)
	cout<<"Found";
	else
	cout<<"not";		
}
