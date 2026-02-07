#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Row{
    public:
    int count;
    int rowidx;
    Row(int count,int rowidx)
    {
        this->count=count;
        this->rowidx=rowidx;
    }
  
    bool operator <(const Row &obj) const{
        if(this->count!=obj.count)
        {
            return this->count>obj.count;
        }
        return this->rowidx>obj.rowidx;
    }
};
void weakestKsoldiers(vector<vector<int>> &base,int k)
{
    vector<Row> rows;
    for(int i=0;i<base.size();i++)
    {
        int count=0;
        for(int j=0;j<base.size();j++)
        {
            if(base[i][j]==1)
            {
                count++;
            }
        }
        Row row(count,i);
        rows.push_back(row);
    }
    priority_queue<Row> pq(rows.begin(),rows.end());
    while(k!=0)
    {
        cout<<pq.top().rowidx<<"  ";
        pq.pop();
        k--;
    }
    return ;
}
int main()
{
    vector<vector<int>> base={{1,0,0,0},
                              {1,1,1,1},
                              {1,0,0,0},
                              {1,0,0,0}};
   weakestKsoldiers(base,2);
}