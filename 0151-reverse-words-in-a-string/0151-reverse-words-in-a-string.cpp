class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        string word;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (!word.empty()) {
                    temp.push_back(word);
                    word="";
                }
            }
        }
        if (!word.empty()) {
            temp.push_back(word);
        }
        string ans;
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans += temp[i];
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};