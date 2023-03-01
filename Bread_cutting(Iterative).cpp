#include<bits/stdc++.h>
using namespace std;

int minimum_cost(int size, int bread[]) {
    int dp[size+1][size+1];
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            dp[i][j] = 0;
        }
    }
    for (int len = 2; len <= size; len++) {
        for (int i = 0; i <= size - len; i++) {
            int j = i + len - 1;
            dp[i][j] = j - i;
            for (int k = i + 1; k <= j; k++) {
                if (bread[k] > bread[k-1]) {
                    dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j]);
                }
            }
            if (dp[i][j] == j-i) {
                int cuts = 0;
                for (int k = i + 1; k <= j; k++) {
                    if (bread[k] > bread[k-1]) {
                        cuts++;
                    }
                }
                if (cuts == 1) {
                    dp[i][j]++;
                }
            }
        }
    }
    return dp[0][size];
}

int main() {
    cout<<"Enter the bread size"<<endl;
    int size;cin>>size;
    int bread[size+1];
    for(int i = 0; i <size+1; i++) {
        bread[i] = 0;
    }
    cout<<"Enter the number of cutpoints"<<endl;
    int k;cin>>k;
    cout<<"Enter the cutpoints of bread"<<endl;
    int cutpoint;
    for(int i = 0; i <k; i++) {
       cin>>cutpoint;
        bread[cutpoint] = 1;
    }
    for(int i = 1; i <= size; i++) {
        bread[i] += bread[i-1];
    }
    int cost = minimum_cost(size, bread);
    cout<<"The minimum_cost"<<" "<<cost<<endl;
}

