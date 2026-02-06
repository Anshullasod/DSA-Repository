#include<iostream>
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
    //Operator overloading for pairs
    bool operator <(const Student &obj) const{
        return this->marks< obj.marks;           //Comparators
    }
};
int main()
{
    priority_queue<Student> pq;
    pq.push(Student("ANSHUL",92));
    pq.push(Student("KARTIK",82));
    pq.push(Student("CHANDRAVARDHAN",99));
    while(!pq.empty())
    {
        cout<<pq.top().name<<" - "<<pq.top().marks<<endl;
        pq.pop();
    }
}
