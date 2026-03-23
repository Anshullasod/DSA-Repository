class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
    for(int i=y;i<y+k;i++)
    {
        int f=x,l=x+k-1;
        while(f<l)
        {
            swap(grid[f][i],grid[l][i]);
            f++;
            l--;
        }
    }
    return grid;
    }
    
};