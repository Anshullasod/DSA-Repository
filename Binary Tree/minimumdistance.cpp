#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
class Node
{
public:
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
Node *maketree(vector<int> &roots, int &idx)
{
    idx++;
    if (roots[idx] == -1)
    {
        return NULL;
    }
    Node *temp = new Node(roots[idx]);
    temp->left = maketree(roots, idx);
    temp->right = maketree(roots, idx);
    return temp;
}
Node* LCA2(Node* root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1||root->data==n2)
    {
        return root;
    }
    Node* leftlca=LCA2(root->left,n1,n2);
    Node* rightlca=LCA2(root->right,n1,n2);
    if(leftlca!=NULL&&rightlca!=NULL)
    {
        return root;
    }
    return (leftlca!=NULL)?leftlca:rightlca;
    
}
int dist(Node* root,int n)
{
  if(root==NULL)
  {
    return -1;
  }
  if(root->data==n)
  {
    return 0;
  }
  int distl=dist(root->left,n);
  if(distl!=-1)
  { 
    return distl+1;
  }
  int distr=dist(root->right,n);
    if(distr!=-1)
    {
        return distr+1;
    }
   return -1; 
  }
int mindist(Node* root,int n1,int n2)
{
    Node *lca=LCA2(root,n1,n2);
    int dist1=dist(lca,n1);
    int dist2=dist(lca,n2);
    return dist1+dist2;
}

int main()
{
    vector<int> roots = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int idx = -1;
    Node *root = maketree(roots, idx);
    cout<<mindist(root,6,4);
    
}