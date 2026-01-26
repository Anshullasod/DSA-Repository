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
Node *leveltree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
        }
        else
        {
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
    }
}
Node* invert(Node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    invert(root->left);
    invert(root->right);
    swap(root->left,root->right);
    return root;
}
int main()
{
     vector<int> roots={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
     int idx=-1;
     Node* root=maketree(roots,idx);
     leveltree(root);
     cout<<endl;
     Node* inverted=invert(root);
     leveltree(inverted);
     

}