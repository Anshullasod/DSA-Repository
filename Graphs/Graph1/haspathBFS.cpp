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
    bool haspath(int src,int dest)
    { 
        queue<int> q;
        q.push(src);
        vector<bool> vis(V,false);
        vis[src]=true;
        while(!q.empty())
        {
           int temp=q.front();
           q.pop();
           if(temp==dest)
           {
            return true;
           } 
            for(int i:l[temp])
            {
              if(!vis[i])
              {q.push(i);
              vis[i]=true;}
            }



        }
        return false;
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
    cout<<g.haspath(0,9);
}