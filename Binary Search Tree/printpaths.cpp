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
void printpaths(vector<int> ans,Node* root)
{
    if(root->left==NULL&&root->right==NULL)
    {   ans.push_back(root->data);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        ans.pop_back();
        return;
    }
    ans.push_back(root->data);
    if(root->left!=NULL)
    {printpaths(ans,root->left);}
    if(root->right!=NULL)
    {printpaths(ans,root->right);}
    ans.pop_back();
}
int main()
{
    vector<int> roots = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildtree(roots);
    print(root);
    cout << endl;
    vector<int> ans;
    printpaths(ans,root);
}