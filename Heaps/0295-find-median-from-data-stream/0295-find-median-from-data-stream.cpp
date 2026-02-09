class MedianFinder {
public:
priority_queue<int> maxpq; //Left
priority_queue<int,vector<int>,greater<int>> minpq; //Right
    MedianFinder() {
         
    }
    
    void addNum(int num) {
     maxpq.push(num);
     minpq.push(maxpq.top());
     maxpq.pop();
     if(maxpq.size()<minpq.size())
     {
        maxpq.push(minpq.top());
        minpq.pop();
     }
    }
    
    double findMedian() {
        int maxsize=maxpq.size();
        int minsize=minpq.size();
        if((maxsize+minsize)%2!=0)
        {
         return maxpq.top();
        }
        double median=(minpq.top()+maxpq.top())/2.0;
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */