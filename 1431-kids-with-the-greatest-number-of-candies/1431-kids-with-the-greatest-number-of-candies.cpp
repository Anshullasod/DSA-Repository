class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int currmax=0;
        for(int i=0;i<candies.size();i++)
        {
          currmax=max(currmax,candies[i]);
        }
        vector<bool> result(candies.size(),false);
        for(int i=0;i<candies.size();i++)
        {   int total=candies[i]+extraCandies;
            if(total>=currmax)
            {
                result[i]=true;
            }
        }
        return result;
    }
};