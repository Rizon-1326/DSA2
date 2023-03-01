#include<bits/stdc++.h>
using namespace std;
#define s1 heater
#define s2 speak
int dp[100][100],m,n,dir[100][100];
string s1="heater",s2="speak";

int rec(int i,int j)
{
	 if(i<0||j<0)
     {
        return max(i+1,j+1);
     }
     int ret;
	int p1=rec(i,j-1)+1;
	int p2=rec(i-1,j)+1;
	int p3;
	if(s1[i]==s2[j])
		p3=rec(i-1,j-1);
	else
		p3=rec(i-1,j-1)+1;
	if(p1<=p2&&p1<=p3)
		dir[i][j]=1;
	else if(p2<=p1&&p2<=p3)
		dir[i][j]=2;
	else
		dir[i][j]=3;
		int k=min(p2,p3);
	ret=min(p1,k);
	return ret;
}
void path_prnt(int i,int j)
{
	if(i<0||j<0)
		return;
	if(dir[i][j]==1)
	{
		path_prnt(i,j-1);
		cout<<"delete"<<" "<<s1[i]<<endl;
	}
	else if(dir[i][j]==2)
	{
		path_prnt(i-1,j);
		cout<<"add"<<" "<<s2[j]<<endl;
	}
	else
	{
		path_prnt(i-1,j-1);
		if(s1[i]!=s2[j])
            cout<<"replace"<<" "<<s2[j]<<endl;
	}
}

int main()
{
      int m,n;
		m=s1.size();
		n=s2.size();
		/*for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
				dp[i][j]=-1;
		}*/
		cout<<"Minimum_path"<<" "<<rec(m-1,n-1)<<endl;
		path_prnt(m-1,n-1);
	return 0;
}


