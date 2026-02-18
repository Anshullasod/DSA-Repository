class Solution {
public:
class Point{
  public:
  int hd;
  int vd;
  Point(int hd,int vd)
  {
    this->hd=hd;
    this->vd=vd;
  }
  long int dist()
  {
    return (hd*hd)+(vd*vd);
  }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long int,vector<int>>> pq;
  for(int i=0;i<points.size();i++)
  {
    Point temp(points[i][0],points[i][1]);
    long int distance=temp.dist();
    if(pq.size()<k)
    {
      pq.push({distance,{points[i][0],points[i][1]}});
    }
    else
    { if(distance<pq.top().first)
      {pq.pop();
      pq.push({distance,{points[i][0],points[i][1]}});
    }}
  }
  vector<vector<int>> ans;
  while(!pq.empty())
  {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i][0]<<","<<ans[i][1]<<endl;
  }
 return ans;
    }
};