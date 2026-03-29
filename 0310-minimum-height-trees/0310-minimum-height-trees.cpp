class Graph{
    public:
    int V;
    list<int> *l;
    vector<int> indegree;
    Graph(int V)
    {
        this->V=V;
        l=new list<int> [V];
        indegree.assign(V,0);
    }
    void addedge(int u,int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
        indegree[u]++;
        indegree[v]++;
    }
    vector<int> MHT()
    {   if(V==1)
        {return {0};}
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }
        int total=V;
        while(total>2)
        {  int tsize=q.size();
           total-=tsize;
           for(int i=0;i<tsize;i++)
           {
            int temp=q.front();
            q.pop();
            for(int idx:l[temp])
            {
             indegree[idx]--;
             if(indegree[idx]==1)
             {
                q.push(idx);
             }
            }
           }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        Graph g(n);
        for(int i=0;i<edges.size();i++)
        {
            g.addedge(edges[i][0],edges[i][1]);
        }
        return g.MHT();

    }
};