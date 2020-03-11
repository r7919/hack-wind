// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821304
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define dd(x) cout<<#x<<" = "<<x<<" , "
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=b;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//INF = 1 061 109 567 ; INF + INF = 2 122 219 134 ;
//LINF = 4 557 430 888 798 830 399 ; LINF + LINF = 9 114 861 777 597 660 798 ;
const int INF = 0x3f3f3f3f;     // -INF: 0xc0   abs(-INF) = INF + 1
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 4e4+7;
int n,m,k;
ll a[35];
ll fpow(ll a,ll b){
	ll ret=1;
	for(;b;b>>=1,a=a*a) if(b&1) ret=ret*a;
	return ret;
}
int vis[101];
ll cis(ll num,ll k){
	ll ret=1,cnt=0;
	while(ret<=num){
		ret=ret*k;
		cnt++;
		
	}
	cnt--;
	return cnt;
}
bool work(ll num,ll k){
	if(num==0) return true;
	//de(num);
	while(num){
		ll cs=cis(num,k);
		//de(cs);
		if(vis[cs]) return false;
		vis[cs]=1;
		ll p=pow(k,cs);
		//dd(num);de(p);
		num=num-p;
	}
	return true;
}
int main(){
	//de(cis(81,9));
	int t;
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof(vis));
		
		ll n,k;
		scanf("%lld%lld",&n,&k);
		rep(i,1,n+1) {
			scanf("%lld",&a[i]);
		}
		int fg=0;
		rep(i,1,n+1){
			if(!work(a[i],k)){
				fg=1;
				break;
			}
		}
		if(fg) puts("NO");
		else puts("YES");
	}
	return 0;
}



