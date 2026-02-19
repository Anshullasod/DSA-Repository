#include <bits/stdc++.h>
using namespace std;
int connectingropes(vector<int> &nums)
{
  priority_queue<int,vector<int>,greater<int>> pq;
  for(int i=0;i<nums.size();i++)
  {
    pq.push(nums[i]);
  }
  int sum=0;
  while(pq.size()>1)
  {
    int curr=pq.top();
    pq.pop();
    int cursum=pq.top()+curr;
    sum+=cursum;
    pq.pop();
    pq.push(cursum);
    
  }
  cout<<sum<<endl;
  return sum;
}
int main()
{
 vector<int> nums={4,2,7,6,9};
 connectingropes(nums);
}