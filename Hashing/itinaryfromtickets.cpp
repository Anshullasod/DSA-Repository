#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;
void paths(unordered_map<string,string> tickets)
{
    unordered_set<string> to;
    for(pair<string,string> s:tickets)
    {
        to.insert(s.second);
    }
    string start;
    for(pair<string,string> p:tickets)
    {
        if(to.find(p.first)==to.end())
        {
          start=p.first;
        }
    }
    while(tickets.find(start)!=tickets.end())
    {
        cout<<start<<" -> "<<tickets[start]<<endl;
        start=tickets[start];
    }
    return;

}
int main()
{
    unordered_map<string,string> tickets;
    tickets["Kota"]="Jaipur";
    tickets["Indore"]="Udaipur";
    tickets["Neemuch"]="Kota";
    tickets["Udaipur"]="Neemuch";
    paths(tickets);
}