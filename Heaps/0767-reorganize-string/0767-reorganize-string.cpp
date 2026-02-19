class Solution {
public:
    string reorganizeString(string s) {
         int freqcount[26]={0};
 for(int i=0;i<s.size();i++)
 {
    int idx=s[i]-'a';
    freqcount[idx]++;
 }
 priority_queue<pair<int,char>> pq;
 for(int i=0;i<26;i++)
 {
    if(freqcount[i]!=0)
    {
        char ch='a'+i;
        pq.push({freqcount[i],ch});
    }
 }
 vector<pair<int,char>> temp;
 string ans;
 while(!pq.empty())
 {
    auto curr=pq.top();
    pq.pop();
    ans+=curr.second;
    curr.first--;
    if(!temp.empty())
    {
        pq.push(temp[0]);
        temp.clear();
    }
    if(curr.first>0)
    {temp.push_back({curr.first,curr.second});}    

 }
 if(!temp.empty())
 { cout<<"Not possible"<<endl;
   return "";
 }
 cout<<ans<<endl;
 return ans;
    }
};