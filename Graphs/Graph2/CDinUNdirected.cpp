#include <iostream>
#include <list>
using namespace std;
#include <queue>
#include <vector>
class Graph
{
public:
    int V;
    list<int> *l;
    Graph(int val)
    {
        V = val;
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
    bool helper(int v, vector<bool> &vis, int par)
    {
        vis[v] = true;
        for (auto i : l[v])
        {
            if (!vis[i])
            {
                if (helper(i, vis, v))
                {
                    return true;
                }
            }
            else
            {
                if (i != par)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs()
    {
        vector<bool> vis(V, false);
        return helper(0, vis, -1);
    }
};
int main()
{
    Graph g(3);
    g.addedge(1, 0);
    g.addedge(1, 2);
    g.addedge(2, 0);

    cout << g.dfs();
}