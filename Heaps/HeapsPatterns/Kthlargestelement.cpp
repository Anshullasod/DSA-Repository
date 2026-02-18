#include<bits/stdc++.h>   //Leetcode-215
using namespace std;
int Kthlargest(vector<int> &nums,int k)
{
  priority_queue<int,vector<int>,greater<int>> pq;
  for(int i=0;i<nums.size();i++)
  {
    if(pq.size()<k)
    {
      pq.push(nums[i]);
    }
    else
    {
      if(nums[i]>pq.top())
      {
        pq.pop();
        pq.push(nums[i]);
      }
    }
  }
  cout<<pq.top()<<endl;
  return pq.top();
}
int main()
{
  vector<int> nums={3,2,1,5,6,4};
  Kthlargest(nums,2);
}
