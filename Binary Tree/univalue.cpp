#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
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
Node* maketree(vector<int> &roots,int &idx)
{   idx++;
    if(roots[idx]==-1)
    {
        return NULL;
    }
    Node* temp=new Node(roots[idx]);
    temp->left=maketree(roots,idx);
    temp->right=maketree(roots,idx);
    return temp;
}
Node* leveltree(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
    cout<<endl;
}
bool univalue(Node* root)
{
    queue<Node*> q;
    q.push(root);
    int val=root->data;
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp->data!=val)
        {   cout<<"FALSE"<<endl;
            return false;
        }
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
    cout<<"TRUE"<<endl;
    return true;
}
bool univalusingrec(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    if(!univalusingrec(root->left)||!univalusingrec(root->right))
    {
        return false;
    }
    if(root->left!=NULL)
    {
        if(root->data!=root->left->data)
        {
            return false;
        }
    }
    if(root->right!=NULL)
    {
        if(root->data!=root->right->data)
        {
            return false;
        }
    }
    return true;
}
int main()
{
     vector<int> roots={1,1,-1,-1,-1,-1};
     int idx=-1;
     Node* root=maketree(roots,idx);
     leveltree(root);
  
     cout<<univalusingrec(root);
}