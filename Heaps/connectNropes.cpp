#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minprice(vector<int> &num)
{
    priority_queue<int,vector<int>,greater<int>> ropes;
    for(int i=0;i<num.size();i++)
    {
        ropes.push(num[i]);
    }
    int sum=0;
    while(ropes.size()>1)
    {
        int r1=ropes.top();
        ropes.pop();
        int r2=ropes.top();
        ropes.pop();
        sum+=r1+r2;
        ropes.push(r1+r2);
    }
    cout<<sum<<endl;
    return sum;

}
int main()
{
    vector<int> num={4,3,2};
    minprice(num);

    
}