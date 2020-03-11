// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72824774
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define inf 0x3f3f3f3f;
extern "C"{void *__dso_handle=0;}
using namespace std;
typedef long long ll;
map<ll,int> mp;
ll A[40];
void solve()
{
	ll n,k;
	mp.clear();
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>A[i];
	sort(A+1,A+1+n);
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		ll tmp=A[i];
		ll j=0;
		vector<ll> v;
		while(tmp)
		{	
			if(tmp%k!=1 && tmp%k!=0)
			{flag=0;break;}
			v.push_back(tmp%k);
			tmp/=k;
		}
		for(int i=v.size()-1;i>=0;i--)
		{
			if(v[i]==1)
				mp[i]++;
			if(mp[i]>1)
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
			break;
			
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
} 
