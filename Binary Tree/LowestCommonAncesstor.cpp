#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
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
Node* LowestCA(Node* root,int n1,int n2)
{   if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1||root->data==n2)
    {
        return root;
    }
   Node* l=LowestCA(root->left,n1,n2);
   Node* r=LowestCA(root->right,n1,n2);

   if(l!=NULL&&r!=NULL)
   {
    return root;
   }
   return l==NULL?r:l;
}
bool findpath(Node* root,int n,vector<int> &path)
{
  if(root==NULL)
  {
    return false;
  }
  path.push_back(root->data);
  if(root->data==n)
  {
    return true;
  }
  if(findpath(root->left,n,path)||findpath(root->right,n,path))
    {return true;}
    path.pop_back();
    return false;
}
int LCA(Node* root,int n1,int n2)
{
vector<int> path1,path2;
findpath(root,n1,path1);
findpath(root,n2,path2);
int lca=-1;
for(int i=0,j=0;i<path1.size()&&j<path2.size();i++,j++)
{
    if(path1[i]!=path2[j])
    {   cout<<"LCA = "<<lca<<endl;
        return lca;
    }
    lca=path1[i];
}
}
int main()
{
    vector<int> roots={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int idx=-1;
    Node* root=maketree(roots,idx);
    int n1=4,n2=5;
    LCA(root,n1,n2);
    cout<<LowestCA(root,n1,n2)->data;
}
