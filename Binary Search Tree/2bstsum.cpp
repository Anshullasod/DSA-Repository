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
Node *formtrees(Node *root, int val)
{
    if (root == NULL)
    {
        Node *temp = new Node(val);
        return temp;
    }
    else if (root->data > val)
    {
        root->left = formtrees(root->left, val);
    }
    else
    {
        root->right = formtrees(root->right, val);
    }
    return root;
}
Node *buildtree(vector<int> roots)
{
    Node *root = NULL;
    for (int i = 0; i < roots.size(); i++)
    {
        root = formtrees(root, roots[i]);
    }
    return root;
}
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}
void findinorder(vector<int> &inorder,Node* root )
{
    if(root==NULL)
    {
        return;
    }
    findinorder(inorder,root->left);
    inorder.push_back(root->data);
    findinorder(inorder,root->right);
}
int targetsum(Node* root1,Node* root2,int target)
{
    vector<int> inorder1;
    vector<int> inorder2;
    findinorder(inorder1,root1);
    findinorder(inorder2,root2);
    int num=0;
    int i=0,j=inorder2.size()-1;
    while(i<inorder1.size()&&j>=0)
    {
        if(target==inorder1[i]+inorder2[j])
        {
            num++;
            cout<<inorder1[i]<<" + "<<inorder2[j]<<endl;
            i++;
            j--;
        }
        else if(target>(inorder1[i]+inorder2[j]))
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return num;
}
int main()
{
    vector<int> nums1={5,3,2,4,7,6,8};
    vector<int> nums2={10,6,3,8,15,11,18};
    Node* root1=buildtree(nums1);
    Node* root2=buildtree(nums2);
   cout<<"Total num = "<<targetsum(root1,root2,16);
    
}