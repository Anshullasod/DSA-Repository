#include<bits/stdc++.h>
using namespace std;
int counttuples(vector<int> &nums1,vector<int> &nums2,vector<int> &nums3,vector<int> &nums4)
{
    unordered_map<int,int> m1; //elements sum,freq
    for(int i:nums1)
    {
        for(int j:nums2)
        {
            m1[i+j]++;
        }
    }
    int count=0;
    for(int i:nums3)
    {
        for(int j:nums4)
        {
            int target=-(i+j);
            if(m1.count(target))
            {
                count+=m1[target];
            }
        }
    }
    cout<<count<<endl;
    return count;
}
int main()
{
 vector<int> nums1={1,2};
 vector<int> nums2={-2,-1};
 vector<int> nums3={-1,2};
 vector<int> nums4={0,2};
 counttuples(nums1,nums2,nums3,nums4);

}