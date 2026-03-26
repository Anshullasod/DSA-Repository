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
    bool iscycle(int v,vector<bool> &vis,int par)
    {
      vis[v]=true;
      for(auto i:l[v])
      {
        if(!vis[i])
        {
            if(iscycle(i,vis,v))
            {return true;}
        }
        else
        {
            if(i!=par)
            {
                return true;
            }
        }
      }
      return false;
    }
    bool detect()
    {   vector<bool> vis(V,false);
        return iscycle(0,vis,-1);
    }
    bool helper(int v,int p,vector<int> &pos,int d)
    {   pos[v]=d;
        for(auto i:l[v])
        {
            if(pos[i]==-1)
            {
                if(!helper(i,v,pos,d+1))
                {return false;}
            }
            else{
                if(p!=i)
                {   
                    int len=abs(pos[v]-pos[i])+1;
                    if(len%2!=0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;

    }
    int count()
    {
        vector<int> pos(V,-1);
        return helper(0,-1,pos,0);
    }
    bool ispartite()
    {
        vector<int> pos(V,-1);
        for(int i=0;i<V;i++)
        {
            if(pos[i]==-1)
            {
                if(!helper(i,-1,pos,0))
                {
                 return false;
                }
            }
        }
        return true;
    }
};    

int main()
{
    Graph g(4, false);
    g.addedge(0, 1);
    g.addedge(1, 2);
    g.addedge(2, 3);
    g.addedge(3, 0);
  cout<<g.ispartite();
    
}