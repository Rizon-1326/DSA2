#include<bits/stdc++.h>
using namespace std;

int minimum_cost(int size, int bread[]){
    int dp[size+1];
    dp[0] = 0;
    for(int i=1; i<=size; i++){
        dp[i] = i;
        for(int j=0; j<i; j++){
            if(bread[i]-bread[j] > 0){
                dp[i] = min(dp[i], dp[j] + i - j);
            }
        }
    }
    return dp[size];
}
int main()
{
    // the cake size
    cout<<"Enter the bread size"<<endl;
    int size;
    cin>>size;
    int bread[size+1];
    bread[0] = 0;
    cout<<"Enter the number of cutpoints"<<endl;
    int k;
    cin>>k;
    cout<<"Enter the cutpoints of bread"<<endl;
    int cutpoint;
    for(int i = 1; i <= k; i++){
        cin>>cutpoint;// saving the index of the cutpoint
        bread[i] = cutpoint;
    }
    bread[k+1] = size;
    // taking count of how many cutpoints there are starting from length 0 to i
    for(int i = 1; i <= k+1; i++){
        bread[i] += bread[i-1];
    }
    int cost = minimum_cost(k+1, bread);
    cout<<"The minimum_cost"<<" "<<cost<<endl;
}
