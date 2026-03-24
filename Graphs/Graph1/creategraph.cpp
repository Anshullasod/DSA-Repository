#include<iostream>
#include<list>
using namespace std;
#include<vector>
class Graph{
    int v; //Total no. of vetrices
    list<int> *l;
    public:
    Graph(int v)
    {
     this->v=v;
     l=new list<int> [v];
    }
    void addedge(int u,int v)
    {
      l[u].push_back(v);
      l[v].push_back(u);
    }
     void print()
     {
        for(int i=0;i<v;i++)
        {
            list<int> neighbours=l[i];
            cout<<"Vertex = "<<i<<" -> ";
            for(int v:neighbours)
            {
              cout<<v<<" ";
            }
            cout<<endl;
        }
     }
};
int main()
{
Graph graph(5);
graph.addedge(0,1);
graph.addedge(1,2);
graph.addedge(3,1);
graph.addedge(2,3);
graph.addedge(2,4);
graph.print();
return 0;

}
