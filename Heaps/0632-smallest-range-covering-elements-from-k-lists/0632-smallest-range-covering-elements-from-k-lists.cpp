class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int max_val=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i][0],i,0});
            max_val=max(max_val,nums[i][0]);
        }
        vector<int> ans;
        int rangesize=max_val-pq.top()[0];
        ans={pq.top()[0],max_val};
        while(true)
        {
            auto curr=pq.top(); 
            pq.pop();
            if(rangesize>max_val-curr[0])
            {
                rangesize=max_val-curr[0];
                ans[0]=curr[0];
                ans[1]=max_val;
            }
            if(curr[2]+1<nums[curr[1]].size())
            {   
                pq.push({nums[curr[1]][curr[2]+1],curr[1],curr[2]+1});
                max_val=max(max_val,nums[curr[1]][curr[2]+1]);
            }
            else
            {
                break;
            }
            
            
        }
        return ans;
    }
};