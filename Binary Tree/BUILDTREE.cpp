#include<iostream>
#include<map>
#include<queue>
using namespace std;
#include<vector>
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
Node *leveltree(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
    cout << endl;
}
Node* formtree(int ps,int pe,int is,int ie,vector<int> preorder,map<int,int> m)
{
 if(ps>pe||is>ie)
 {
    return NULL;
 }
 int rootval=preorder[ps];
 Node* temp=new Node(rootval);
 int inroot=m[rootval];
 int numsleft=inroot-is;
 temp->left=formtree(ps+1,ps+numsleft,is,inroot-1,preorder,m);
 temp->right=formtree(ps+numsleft+1,pe,inroot+1,ie,preorder,m);
 return temp;}
Node* maketree(vector<int> preorder,vector<int> inorder)
{
    map<int,int> m;
    for(int i=0;i<inorder.size();i++)
    {
        m[inorder[i]]=i;
    }
    Node* root=formtree(0,preorder.size()-1,0,inorder.size()-1,preorder,m);
    leveltree(root);
    return root;
}
int main()
{
    vector<int> inorder={4,2,5,1,3,6};
    vector<int> preorder={1,2,4,5,3,6};
    maketree(preorder,inorder);
}