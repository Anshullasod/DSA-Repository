#include<bits/stdc++.h>
using namespace std;
class MedianFinder{
  public:
  priority_queue<int> pq1; //Max heap for first half;
  priority_queue<int,vector<int>,greater<int>> pq2;//<in heap for second half
  void addNum(int num)
  {
    pq1.push(num);
    pq2.push(pq1.top());
    pq1.pop();
    if(pq1.size()<pq2.size())
    {
        pq1.push(pq2.top());
        pq2.pop();
    }
    return;
  }
  double findmedian()
  { 
    if(pq1.size()==pq2.size())
    {double median=(pq1.top()+pq2.top())/2.0;
    cout<<median<<endl;
    return median;}
    else{
      double num=pq1.top();
      cout<<num<<endl;
    }
  }
};
int main()
{
  MedianFinder m;
  m.addNum(2);
  m.addNum(3);
  m.addNum(4);
  m.findmedian();
}