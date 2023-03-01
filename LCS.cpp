#include<bits/stdc++.h>
using namespace std;
int c[100][100];
char b[100][100];
int m,n;
char s[]=" ";
void main_lcs(string x, string y)
{
    m=x.size(),n=y.size();
    for(int i=0; i<=m; i++)
    {
        c[i][0]=0;
    }
    for(int i=0; i<=n; i++)
    {
        c[0][i]=0;
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else if(c[i][j-1]>=c[i][j])
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    }
}int k=0;
char print_lcs(string x, int i, int j)
{
    if(i == 0 || j == 0)
    {
        return 0;
    }

    if(b[i][j] == 'd')
    {
        print_lcs(x, i-1, j-1);k++;
        cout<<x[i-1];

    }
    else if(b[i][j] == 'u')
    {
        print_lcs(x, i-1, j);
    }
    else
    {
        print_lcs(x, i, j-1);
    }
}

int main()
{
    string x,y;
    cin>>x>>y;
    int m,n;
    main_lcs(x,y);
    m=x.size(),n=y.size();
    cout<<"LCS length ="<<c[m][n]<<endl;
    cout<<"LCS is  : ";
    print_lcs(x, m, n);
}
/*
bacdb
bdcb
*/


