#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int twosum(vector<int> &nums,int k)
{
    unordered_map<int,int> m; //num,idx
    for(int i=0;i<nums.size();i++)
    {
        m[nums[i]]=i;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(m.find(k-nums[i])!=m.end())
        {
          cout<<i<<" "<<m[k-nums[i]];
          return 0;
        }
        
    }
    cout<<"Not found";
    return 0;
}
int main()
{
    vector<int> nums={2,7,11,15};
    twosum(nums,1);
}