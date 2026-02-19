class MedianFinder {
public:
  priority_queue<int> pq1; //Max heap for first half;
  priority_queue<int,vector<int>,greater<int>> pq2;//<in heap for second half
    MedianFinder() {
        
    }
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
  double findMedian()
  { 
    if(pq1.size()==pq2.size())
    {double median=(pq1.top()+pq2.top())/2.0;
    return median;}
    else{
      double num=pq1.top();
    return num;
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */