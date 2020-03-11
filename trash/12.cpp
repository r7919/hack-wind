// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72815765
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
#define N 100

ll n,K;
ll a[N];

int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--) {
		memset(a,0,sizeof(a));
		scanf("%lld%lld",&n,&K);
		ll x;
		bool mar=0;
		for(ll i=1;i<=n;++i) {
			scanf("%lld",&x);
			if(!mar) {
				ll t=0;
				while(x) {
					a[t]+=x%K;
					if(a[t]>1) {mar=1;break;}
					x/=K;
					t++;
				}	
			}
		}
		if(!mar) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

