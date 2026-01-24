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

pair<int,int> diameter(Node* root)
{//pair(Diameter,Height)
    if(root==NULL)
    {
        return make_pair(0,0);
    }
    pair<int,int> leftside=diameter(root->left);
    pair<int,int> rightside=diameter(root->right);
    int currdiam=leftside.second+rightside.second+1;
    int maxidia=max({currdiam,leftside.first,rightside.first});
    int finalht=max(leftside.second,rightside.second);
    return make_pair(maxidia,height(root));
}
int main()
{
  vector<int> roots={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root=buildtree(roots);
  cout<<diameter(root).first;
}