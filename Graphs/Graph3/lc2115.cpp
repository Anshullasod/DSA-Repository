#include<iostream>
#include<string>
#include<vector>
#include<queue> 
#include<unordered_map>
#include<algorithm>
using namespace std;
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
     for(int i=0;i<ans.size();i++)
     {
        cout<<ans[i]<<" ";
     }
     return ans;
    }
};
int main()
{
    vector<string> recipes={"bread","sandwich"};
    vector<vector<string>> ingredients={{"yeast","flour"},{"bread","meat"}};
    vector<string> supplies={"yeast","flour","meat"};
    Graph g;
    for(int i=0;i<recipes.size();i++)
    {
        for(int j=0;j<ingredients[i].size();j++)
        {
            g.addedge(ingredients[i][j],recipes[i]);
        }
    }
    g.find(supplies);
    vector<int> vec={1,4,2,3};
  
}
