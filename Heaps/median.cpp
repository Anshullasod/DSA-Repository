#include<iostream> 
#include<queue>
using namespace std;
class median{
    public:
    priority_queue<int> maxpq; //Left
    priority_queue<int,vector<int>,greater<int>> minpq; //Right
    void insert(int val)
    {
     maxpq.push(val);
     minpq.push(maxpq.top());
     maxpq.pop();
     if(maxpq.size()<minpq.size())
     {
        maxpq.push(minpq.top());
        minpq.pop();
     }
    }
    void showmedian()
    {
        int maxsize=maxpq.size();
        int minsize=minpq.size();
        if((maxsize+minsize)%2!=0)
        {
            cout<<maxpq.top()<<" ";
            return;
        }
        double median=(minpq.top()+maxpq.top())/2.0;
        cout<<median<<endl;
        return;
    }
};
int main()
{
  median m;
  m.insert(3);
  m.insert(1);
  m.insert(2);
  m.insert(4);
  m.showmedian();
}