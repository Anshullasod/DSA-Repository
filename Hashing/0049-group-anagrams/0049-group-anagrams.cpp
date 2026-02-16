class Solution {
public:
    string sorted(string s) {
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); i++) {
            string key = sorted(strs[i]);
            m[key].push_back(strs[i]);
        }
        for (pair<string, vector<string>> p : m) {
            ans.push_back(p.second);
        }
        return ans;
    }
};