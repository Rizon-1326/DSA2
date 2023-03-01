#include<bits/stdc++.h>
using namespace std;

int rod_cutting(int c[], int n) {
    int r[n+1];
    r[0] = 0;
    for(int j=1; j<=n; j++) {
        int ans = -1;
        for(int i=1; i<=j; i++) {
            ans = max(ans, c[i] + r[j-i]);
        }
        r[j] = ans;
    }
    return r[n];
}

int main() {
    int n;
    cin >> n;
    int c[n+1];
    c[0] = 0;
    for(int i=1; i<=n; i++) {
        cin >> c[i];
    }
    int max_profit = rod_cutting(c, n);
    cout << max_profit << endl;
    return 0;
}
