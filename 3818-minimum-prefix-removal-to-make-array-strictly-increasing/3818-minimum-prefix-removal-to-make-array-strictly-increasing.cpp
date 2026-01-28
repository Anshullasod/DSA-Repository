class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size()-1;i++)
            {
                if(nums[i]>=nums[i+1])
                {
                    k=i+1;
                }
            }
        return k;
    }
};