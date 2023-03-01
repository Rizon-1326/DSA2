#include<bits/stdc++.h>
using namespace std;
int r[5+1];

void init_r() {
  int i;
  r[0] = 0;
  for(i=1; i<=5; i++) {
    r[i] = -1;
  }
}

int rod_cutting(int c[], int n) {
  if (r[n] >= 0) {
    return r[n];
  }

  int ans = -1;
  int i;

  for(i=1; i<=n; i++) {
   // maximum_revenue = MAX(maximum_revenue, c[i] + top_down_rod_cutting(c, n-i));
    ans=max(ans,c[i] + rod_cutting(c, n-i));
  }
  r[n] = ans;
  return r[n];
}

int main() {
  init_r();
    int n;
    cin>>n;
    int c[n];
  c[0]=0;
  for(int i=1;i<=n;i++)
    cin>>c[i];
  int max_profit=rod_cutting(c,n);
  cout<<max_profit<<endl;
  return 0;
}
// 10 24 30 40 45
