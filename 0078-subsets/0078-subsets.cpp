class Solution {
public:
void subset(vector<int> &root,vector<int> &temp,vector<vector<int>> &ans,int idx)
{
  if(idx==root.size())
  {
    ans.push_back(temp);
    return;
  }
  
  temp.push_back(root[idx]);
  subset(root,temp,ans,idx+1);
  temp.pop_back();
  while(idx+1<root.size()&&root[idx]==root[idx+1])
  {
    idx++;
  }
  subset(root,temp,ans,idx+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        subset(nums,temp,ans,0);
        return ans;
    }
};