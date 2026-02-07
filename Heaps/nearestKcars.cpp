#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
class Car{
    public:
    int hd,vd;
    string name;
    Car(string name,int x,int y)
    {this->name=name;
     hd=x;
     vd=y;   
    }
    double findhypo(int x,int y)
    {
       int z=(x*x)+(y*y);
       double h=sqrt(z);
       return h;
    }

};
struct comparedistance{
    bool operator () (pair<string,double> &p1,pair<string,double> &p2) {
       return p1.second>p2.second;
    } 
};
void findcars(vector<Car> cars,int k)
{
    priority_queue<pair<string,double>,vector<pair<string,double>>,comparedistance> pq;
    for(int i=0;i<cars.size();i++)
    {
        double dist=cars[i].findhypo(cars[i].hd,cars[i].vd);
        pq.push(make_pair(cars[i].name,dist));
    }
    while(!pq.empty()&&k!=0)
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
        k--;
    }
}
int main()
{
  Car c0("C0",3,3);
  Car c1("C1",5,-1);
  Car c2("C2",-2,4);
  vector<Car> cars;
  cars.push_back(c0);
  cars.push_back(c1);
  cars.push_back(c2);
  findcars(cars,2);
}