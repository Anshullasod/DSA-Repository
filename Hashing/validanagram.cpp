#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool checkanagram(string s,string s2)
{
  unordered_map<int,char> m;
  if(s.size()!=s2.size())
  {
    cout<<"NOT anagram"<<endl;
      return false;
  }
  for(int i=0;i<s.size();i++)
  {
    m[s[i]]++;
  }
  for(int i=0;i<s2.size();i++)
  {
    if(m[s2[i]]==0)
    {   cout<<"Not anagram"<<endl;
        return false;
    }
    m[s2[i]]--;
  }
  cout<<"Yes it's anagram"<<endl;
  return true;

}
int main()
{
  string s="RACE",s2="ACER";
  checkanagram(s,s2);

}
