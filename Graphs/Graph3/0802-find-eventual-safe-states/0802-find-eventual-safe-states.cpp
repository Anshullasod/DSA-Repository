class Graph{
    public:
    int V;
    list<int> *l;
    vector<int> indeg;
    Graph(int V)
    {
        this->V=V;
        l=new list<int> [V];
        indeg.assign(V,0);
    }
    void addedge(int u,int v)
    {
        l[u].push_back(v);
        indeg[v]++;
    }
    vector<int> safenodes()
    {
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int temp=q.front();
            ans.push_back(temp);
            q.pop();
            for(int i:l[temp])
            {
                indeg[i]--;
                if(indeg[i]==0)
                {
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    Graph g(graph.size());
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            g.addedge(graph[i][j],i);
        }
    }      
    return g.safenodes();

    }
};