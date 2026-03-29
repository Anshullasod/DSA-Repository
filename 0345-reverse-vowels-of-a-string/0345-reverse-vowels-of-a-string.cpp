class Solution {
public:
    string reverseVowels(string s) {
        vector<int> p;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                p.push_back(i);
            }
        }
            int st=0,end=p.size()-1;
            while(st<end)
            {
                swap(s[p[st]],s[p[end]]);
                st++;
                end--;
            }
            

        
        return s;
    }
};