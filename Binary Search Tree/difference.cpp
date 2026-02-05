#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *maketree(Node *root, int num)
{
    if (root == NULL)
    {
        Node *temp = new Node(num);
        return temp;
    }
    if (root->data > num)
    {
        root->left=maketree(root->left, num);
    }
    else
    {
       root->right= maketree(root->right, num);
    }
    return root;
}
Node *buildtree(vector<int> nums)
{
    Node *root = NULL;
    for (int i = 0; i < nums.size(); i++)
    {
        root = maketree(root, nums[i]);
    }
    return root;
}
static int mini = INT16_MAX;
void mindiff(Node *root, int k)
{
    if (root == NULL)
    {   cout<<mini<<endl;
        return;
    }
    int diff = abs(root->data - k);
    mini=min(diff,mini);
    if (root->data > k)
    {
        mindiff(root->left, k);
    }
    else if (root->data < k)
    {
        mindiff(root->right, k);
    }
}
int main()
{   
    vector<int> num = {8, 5, 3, 6, 11, 20};
    Node *root = buildtree(num);
    mindiff(root, 19);
    cout << mini << " ";
}