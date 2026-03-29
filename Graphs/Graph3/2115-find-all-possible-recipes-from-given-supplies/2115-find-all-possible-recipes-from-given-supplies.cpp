class Graph{
    public:
    unordered_map<string,vector<string>> adj;
    unordered_map<string,int> indegree;
    void addedge(string ingred,string receipe)
    {
      adj[ingred].push_back(receipe);
      indegree[receipe]++;
    }    
    vector<string> find(vector<string> supplies)
    {
     queue<string> q;
     for(int i=0;i<supplies.size();i++)
     {
        q.push(supplies[i]);
     }
     vector<string> ans;
     while(!q.empty())
     {
       string temp=q.front();
       q.pop();
       for(auto i:adj[temp])
       {
        indegree[i]--;
        if(indegree[i]==0)
        {
            ans.push_back(i);
            q.push(i);
        }
       }
     }
     return ans;
    }
};
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    Graph g;
    for(int i=0;i<recipes.size();i++)
    {
        for(int j=0;j<ingredients[i].size();j++)
        {
            g.addedge(ingredients[i][j],recipes[i]);
        }
    }
    return g.find(supplies);
    }
};