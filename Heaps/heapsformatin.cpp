#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Heap{
    vector<int> vec;
    void heapify(int idx)
    { if(idx>=vec.size())
      {
        return;
      }
      int leftidx=(2*idx)+1;
      int rightidx=(2*idx)+2;
      int maxidx=idx;
      if(leftidx<vec.size()&&vec[leftidx]>vec[maxidx])
      {
        maxidx=leftidx;
      }
      if(rightidx<vec.size()&&vec[rightidx]>vec[maxidx])
      {
        maxidx=rightidx;
      }
      swap(vec[maxidx],vec[idx]);
      if(maxidx!=idx)
      {
        heapify(maxidx);
      }

    }
    public:
    void push(int val)
    {   //insert the value
        vec.push_back(val);
        //fix the heap
        int x=vec.size()-1;
        int p=(x-1)/2;
        while(p>=0&&vec[x]>vec[p])
        {
            swap(vec[x],vec[p]);
            x=p;                           //log(n) TC
            p=(x-1)/2;
        }
    }
    void pop()
    {
      swap(vec[vec.size()-1],vec[0]);
      vec.pop_back();
      heapify(0);
      
    }
    int top()
    {
       return vec[0];    //highest priority element
    }
    bool empty()
    {
       return vec.size()==0;
    }

};
int main()
{
  Heap h;
  h.push(9);
  h.push(4);
  h.push(8);
  h.push(1);
  h.push(2);
  h.push(5);

  while(!h.empty())
  {
     cout<<h.top()<<" ";
     h.pop();
  }
}
