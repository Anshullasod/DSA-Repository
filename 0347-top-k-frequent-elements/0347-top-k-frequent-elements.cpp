class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
  for(int i=0;i<nums.size();i++)
  {
    m[nums[i]]++;
  }
  vector<vector<int>> num(nums.size()+1);
  for(auto p:m)
  {
    num[p.second].push_back(p.first);
  }
  vector<int> ans; 
  for(int i=nums.size();i>0&&ans.size()<k;i--)
  {
    for(int val:num[i])
    {
        ans.push_back(val);
        if(ans.size()==k)
        {
            break;
        }
    }
  }
  return ans;
    }
};