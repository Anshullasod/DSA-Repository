class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum=nums[nums.size()-1];
        double count=1;
        int ans=0;
        for(int i=nums.size()-2;i>=0;i--)
            {   double avg=sum/count;
                if(nums[i]>avg)
                {
                    ans++;
                }
                sum+=nums[i];
                count++;
            }
        return ans;
    }
};