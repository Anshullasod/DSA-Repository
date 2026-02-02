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
Node *formtrees(Node *root, int val)
{
    if (root == NULL)
    {
        Node *temp = new Node(val);
        return temp;
    }
    else if (root->data > val)
    {
        root->left = formtrees(root->left, val);
    }
    else
    {
        root->right = formtrees(root->right, val);
    }
    return root;
}
Node *buildtree(vector<int> roots)
{
    Node *root = NULL;
    for (int i = 0; i < roots.size(); i++)
    {
        root = formtrees(root, roots[i]);
    }
    return root;
}
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
void helperinorder(vector<int> &inorder,Node* root)
{
    if(root==NULL)
    {
        return;
    }
    helperinorder(inorder,root->left);
    inorder.push_back(root->data);
    helperinorder(inorder,root->right);
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
Node* BSTtobalance(Node* root)
{
    vector<int> inorder;
    helperinorder(inorder,root);
    Node* newroot=formtree(inorder,0,inorder.size()-1);
    print(newroot);
    return newroot;
}
int main()
{
    vector<int> roots = {6,5,4,3,7,8,9};
    Node* root=buildtree(roots);
    print(root);
    cout<<endl;
    BSTtobalance(root);
     
}