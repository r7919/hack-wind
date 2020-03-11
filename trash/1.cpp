// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72817873
// Problem : C. Adding Powers
// Contest : Educational Codeforces Round 83 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1312/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define int         long long
#define ull 		unsigned long long
#define ll 			long long
#define MM			1000000007
#define N			100005
#define pb 			push_back
#define p_q 		priority_queue
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define ios	    	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mp 			make_pair
#define lb 			lower_bound
#define ub			upper_bound
#define F           first
#define S           second
#define rep(i, begin, end) for(int i=begin;i<end;i++)
#define repr(i,begin,end) for(int i=end-1;i>=begin;i--)
#define ini(a,n,b)	for(ll int i=0;i<n;i++) a[i]=0;
#define cset(a)		__builtin_popcountll(a)
#define hell 		(ull)1e16
#define re 			resize



signed main(void)
{ios
	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
	{
		int n,k;
		cin>>n>>k;
		vi v;
		v.pb(1);
		int y=k;
		while(1)
		{
			if(y>hell) break;
			v.pb(y);
			y=y*k;
		}
		vector<bool> brr(100,0);
		bool ok=1;
		rep(i,0,n)
		{
			int x;
			cin>>x;
			if(x!=0)
			{
				while(x>0)
				{
					int ind=lower_bound(all(v),x)-v.begin();
					//cout<<ind<<' ';
					if(v[ind]>x) ind--;
					if(brr[ind]==1)
					{
						ok=0;
						//ok2=0;
						break;
					}
					brr[ind]=1;
					x-=v[ind];
				}
			}
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
}
