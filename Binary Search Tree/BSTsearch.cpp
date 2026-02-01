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
Node* insert(Node* root,int val)
{
    if(root==NULL)
    {   root=new Node(val);
        return root;
    }
    if(root->data>val)
    {
        root->left=insert(root->left,val);
    }
   else if(root->data<val)
    {
        root->right=insert(root->right,val);
    }
    return root;

}
Node* buildtree(vector<int> roots)
{
    Node* root=NULL;
    for(int i=0;i<roots.size();i++)
    {
        root=insert(root,roots[i]);
    }
    return root;
}
bool search(Node* root,int target)
{
  if(root==NULL)
  { cout<<"False"<<endl;
    return false;
  }
  if(root->data==target)
  {
    cout<<"true"<<endl;
    return true;
  }
  if(root->data>target)
  { return search(root->left,target);}
  else{
  return search(root->right,target);}
}
void print(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main()
{
    int idx = -1;
    vector<int> roots = {5,2,1,4,3,6,7};
    Node* root=buildtree(roots);
    print(root);
    cout << endl;
    search(root,7);
    search(root,9);  
 }