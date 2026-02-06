#include <iostream>
#include <vector>
#include<stack>
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
int countpairs(Node* root1,Node* root2,int k)
{
 if(root1==NULL||root2==NULL)
 {
    return 0;
 }
 stack<Node*> s1,s2;
 Node* curr1=root1, *curr2=root2;
 int count=0;
 while(true)
 {
    while(curr1!=NULL)
    {
        s1.push(curr1);
        curr1=curr1->left;
    }
    while(curr2!=NULL)
    {
        s2.push(curr2);
        curr2=curr2->right;
    }
    if(s1.empty()||s2.empty())
    {
        break;
    }
    Node* top1=s1.top();
    Node* top2=s2.top();

    if(top1->data+top2->data==k)
    {
        count++;
        cout<<top1->data<<" + "<<top2->data<<endl;
        s1.pop();
        s2.pop();
        curr1=top1->right;
        curr2=top2->left;
    }
    else if(top1->data+top2->data<k)
    {
        s1.pop();
        curr1=top1->right;
    }
    else
    {
        s2.pop();
        curr2=top2->left;
    }
}
return count;
}

int main()
{
    vector<int> nums1={5,3,2,4,7,6,8};
    vector<int> nums2={10,6,3,8,15,11,18};
    Node* root1=buildtree(nums1);
    Node* root2=buildtree(nums2);
    cout<<countpairs(root1,root2,16); 
}