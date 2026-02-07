#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Student{
public:
int marks;
string name;
Student(string name,int marks)
{
    this->name=name;
    this->marks=marks;
}
bool operator <(const Student &obj) const{
   return this->marks<obj.marks;
}
};
struct Comparepair{
  bool operator () (pair<string,int> &p1,pair<string,int> &p2)
  {
  return p1.second>p2.second;
  }
};

int main()
{   
   priority_queue<pair<string,int>,vector<pair<string,int>>,Comparepair> pq;
   pq.push(make_pair("Anshul",78));
   pq.push(make_pair("Sunny",80));
   pq.push(make_pair("Rohitash",68));
    while(!pq.empty())
 {
    cout<<pq.top().first<<":"<<pq.top().second<<endl;
    pq.pop();
 }

}