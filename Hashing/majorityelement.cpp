#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void majorityelement(vector<int> &nums)
{
    unordered_map<int,int> m;
    for(int i=0;i<nums.size();i++)
  {
  
     m[nums[i]]++;
    
 
  }
  for(pair<int,int> p:m)
  {
    if(p.second>nums.size()/3)
    {   
        cout<<p.first<<" ";
    }
  }
  return;}
int main()
{
    vector<int> nums={1,9,9,9,3};
    majorityelement(nums);
}