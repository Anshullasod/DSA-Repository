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
    bool haspathhelper(int src,int dest,vector<bool> &vis)
    {
        if(src==dest)
        {
            return true;
        }
        vis[src]=true;
        for(int i:l[src])
        {
            if(!vis[i])
            {
                if(haspathhelper(i,dest,vis))
                {return true;}
            }
        }
        
        return false;
    }
      void haspath(int src,int dest)
    {
         vector<bool> vis(V,false);
         cout<<haspathhelper(src,dest,vis)<<endl;
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
    g.haspath(0,9);
}