class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, char> m;
        if (s.size() != t.size()) {

            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (m[t[i]] == 0) {
                return false;
            }
            m[t[i]]--;
        }
        if (m.size() != 0) {
            cout << "Not anagram" << endl;
            return false;
        }
        return true;
    }
};