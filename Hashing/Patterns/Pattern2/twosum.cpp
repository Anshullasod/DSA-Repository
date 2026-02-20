#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
pair<int,int> twosum(vector<int> &num,int target)
{ unordered_map<int,int> m;
  for(int i=0;i<num.size();i++)
  { 
     if(m.find(target-num[i])!=m.end())
     {cout<<i<<" , "<<m[target-num[i]];
      return make_pair(i,m[target-num[i]]);
     }
     m[num[i]]=i;

  }
  cout<<"Not present";
  return make_pair(-1,-1);
}
int main()
{
    vector<int> nums={1,5,7,1,3,2};
    int target=9;
    twosum(nums,9);
}