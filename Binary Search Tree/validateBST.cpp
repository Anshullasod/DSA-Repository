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
Node *formtree(Node *root, int val)
{
    if (root == NULL)
    {
        Node *temp = new Node(val);
        return temp;
    }
    else if (root->data > val)
    {
        root->left = formtree(root->left, val);
    }
    else
    {
        root->right = formtree(root->right, val);
    }
    return root;
}
Node *buildtree(vector<int> roots)
{
    Node *root = NULL;
    for (int i = 0; i < roots.size(); i++)
    {
        root = formtree(root, roots[i]);
    }
    return root;
}
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

bool isBST(Node* root,Node* min,Node* max)
{
if(root==NULL)
{
    return true;
}
if(min!=NULL&&root->data<min->data)
{
    return false;
}
if(max!=NULL&&root->data>max->data)
{
    return false;
}
 return isBST(root->left,min,root)&&isBST(root->right,root,max);
}
int main()
{
    vector<int> roots = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildtree(roots);
    print(root);
    cout << endl;
    cout<<isBST(root,NULL,NULL);
}