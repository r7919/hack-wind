// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72813157
#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long 
using namespace std;

LL max(LL a,LL b)
{
	return a>b?a:b;
}

LL t,n,k,wei[110],mcur;


int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		memset(wei,0,sizeof(wei));
		mcur=-1;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)
		{
			long long tmp;
			scanf("%lld",&tmp);
			LL cur=0;
			while(tmp)
			{
				wei[cur++]+=tmp%k;
				tmp/=k;
			}
			mcur=max(mcur,cur);
		}
		mcur--;
		int flag=1;
		for(int i=0;i<=mcur;i++)
			if(wei[i]>1)
			{
				flag=0;
				break;
			}
		if(flag)
			printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}
