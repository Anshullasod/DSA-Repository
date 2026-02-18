class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> p;       
       for(int i=0;i<points.size();i++)
       {
        int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
        p.push({dist,points[i]});
       }    
       int i=0;
       vector<vector<int>> ans;
       while(i!=k)
       {
        i++;
    ans.push_back(p.top().second);
  
        p.pop();
       }
       return ans;
       }
};