class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
         unordered_map<int,int> m1; //elements sum,freq
    for(int i:nums1)
    {
        for(int j:nums2)
        {
            m1[i+j]++;
        }
    }
    int count=0;
    for(int i:nums3)
    {
        for(int j:nums4)
        {
            int target=-(i+j);
            if(m1.count(target))
            {
                count+=m1[target];
            }
        }
    }
    return count;
    }
};