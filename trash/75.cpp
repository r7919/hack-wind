// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821056
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	ll a,b,c,d;
	scanf("%lld",&d);
	while(d--)
	{
		ll maxx=0;
		scanf("%lld%lld",&a,&b);
		ll z[a];
		for(int i=0;i<a;i++)
		{scanf("%lld",&z[i]);
		maxx=max(maxx,z[i]);}
		ll e=b;
		c=1;
		while(e<maxx)
		{e=e*b;c++;}
		for(int i=c;i>=0;i--)
		{
			sort(z,z+a,cmp);
			if(z[0]>=e)z[0]-=e;
			e/=b;
		}
		int flag=0;
		for(int i=0;i<a;i++)
		{
			if(z[i]!=0)
			{
				flag=1;break;
			}
		}
		if(flag)printf("NO\n");
		else printf("YES\n");
	}
}
