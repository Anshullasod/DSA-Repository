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
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (root->data > val)
    {
        root->left = insert(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = insert(root->right, val);
    }
    return root;
}
Node *buildtree(vector<int> roots)
{
    Node *root = NULL;
    for (int i = 0; i < roots.size(); i++)
    {
        root = insert(root, roots[i]);
    }
    return root;
}
Node *search(Node *root, int target)
{
    if (root == NULL)
    {
        cout << "False" << endl;
        return NULL;
    }
    if (root->data == target)
    {
        cout << "true" << endl;
        return root;
    }
    if (root->data > target)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}
Node *getinorder(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *deletenode(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (val < root->data)
    {
        root->left = deletenode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deletenode(root->right, val);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL || root->right != NULL)
        {
            return root->left == NULL ? root->right : root->left;
        }
        else
        {
            Node *inorder = getinorder(root->right);
            root->data = inorder->data;
            deletenode(root->right, inorder->data);
        }
        return root;
    }
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
void printinrange(Node *root, int st, int end)
{
    if (root == NULL)
    {
        return;
    }

    if (st <= root->data && root->data <= end)
    {
        printinrange(root->left, st, end);
        cout << root->data << " ";

        printinrange(root->right, st, end);
    }
    if (root->data < st)
    {
        printinrange(root->right, st, end);
    }

    if (root->data > end)
    {
        printinrange(root->left, st, end);
    }
}
int main()
{
    int idx = -1;
    vector<int> roots = {5, 2, 1, 4, 3, 6, 7};
    Node *root = buildtree(roots);
    print(root);
    cout << endl;
    printinrange(root, 2, 6);
}