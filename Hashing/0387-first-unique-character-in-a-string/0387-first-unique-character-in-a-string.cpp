class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> m;
        for(int i=0;i<s.size();i++)
        {
            int idx=s[i]-'a';
            m[idx]++;
        }
        for(int i=0;i<s.size();i++)
        {
            int idx=s[i]-'a';
            if(m[idx]==1)
            {
                return i;
            }
        }
        return -1;
    }
};