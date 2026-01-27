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
int Kthancestor(Node* root,Node* n,int k)
{
    if(root==NULL)
    {
      return -1;
    }
     if(root==n)
     {
        return 0;
     }

     int lk=Kthancestor(root->left,n,k);
     if(lk!=-1)
     {  if(lk+1==k)
        {
            cout<<root->data<<" ";
        }
        return lk+1;
     }
     int rk=Kthancestor(root->right,n,k);
     if(rk!=-1)
     {  if(rk+1==k)
        {
            cout<<root->data<<" ";
        }
        return rk+1;
     }

     return -1;
}
int main()
{
    vector<int> roots = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int idx = -1;
    Node *root = maketree(roots, idx);
    leveltree(root);
    Kthancestor(root,root->left->left,2);

    
}