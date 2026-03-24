#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#include <list>
class Graph
{
public:
    int V;
    list<int> *l;
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addedge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
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
    void DFShelper(int u, vector<bool> &vis)
    {
        vis[u] = true;
        cout << u << " ";
        for (int i : l[u])
        {
            if (!vis[i])
            {
                DFShelper(i, vis);
            }
        }
    }
    void DFS()
    {
         vector<bool> vis(V,false);
         DFShelper(0,vis);
    }
};
int main()
{
    Graph g(7);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 3);
    g.addedge(2, 4);
    g.addedge(3, 4);
    g.addedge(3, 5);
    g.addedge(4, 5);
    g.addedge(5, 6);
    g.DFS();
}