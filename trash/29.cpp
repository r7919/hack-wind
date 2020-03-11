// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819416
#include<bits/stdc++.h>
using namespace std;
long long a[40];
long long ci[101];
int t,n,k;
int main()
{
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(ci,0,sizeof(ci));
		cin>>n>>k;
		int flag=0;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i];
			int j=0;
			while(a[i]>0)
			{
				ci[j]+=a[i]%k;
				a[i]/=k;
				j++;
			}
		}
		for(int i=0; i<=100; i++)
		{
			if(ci[i]>1)
				flag=1;
		}
		if(flag==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		else
			cout<<"YES"<<endl;
	}

	return 0;
}
