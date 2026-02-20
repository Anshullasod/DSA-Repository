class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> m; //num,idx
    vector<int> ans;
    for(int i=0;i<nums.size();i++)
    {
        if(m.count(target-nums[i]))
        {
            ans={i,m[target-nums[i]]};
            return ans;
        }
        m[nums[i]]=i;
    }
    return {-1,-1}; 
    }
};