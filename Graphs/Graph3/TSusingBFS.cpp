#include <iostream>
#include <stack>
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
            for (int idx : l[i])
            {
                cout << idx << " ";
            }
            cout << endl;
        }
    }
    void indegree(vector<int> &indeg)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v : l[u])
            {
                indeg[v]++;
            }
        } 
    }
    void toposort2() // Kahns algorithm
    {
        vector<int> indeg(V, 0);
        queue<int> q;
        indegree(indeg);
        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int curr = q.front();
            cout << curr << " ";
            q.pop();
            for (int v : l[curr])
            {
                indeg[v]--;
                if (indeg[v] == 0)  //No pending dependencies
                {
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};
int main()
{
    Graph g(6, true);
    g.addedge(2, 3);
    g.addedge(3, 1);
    g.addedge(4, 0);
    g.addedge(4, 1);
    g.addedge(5, 0);
    g.addedge(5, 2);
    g.toposort2();
}