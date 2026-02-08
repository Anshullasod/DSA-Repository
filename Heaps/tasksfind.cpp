#include<iostream>
#include<queue>
using namespace std;
int scheduletask(vector<char> &tasks,int n)
{
    int counttask[26]={0};
    for(int i=0;i<tasks.size();i++)
    {
        counttask[tasks[i]-'A']++;
    }
    priority_queue<pair<int,char>> pq;
    for(int i=0;i<26;i++)
    {
        if(counttask[i]!=0)
        {   char ch='A'+i;
            pq.push(make_pair(counttask[i],ch));
        }
    } 
    vector<pair<int,char>> waitlist;
    int ans=0;
    int countturns=0;
    while(!pq.empty()||!waitlist.empty())
    {   if(pq.empty())
        {
            cout<<" (IDLE) ";
        ans++;
        countturns++;
        } 
        else
        {cout<<pq.top().second<<" ";
        pair<int,char> temp=pq.top();
        pq.pop();
        temp.first--;
        if(temp.first>0)
        {
            waitlist.push_back(temp);
        }
        ans++;
        countturns++;}
        if(countturns==n+1)
        {
          for(int i=0;i<waitlist.size();i++)
          {
            pq.push(waitlist[i]);
          }
          waitlist.clear();
          countturns=0;
        }
    }

    cout<<endl<<ans<<" ";
    return ans;
}
int main()
{
    vector<char> tasks={'A','B','B','A','B','A'};
    scheduletask(tasks,2);
    }