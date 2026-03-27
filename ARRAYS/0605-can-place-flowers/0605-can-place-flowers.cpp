class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
     int pos=0,prev=0;
     while(n>0&&pos<flowerbed.size())
     {
      bool nextempty=(pos==flowerbed.size()-1||flowerbed[pos+1]==0);
      if(flowerbed[pos]==0&&prev==0&&nextempty)
      {
        n--;
        flowerbed[pos]=1;
      }
      prev=flowerbed[pos];
      pos++;
     }
     if(n>0)
     {
        return false;
     }
     return true;

    }
};