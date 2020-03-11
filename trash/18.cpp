// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820818
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,k,a[10000],ans[100000];
		cin>>n>>k;
		for(int i=0;i<n;i++) 
		{
			cin>>a[i];
		}
		bool flag=0;
		for(int i=0;i<n;i++)
		{
			if(a[i])flag=1;
		}
		if(!flag) 
		{
			cout<<"YES"<<endl;
			continue;
		}
		
		memset(ans,0,sizeof ans);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<1000;j++)
			{
				ans[j]+=a[i]%k;
				a[i]/=k;
			}
		}
		
		for(int i=0;i<1000;i++)
		{
			if(ans[i]>1)
			flag=0;
		}
		
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
 }

