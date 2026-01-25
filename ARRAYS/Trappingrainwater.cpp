#include<iostream>
using namespace std;

int main()
{
    int arr[]={7,6,5,4,3,2,1};
    int lmax[100000], rmax[100000], tmin[10000];
    int totalwater[10000];
    
    lmax[0] = rmax[6] = 0;
    
    for(int i=1; i<7; i++)
    { 
        lmax[i] = max(arr[i-1], lmax[i-1]); 
    }
    
    for(int i=5; i>=0; i--)
    {
        rmax[i] = max(arr[i+1], rmax[i+1]);
    }
    
    for(int i=0; i<7; i++)
    {
        tmin[i] = min(lmax[i], rmax[i]);
        cout << tmin[i] << " ";
    }
    
    cout << endl;
    
    int eachwater[10000];
    int totalwater1 = 0;
    
    for(int i=0; i<7; i++)
    {
        eachwater[i] = tmin[i] - arr[i];
        if(eachwater[i] < 0)
        {
            eachwater[i] = 0;
        }
        totalwater1 = totalwater1 + eachwater[i];
        cout << eachwater[i] << " ";
    }
    
    cout << endl << totalwater1;
    
    return 0;
}
