// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821324
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,h=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		priority_queue<int> q;
		for(int i=1;i<=n;i++)
		{
			h=max(h,a[i]);
			if(a[i]==0)continue;
			else q.push(a[i]);
		}
		int o=1;
		for(int i=1;i<=100;i++)
		{
			o=o*k;
			if(o*k>h)break;
		}
		//cout<<o<<endl;
		int r=0;
		while(!q.empty())
		{
			if(o==0)
			{
				r=1;
				break;
			}
			int x=q.top();
			if(o<=x)
			{
				x=x-o;
				q.pop();
				if(x!=0)q.push(x);
			}
			o=o/k;
		}
		if(r!=1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	} 
	return 0;
}
