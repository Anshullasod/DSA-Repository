#include <bits/stdc++.h>
using namespace std;
int leastinterval(vector<char> &tasks,int k)
{
    int freqcount[26]={0};
    for(int i=0;i<tasks.size();i++)
    {
        int idx=tasks[i]-'A';
        freqcount[idx]++;
    }
    priority_queue<pair<int,char>> pq;
    for(int i=0;i<26;i++)
    {
        if(freqcount[i]>0)
        {   char ch='A'+i;
            pq.push({freqcount[i],ch});
        }
    }
    int countturn=0;
    vector<pair<int,char>> temp;
    int ans=0;
    while(!pq.empty()||temp.size()!=0)
    {
        if(!pq.empty())
        {
            auto curr=pq.top();
            pq.pop();
            cout<<curr.second<<"->";
            curr.first--;
            if(curr.first>0)
            {temp.push_back({curr.first,curr.second});}
        }
        else
        {
            cout<<"IDLE ->";
        }
        ans++;
        countturn++;
        if(countturn==k+1)
        {
            for(int i=0;i<temp.size();i++)
            {
                pq.push({temp[i].first,temp[i].second});
            }
            temp.clear();
            countturn=0;
        }
     }
     cout<<endl<<ans<<endl;
     return ans;

}
int main()
{
vector<char> tasks={'A','A','A','B','B','B'};
leastinterval(tasks,2);

}