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
Node* deleteleaf(Node* root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    root->left=deleteleaf(root->left,val);
    root->right=deleteleaf(root->right,val);
    if(root->left==NULL&&root->right==NULL)
    {
        if(root->data==val)
        {
             root=NULL;
        }
    }
    return root;

}
int main()
{
     vector<int> roots={1,2,2,-1,-1,-1,3,2,-1,-1,4,-1,-1};
     int idx=-1;
     Node* root=maketree(roots,idx);
     leveltree(root);
     Node* deleted=deleteleaf(root,2);
     leveltree(deleted);



}