#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int val)
  {
    data=val;
    left=NULL;
    right=NULL;
  }
};
static int pos=-1;
Node* buildtree(vector<int> &roots)
{
  pos++;
  if(roots[pos]==-1)
  {
    return NULL;
  }
  Node* temp=new Node(roots[pos]);
  temp->left=buildtree(roots);
  temp->right=buildtree(roots);
  return temp;
}

int sum(Node* root,int s)
{
  if(root==NULL)
  {return 0;}
  s+=root->data+sum(root->left,s)+sum(root->right,s);
  return s;
}
int count(Node* root)
{
  if(root==NULL)
  {
    return 0;
  }
  return count(root->left)+count(root->right)+1;
}
int height(Node* root)
{
  if(root==NULL)
  {
    return 0;
  }
  int lh=height(root->left);
  int rh=height(root->right);
  int maxi=max(lh,rh);
  return maxi+1;
}
void leveltree(Node *root)
{
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty())
  {
    Node* curr=q.front();
    q.pop();
    if(curr==NULL)
    { if(q.empty())
      {
        break;
      }
      cout<<endl;
      q.push(NULL);
    }
    else{
    cout<<curr->data<<" ";
    if(curr->left!=NULL)
    {
      q.push(curr->left);
    }
    if(curr->right!=NULL)
    {
      q.push(curr->right);
    }
  }}
}
int diameter(Node* root)
{
  if(root==NULL)
  {
    return 0;
  }
  int rootdia=height(root->left)+height(root->right)+1;
  int lefht=diameter(root->left);
  int rightht=diameter(root->right);
  int maxidia= max({lefht,rightht,rootdia});
  return maxidia;
  
}
int main()
{
  vector<int> roots={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root=buildtree(roots);
  leveltree(root);
  cout<<endl;
  cout<<"Height = "<<height(root)<<endl;
  cout<<"Total nodes = "<<count(root)<<endl;
  cout<<"Total sum = "<<sum(root,0)<<endl;
  cout<<"Diameter = "<<diameter(root);
}