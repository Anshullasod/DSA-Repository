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
    void helper(int src,vector<bool> &vis,int dest,string ans)
    {
        if(src==dest)
        {
          cout<<ans<<dest<<endl;
          return;
        }
        vis[src]=true;
        
        for(int i:l[src])
        {
          if(!vis[i])
          { 
            helper(i,vis,dest,ans+to_string(src));
          }
        }
       
        vis[src]=false;
    }
    void findpath(int src,int dest)
    {   string ans;
        vector<bool> vis(V,false);
        helper(src,vis,dest,ans);
    }

    };    


int main()
{
    Graph g(6, true);
    g.addedge(5,0);
    g.addedge(5,2);
    g.addedge(4,0);
    g.addedge(4,1);
    g.addedge(0,3);
    g.addedge(2,3);
    g.addedge(3,1);
    g.findpath(5,1);

}