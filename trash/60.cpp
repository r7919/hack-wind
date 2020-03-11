// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72816741
#pragma GCC optimize(3,"Ofast","inline")  	//G++
#include<bits/stdc++.h>
#define TEST freopen("C:\\Users\\hp\\Desktop\\ACM\\in.txt","r",stdin);
#define mem(a,x) memset(a,x,sizeof(a))
#define debug(x) cout << #x << ": " << x << endl;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fcout cout<<setprecision(4)<<fixed
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;


const ll inf=0x3f3f3f3f;
const ll INF=0x7fffffffffffffff;
const ll mod=1e9+7;
const ll maxn = 1e6+5;
const double eps=1e-8;

template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}
ll a[maxn];
ll vis[maxn];
ll n,m;
ll check(ll x){
    ll pos=0;
    while(x){
        ll t=x%m;
        if(t>1) return 1;
        if(t) vis[pos]++;
        x/=m;
        if(vis[pos]>1) return 1;
        pos++;
    }
    return 0;
}
main()
{
    ll T;
    read(T);
    while(T--){
        for(ll i=0;i<=100;i++){
            vis[i]=0;
        }
        read(n,m);
        for(ll i=1;i<=n;i++){
            read(a[i]);
        }
        ll F=0;
        for(ll i=1;i<=n;i++){
            if(check(a[i])){
                puts("NO");
                F=1;
                break;
            }
        }
        if(!F)
            puts("YES");
    }
}

