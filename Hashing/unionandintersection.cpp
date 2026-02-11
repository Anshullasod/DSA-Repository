#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#include<vector>
void unionofset(vector<int> s1,vector<int> s2)
{
 unordered_set<int> s;
 for(int i=0;i<s1.size();i++)
 {
    s.insert(s1[i]);
 }
 for(int i=0;i<s2.size();i++)
 {
    s.insert(s2[i]);
 }
 for(int val:s)
 {
    cout<<val<<" ";
 }
 return;
}
void intersection(vector<int> s1,vector<int> s2)
{
    unordered_set<int> s;
    for(int i=0;i<s1.size();i++)
    {
        s.insert(s1[i]);
    }
    for(int i=0;i<s2.size();i++)
    {
        if(s.find(s2[i])!=s.end())
        {
          cout<<s2[i]<<" ";
          s.erase(s2[i]);
        }
    }
   return;
}
int main()
{
    vector<int> s1={7,3,9},s2={6,3,9,2,9,4};
    unionofset(s1,s2);
    cout<<endl;
    intersection(s1,s2);
}