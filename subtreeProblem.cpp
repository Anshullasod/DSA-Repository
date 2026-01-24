#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
static int pos = -1;
Node *buildtree(vector<int> &roots)
{
    pos++;
    if (roots[pos] == -1)
    {
        return NULL;
    }
    Node *temp = new Node(roots[pos]);
    temp->left = buildtree(roots);
    temp->right = buildtree(roots);
    return temp;
}
bool ischeck(Node *root, Node *subroot)
{   if (root == NULL && subroot == NULL)
    {
        return true;
    }
    else if (root == NULL || subroot == NULL)
    {
        return false;
    }
    if (root->data != subroot->data)
    {
        return false;
    }
    return ischeck(root->left, subroot->left) && ischeck(root->right, subroot->right);
}
bool ispresent(Node *root, Node *subroot)
{
    if (root == NULL && subroot == NULL)
    {
        return true;
    }
    else if (root == NULL || subroot == NULL)
    {
        return false;
    }
    if (root->data == subroot->data)
    {
        if (ischeck(root, subroot))
        {
            return true;
        }
    }
    int leftsubtree = ispresent(root->left, subroot);
    if (!leftsubtree)
    {
        return ispresent(root->right, subroot);
    }
    return true;
}
int main()
{
    vector<int> roots = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildtree(roots);
    pos=-1;
    vector<int> subtree = {2, 4, -1, -1, 5, -1, -1};
    Node *subroot = buildtree(subtree);
    if(ispresent(root, subroot))
    {
        cout<<"True";
        return 0;
    }
    cout<<"FALSE";
    return 0;
}