#include <iostream>
#include <vector>
#include<algorithm>
#include<climits>
using namespace std;
class Node
{   public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Info{
    public:
    bool isBST;
    int max,min,sz;
    Info(bool isBST,int max,int min,int sz)
    {
      this->isBST=isBST;
      this->max=max;
      this->min=min;
      this->sz=sz;
    }
};
static int maxsz=0;
Info* maxBST(Node* root)
{  
   if(root==NULL)
   {
    return new Info(true,INT32_MIN,INT32_MAX,0);
   } 
   Info* leftbst=maxBST(root->left);
   Info* rightbst=maxBST(root->right);
   int currmax,currmin,currsize;
   currmax=max({root->data,leftbst->max,rightbst->max}); 
   currmin=min({root->data,leftbst->min,rightbst->min});
   currsize=leftbst->sz+rightbst->sz+1;
   if(leftbst->isBST&&rightbst->isBST&&
     root->data>leftbst->max&&root->data<rightbst->min)
   {
     maxsz=max(maxsz,currsize);
     return new Info(true,currmax,currmin,currsize);
   }
   return new Info(false,currmax,currmin,currsize);
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);
    maxBST(root);
    cout<<maxsz<<" ";
    
}