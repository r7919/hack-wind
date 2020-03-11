// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820697
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define sz size()

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1){cout<<name<<" : "<<arg1<<"\n";}
template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args)
{const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" , ";__f(comma+1, args...);} 
#define traceloop(x,a) { cerr<<#a<<": "; for(ll ix=0;ix<x;ix++) cerr<<a[ix]<<" "; cerr<<endl; }

template<typename T> inline T gcd(T a, T b) {return (b?gcd(b,a%b):a);}
template<typename T> T lcm(T a, T b) {return (a*(b/gcd(a,b)));}
template<typename T> T mod(T a, T b) {return (a<b ? a : a%b);}
template<typename T> T mod_neg(T a, T b) {a=mod(a, b);if(a<0){a+=b;}return a;}
template<typename T> T power(T e, T n) {T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T> T power(T e, T n, T m) {T x=1%m,p=e%m;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template<typename T> T extended_euclid(T a, T b, T &x, T &y) {T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n) {T x,y;T d = extended_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}


int main()
{
	ios::sync_with_stdio(0);
	ll i, j, k, n, t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		vector<ll> used(70);

		bool can = true;
		for(i=0;i<n;++i)
		{
			ll temp;
			cin >> temp;

			if(!temp)
				continue;
			
			while(temp)
			{
				//trace(i, temp);
				ll kk = 1;
				ll pw = -1;
				while(kk > 0 and temp % kk == 0)
				{
					//trace(pw, kk, k);
					kk *= k;
					pw++;
				}

				//trace(i, pw, kk);
				temp = temp - power(k, pw);
				used[pw]++;
			}

			if(temp == 1)
			{
				used[0]++;
			}
			else if(temp != 0)
				can = false;
		}

		if(!can)
		{
			cout << "NO\n";
		}
		else
		{
			for(i=0;i<70;++i)
			{
				if(used[i] > 1)
					can = false;
			}

			cout << (can ? "YES\n" : "NO\n");
		}
	}

	return 0;
}
