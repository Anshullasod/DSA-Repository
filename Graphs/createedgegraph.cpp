#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
    public:
    int v;
    list<pair<int,int>> *l;
    Graph(int v)
    {
        this->v=v;
        l=new list<pair<int,int>> [v];
    }
    void addedge(int u,int v,int val)
    {
        l[u].push_back(make_pair(v,val));
        l[v].push_back(make_pair(u,val));
    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            list<pair<int,int>> temp=l[i];
            cout<<"Vertex = "<<i<<" -> ";
            for(auto idx:temp)
            {
              cout<<" ["<<idx.first<<","<<idx.second<<"] ";  
            }
            cout<<endl;
        }
    }
};
int main()
{
Graph graph(5);
graph.addedge(0,1,3);
graph.addedge(1,2,4);
graph.addedge(3,1,5);
graph.addedge(2,3,1);
graph.addedge(2,4,9);
graph.print();
return 0;
}