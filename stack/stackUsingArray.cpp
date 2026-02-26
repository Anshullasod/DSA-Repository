#include<iostream>
#include<vector>
using namespace std;
class Stack{
vector<int> arr;
public:
void push(int val)
{
    arr.push_back(val);
    cout<<"Pushed"<<endl;
    return;
}
void pop()
{   if(!isempty())
    {return;}
    arr.pop_back();
    cout<<"Popped"<<endl;
    return;
}
int top()
{   if(!isempty())
    {return;}
    cout<<arr[arr.size()-1]<<endl;
    return arr[arr.size()-1];
}
void print()
{
    for(int i=arr.size()-1;i>=0;i--)
    {
        cout<<arr[i]<<" ";    }
    cout<<endl;
    return;
}
bool isempty()
{
    if(arr.size()==0)
    {
        return true;
    }
    return false;
}
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.top();
    s.print();

}