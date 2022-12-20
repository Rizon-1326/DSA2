#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int start[n],a[n],end[n];
    for(int i=0; i<n; i++)
        cin>>start[i];
    for(int i=0; i<n; i++)
        cin>>end[i];
    //  sort(end,end+n);
    //  for(int i=0;i<n;i++)cout<<end[i];
    int k=0;
    for(int i=k; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            if(start[j]<end[i])
                a[i]=1;
            else
                k=i;
        }
    }
    int j=0;
    for(int i=1;i<n;i++)
        {
            if (start[i] >= end[j]) {
			//printf("%d ", i);
			a[i]=i+1;
			j = i;
		}
		else a[i]=0;
        }
    for(int i=0; i<n; i++)
    {
        if(a[i]>0)
            cout<<a[i]<<" "<<endl;
    }
}
