#include<iostream>
using namespace std;
#include<stack>
class Queue{
stack<int> s1,s2;
public:
void push(int val)
{
    s1.push(val);
}
int top()
{
      while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    int ans=s2.top();
    cout<<ans<<endl;
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return ans;
}
void pop()
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
bool empty()
{
    if(s1.empty())
    {
        return true;
    }
    return false;
}};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    q.top();

}