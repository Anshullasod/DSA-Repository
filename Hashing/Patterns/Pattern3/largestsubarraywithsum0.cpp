#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int sum0(vector<int> &nums)
{
    unordered_map<int, int> m;
    int cursum = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cursum += nums[i];
        if (m.count(cursum))
        {
            ans = max(ans, i - m[cursum]);
        }
        else
        {
            m[cursum] = i;
        }
    }
    cout << ans << endl;
    return ans;
}
int main()
{
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10};
    sum0(nums);
}