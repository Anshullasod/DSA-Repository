class Solution {
public:
    void combisum(vector<int> candidates,vector<int> &ans,vector<vector<int>> &result,   int target,int cur,int idx)
    {
        if(cur==target)
        {
            result.push_back(ans);
            return;
        }
        if(cur>target||idx>=candidates.size())
        {
            return;
        }
        ans.push_back(candidates[idx]);
        combisum(candidates,ans,result,target,cur+candidates[idx],idx);
        ans.pop_back();
        combisum(candidates,ans,result,target,cur,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> result;
        combisum(candidates,ans,result,target,0,0);
        return result;
    }
};