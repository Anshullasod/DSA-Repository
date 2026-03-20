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
    void BFS()    //TC O(V+E)
    {
        queue<int> q;
        vector<bool> vis(V, false);
        q.push(0);
        vis[0] = true;
        while (q.size() > 0)
        {
            int temp = q.front();
            q.pop();
            cout << temp << " ";
            for (auto i : l[temp])
            {
                if (!vis[i])
                {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        cout<<endl;
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

    g.BFS();
}