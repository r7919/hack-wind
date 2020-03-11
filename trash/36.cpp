// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72816163
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
const double eps = 1e-8;
const double pi = acos(-1.0);
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll qw(ll x,ll y){ll ans = 1;while(y){if(y&1) ans *= x;x *= x;y >>= 1;}return ans;}
int t,n,k;
ll a[35];
bool vis[65];
vector<ll> v;
bool check(){
	for(int i = 0;i < n;i++){
		ll x = a[i];
		int cnt = 0;
		while(x){
			ll t = x % k;
			if(t > 1) return 0;
			else if(t == 1){
				if(vis[cnt]) return 0;
				else{
					vis[cnt] = 1;
				}
			}
			cnt++;
			x /= k;
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		v.clear();
		cin >> n >> k;
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < n;i++) cin >> a[i];
		if(check()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	return 0;
}
