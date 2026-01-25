#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool comp(pair<float,int> p1,pair<float,int> p2)
{
    return p1.first>p2.first;
}
int maxvalue(vector<float> wt,vector<int> value,int maxwt)
{
    vector<float> ratio;
    vector<pair<float,int>> p(wt.size(),make_pair(0,0));
    for(int i=0;i<wt.size();i++)
    {
      ratio.push_back(value[i]/wt[i]);
      p[i]=make_pair(ratio[i],i);
    }
    sort(p.begin(),p.end(),comp);
    int price=0;
    int curwt=0;
    int i=0;
    while(curwt<=maxwt)
    {
        if(wt[p[i].second]<=maxwt-curwt)
        {
            curwt+=wt[p[i].second];
            price+=value[p[i].second];
        }
        else{
            price+=(maxwt-curwt)*p[i].first;
            break;
        }
        i++;
    }
 cout<<"MAx price = "<<price<<endl;
 return price;
    

}
int main()
{
    vector<int> value={60,100,120};
    vector<float> wt={10,20,30};
    maxvalue(wt,value,50);}