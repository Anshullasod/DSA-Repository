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
int maxsum(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=maxsum(root->left);
    int rs=maxsum(root->right);
    int cs=root->data;
    return max({ls,rs,ls+rs+cs});
}

int main()
{
    vector<int> roots = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int idx = -1;
    Node *root = maketree(roots, idx);
    leveltree(root);
    cout<<"MAX SUM = "<<maxsum(root);

    
}