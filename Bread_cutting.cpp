#include<bits/stdc++.h>
using namespace std;

int minimum_cost(int i, int j, int bread[]){
    int mn = j-i, x = 0;
    for(int k = i+1; k < j; k++){
        // cake[k] > cake[k-1] indicates that the cake piece has a cutpoint on k
        if(bread[k]>bread[k-1]){
            mn = min(mn,minimum_cost(i, k, bread)+minimum_cost(k, j, bread));
            // taking count of the cuts made in the cake
            x++;
        }
    }
    // x == 0 means no cutpoint
    if(x==0) return 0;
    // x == 1 means 0ne cutpoint
    else if(x == 1) return (j-i);
    return (j+mn);
}
int main()
{
    // the cake size
    cout<<"Enter the bread size"<<endl;
    int size;cin>>size;
    int cake[size+1];
    for(int i = 0; i <size+1; i++){
        cake[i] = 0;
    }
    cout<<"Enter the number of cutpoints"<<endl;
    int k;cin>>k;
    cout<<"Enter the cutpoints of bread"<<endl;
    int cutpoint;
    for(int i = 0; i <k; i++){
       cin>>cutpoint;// saving the index of the cutpoint
        cake[cutpoint] = 1;
    }// taking count of how many cutpoints there are starting from length 0 to i
    for(int i = 1; i <= size; i++){
        cake[i] += cake[i-1];
    }
    int cost =minimum_cost(0,size, bread);
    cout<<"The minimum_cost"<<" "<<cost<<endl;
}

