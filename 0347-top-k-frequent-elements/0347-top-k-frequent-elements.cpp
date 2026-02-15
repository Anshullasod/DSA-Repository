class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
          unordered_map<int,int> m;
  for(int i=0;i<nums.size();i++)
  {
    m[nums[i]]++;
  }
  vector<int> ans;
  priority_queue<pair<int,int>> p;
  for(pair<int,int> i:m)
  {
    p.push(make_pair(i.second,i.first));
  }
  for(int i=0;i<k;i++)
  {
    ans.push_back(p.top().second);
    p.pop();
  }
  return ans;
    }
};