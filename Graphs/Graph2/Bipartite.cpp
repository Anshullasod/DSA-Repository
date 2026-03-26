#include <iostream>
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
    bool bipartite()
    {
        vector<int> color(V, -1);
        queue<int> q;
        q.push(0);
        color[0] = 0;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (int i : l[temp])
            {
                if (color[i]==-1)
                {
                    q.push(i);
                    color[i] = !color[temp];
                }
                else
                {
                    if (color[i] == color[temp])
                    {
                        cout << "Not bipartite" << endl;
                        return false;
                    }
                }
            }
        }
        cout << " yes it is partite" << endl;
        return true;
    }
};        //for disconnected make a helper fn and take loop in that fn 
int main()
{
    Graph g(4, false);
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 0);
   // g.addedge(1, 3);
    g.bipartite();
}