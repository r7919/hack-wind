// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821803
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int t,n,k,cnt;
long long a[110],x;
long long z[110];
int jz[110],g[110];
bool u[110];
int main()
{
	cin>>t;
	while(t--)
	{
		bool f=0;
		memset(u,0,sizeof(u));
		cin>>n>>k;
		x=1,cnt=-1;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			int j=0;
		    while(a[i]>0)
		    {
			    jz[j]=a[i]%k;
		    	a[i]/=k;
		    	if(jz[j]!=0&&jz[j]!=1)
		    	{
		    		f=1;
		    		break;
				}
				else if(jz[j]==1)
				{
					if(u[j]==1)
					{
						f=1;
						break;
					}
					u[j]=1;
				}
		    	j++;
			}
			if(f==1)
			break;
		}
		if(f==1)
		cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
	}
	return 0;
}
