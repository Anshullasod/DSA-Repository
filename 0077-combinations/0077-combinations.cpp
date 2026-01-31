class Solution {
public:
    void combi(int n, int k, vector<int>& ans, vector<vector<int>>& result,
               int st) {
        if (ans.size() == k) {
            result.push_back(ans);
            return;
        }
        for (int i = st; i <= n; i++) {
            ans.push_back(i);
            combi(n, k, ans, result, i + 1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        vector<vector<int>> result;
        combi(n,k,ans,result,1);
        return result;
    }
};