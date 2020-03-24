// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74075247
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
 
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
 
#define rep(i,a) for(int i=0;i<a;i++)
#define repn(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)

#define endl '\n'
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
const int MOD = 1000000007;
const ll INF = 1e18;

 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(n%2==0 && k<=sqrt(n) && k%2==0)
		{
			cout<<"YES"<<endl;
			continue;
		}
		if(n%2==1 && k%2==1 && k<=sqrt(n))
		{
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}


