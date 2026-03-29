class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
       vector<int> two,one;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==1)
                {
                    one.push_back(i);
                }
                if(nums[i]==2)
                {
                    two.push_back(i);
                }
            }
        int mini=INT_MAX;
        if(one.size()==0||two.size()==0)
        {
            return -1;
        }
        for(int i=0;i<one.size();i++)
        {
            for(int j=0;j<two.size();j++)
            {
                int dif=abs(one[i]-two[j]);
                mini=min(mini,dif);
            }
        }
        return mini;
    }
 
};