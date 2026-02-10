#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int countdistinct(vector<int> nums)
{
    unordered_map<int,int> m;
    for(int i=0;i<nums.size();i++)
    {
       m[nums[i]]=1;
    }
    int count=0;
    for(pair<int,int> p:m)
    {
        cout<<p.first<<" ";
        count++;
    }
   cout<<endl<<"count = "<<count<<endl;
   return count;
}
int main()
{
    vector<int> nums={4,3,2,5,6,7,3,4,2,1};
     countdistinct(nums);  
} 