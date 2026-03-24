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
    bool isuni;
    Graph(int val, bool is)
    {
        isuni = is;
        V = val;
        l = new list<int>[V];
    }
    void addedge(int u, int v)
    {
        l[u].push_back(v);
        if (isuni) // undirectional
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
    bool helper(int v, vector<bool> &vis, vector<bool> &recpath)
    {
        recpath[v] = true;
        vis[v] = true;
        for (auto i : l[v])
        {
            if (!vis[i])
            {
                if (helper(i, vis, recpath))
                {
                    return true;
                }
            }
            else
            {
                if (recpath[i])
                {
                    return true;
                }
            }
        }
        recpath[v]=false;
        return false;
    }
    bool dfs()
    {
        vector<bool> recpath(V, false);
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (helper(i, vis, recpath))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Graph g(4,false);
    g.addedge(1, 0);
    g.addedge(0, 2);
    g.addedge(2,3);
  //  g.addedge(0,3);

    cout << g.dfs();
}