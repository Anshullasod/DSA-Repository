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
    void bfs()
    {
        queue<int> q;
        vector<bool> vis(V, false);
        for (int i = 0; i < vis.size(); i++)
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
                while (!q.empty())
                {
                    int temp = q.front();
                    q.pop();
                    cout << temp << " ";
                    for (int i : l[temp])
                    {
                        if (!vis[i])
                        {
                            q.push(i);
                            vis[i] = true;
                        }
                    }
                }
                cout << endl;
            }
        }
    }
     void sortedge()
  {
    for(int i=0;i<V;i++)
    {
      l[i].sort();
    }
  }
    void helper(int v, vector<bool> &vis)
    {
        vis[v] = true;
        cout << v << " ";
        for (auto i : l[v])
        {
            if (!vis[i])
            {
                helper(i, vis);
            }
        }
    }
    void dfs()
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < vis.size(); i++)
        {
            if (!vis[i])
            {
                helper(i, vis);
                cout << endl;
            }
        }
    }
};
int main()
{
    Graph g(10);
    g.addedge(1, 6);
    g.addedge(4, 6);
    g.addedge(9, 4);
    g.addedge(4, 3);
    g.addedge(3, 8);
    g.addedge(3, 7);
    g.addedge(2, 5);
    g.addedge(2, 0);
    g.sortedge();
    g.print();
    g.bfs();
    g.dfs();
}