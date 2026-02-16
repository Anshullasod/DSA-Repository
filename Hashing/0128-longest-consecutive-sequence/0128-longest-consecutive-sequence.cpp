class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
for(int i=0;i<nums.size();i++)
{
  s.insert(nums[i]);
}
int ans=0;
for(int i:s)
{
  if(s.find(i-1)==s.end())
  {
    int currnum=i;
    int currans=1;
    while(s.find(currnum+1)!=s.end())
    {
      currnum++;
      currans++;
    }
    ans=max(currans,ans);
  }
}
return ans;
    }
};