#include <iostream>
using namespace std;
#include <vector>
void print(vector<int> num)
{
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << ",";
    }
    cout << endl;
}
void merge(vector<int> &num, int s, int m, int e)
{
    vector<int> temp;
    int i = s, j = m + 1;
    while (i <= m && j <= e)
    {
        if (num[i] >= num[j])
        {
            temp.push_back(num[j]);
            j++;
        }
        if (num[i] < num[j])
        {
            temp.push_back(num[i]);
            i++;
        }
    }
    while (i <= m)
    {
        temp.push_back(num[i]);
        i++;
    }
    while (j <= e)
    {
        temp.push_back(num[j]);
        j++;
    }
    for (int i = s, x = 0; i <= e; i++)
    {
        num[i] = temp[x];
        x++;
    }
}
void mergesort(vector<int> &num, int s, int e)
{
    int m = s + (e - s) / 2;
    if (s >= e)
    {
      return;
    }
    mergesort(num, s, m);
    mergesort(num, m + 1, e);
    merge(num, s, m, e);
}
int main()
{
    vector<int> num = {3, 1, 2, 5, 4};
    print(num);
    mergesort(num,0,4);
    print(num);
}