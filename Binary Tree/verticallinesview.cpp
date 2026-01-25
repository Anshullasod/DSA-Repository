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
void topview(Node *root)
{
    map<int, vector<int>> m;
    // distance,data
    queue<pair<Node *, int>> q; // Node,distance
    int dis = 0;
    q.push(make_pair(root, dis));
    while (!q.empty())
    {
        pair<Node *, int> p1 = q.front();
        q.pop();
        m[p1.second].push_back(p1.first->data); //changefirst
        if (p1.first->left != NULL)
        {
            q.push(make_pair(p1.first->left, p1.second - 1));
        }
        if (p1.first->right != NULL)
        {
            q.push(make_pair(p1.first->right, p1.second + 1));
        }
    }
    for (auto i : m)
    {
      for(auto val:i.second)
      {
        cout<<val<<",";
      }
      cout<<endl;
    }
    cout << endl;
}

int main()
{
    vector<int> roots = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int idx = -1;
    Node *root = maketree(roots, idx);
    leveltree(root);
    cout << endl;
    topview(root);
}
