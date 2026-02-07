#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void heapify(int idx,vector<int> &arr,int n)
{
    int lidx=2*idx+1;
    int ridx=2*idx+2;
    int maxidx=idx;
    if(lidx<n&&arr[lidx]>arr[maxidx])
    {
        maxidx=lidx;
    }
    if(ridx<n&&arr[ridx]>arr[maxidx])
    {
        maxidx=ridx;
    }
    swap(arr[idx],arr[maxidx]);
    if(idx!=maxidx)
    {
        heapify(maxidx,arr,n);
    }
}
void heapsort(vector<int> &arr)
{ //Step 1: create a max heap of vector.
  int n=arr.size();
  for(int i=n/2-1;i>=0;i--)
  {
    heapify(i,arr,n);
  }
  //Step 2 taking element to correct position
  for(int i=n-1;i>=0;i--)
  {
    swap(arr[0],arr[i]);
    heapify(0,arr,i);
  }
}
int main()
{
    vector<int> num={1,4,2,5,3};
    heapsort(num);
    for(int i=0;i<num.size();i++)
    {
        cout<<num[i]<<" ";
    }
    
}