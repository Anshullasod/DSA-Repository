#include <iostream>
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
Node* formtree(vector<int> roots,int st,int end)
{
  if(st>end)
  {
    return NULL;
  }  
 int mid=st+(end-st)/2;
 Node* root=new Node(roots[mid]);
 root->left=formtree(roots,st,mid-1);
 root->right=formtree(roots,mid+1,end);
 return root;
}
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}
int main()
{
    vector<int> roots = {3,4,5,6,7,8,9};
    Node* root=formtree(roots,0,roots.size()-1);
    print(root);
     
}