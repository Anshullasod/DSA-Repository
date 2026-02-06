#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
class Info
{
public:
    bool isBST;
    int max, min, size,sum;
    Info(bool isBST, int max, int min, int sz,int sum)
    {
        this->isBST = isBST;
        this->max = max;
        this->min = min;
        size = sz;
        this->sum=sum;
    }
};
static Node *maxbst = NULL;
static int maxsz = 0;
static int maxsum=0;
Info *maxBST(Node *root)
{
    if (root == NULL)
    {
        return new Info(true, INT_MIN, INT_MAX, 0,0);
    }
    Info *leftinfo = maxBST(root->left);
    Info *rightinfo = maxBST(root->right);
    int currmax = max({root->data, leftinfo->max, rightinfo->max});
    int currmin = min({root->data, leftinfo->min, rightinfo->min});
    int currsize = leftinfo->size + rightinfo->size + 1;
    int currsum = leftinfo->sum+rightinfo->sum+root->data;
    if (leftinfo->isBST && rightinfo->isBST &&
        leftinfo->max < root->data && rightinfo->min > root->data)
    {
        maxsz = max(currsize, maxsz);
        maxsum=max(maxsum,currsum);
        return new Info(true, currmax, currmin, currsize,currsum);
    }
    return new Info(false, currmax, currmin, currsize,currsum);
}
static int idx = -1;
Node *buildBT(vector<int> num)
{
    idx++;
    if (num[idx] == -1)
    {
        return NULL;
    }
    Node *temp = new Node(num[idx]);
    temp->left = buildBT(num);
    temp->right = buildBT(num);
    return temp;
}
int main()
{
    vector<int> num = {1, 4, 2, -1, -1, 4, -1, -1, 3, 2, -1, 
                      -1, 5, 4, -1, -1, 6, -1, -1};
    Node *root = buildBT(num);
    maxBST(root);
    cout << maxsz << " ";
    cout<<endl<<maxsum<<" ";
}