#include <iostream>
#include<stack>
#include <vector>
#include <queue>
#include <list>
using namespace std;
class Graph
{
public:
    int V;
    list<int> *l;
    bool isuni;
    Graph(int V, bool uni)
    {
        this->V = V;
        isuni = uni;
        l = new list<int>[V];
    }
    void addedge(int u, int v)
    {
        l[u].push_back(v);
        if (!isuni)
        {
            l[v].push_back(u);
        }
    }
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (auto idx : l[i])
            {
                cout << idx << " ";
            }
            cout << endl;
        }
    }
    void helper(int v,vector<bool> &vis,stack<int> &s)
    {
        vis[v]=true;
        for(int i:l[v])
        {
            if(!vis[i])
            {
                helper(i,vis,s);
            }
        }
        s.push(v);
    }
    void toposort()
    {
        vector<bool> vis(V,false);
        stack<int> s;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                helper(i,vis,s);
            }
        }
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }

    }
};
int main()
{
 Graph g(6,true);
 g.addedge(2,3);
 g.addedge(3,1);
 g.addedge(4,0);
 g.addedge(4,1);
 g.addedge(5,0);
 g.addedge(5,2);
 g.toposort();
}