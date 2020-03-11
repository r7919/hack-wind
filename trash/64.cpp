// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819216
#include<bits/stdc++.h>
using namespace std;
long long t,n,k,a,b[211],f;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(int i=0;i<111;++i)
			b[i]=0;
		f=0;
		while(n--)
		{
			scanf("%lld",&a);
			for(int i=0;a;++i,a/=k)
			{
				if(a%k==1)
				{
					if(b[i])
						f=1;
					else
						b[i]=1;
				}
				else if(a%k!=0)
					f=1;
			}
		}
		if(f)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
