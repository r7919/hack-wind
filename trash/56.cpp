// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72818206
#include                        <bits/stdc++.h>
#include                        <ext/pb_ds/assoc_container.hpp>
#define lb                      lower_bound
#define ub                      upper_bound
#define pb(x)                   push_back((x))
#define pb2(x,y)                push_back({x,y})
#define pb3(x,y,z)              push_back({x,y,z})
#define load(node,n)            bool operator < (const node &n) const
#define fbo(x)                  find_by_order(x)
#define ook(x)                  order_of_key(x)
#define all(x)                  (x).begin(),(x).end()
#define FOR(i,n)                for(int i = 1; i<=n; i++)
#define REP(i,n)                for(int i = 0; i<n;  i++)
#define dbg(a)                  cout<<#a <<" --> "<<(a)<<endl;
#define TT                      int TC;  scanf("%d",&TC);  while(TC--)
#define read                    freopen("input.txt","r",stdin)
#define write                   freopen("output.txt","w",stdout)
#define FAST                    ios::sync_with_stdio(false); cin.tie(nullptr);  cout.tie(nullptr);
#define set(x)                  tree<x,null_type,less<x>,rb_tree_tag,tree_order_statistics_node_update>
using                           namespace std;
using                           namespace __gnu_pbds;
typedef                         long long ll;
typedef                         pair<ll,ll> pll;
typedef                         pair<int,int> pii;

ll k;

bool check(ll n){
    ll x = 0;
    while(n){
        n/=k;
        if(n%k) return false;
    }
    return 1;
}

map<ll,ll> mp;
ll pwr[102];

main(){
//read;
//FAST;
ll n;

TT{
    cin>>n>>k;
    vector<ll> v;
    mp.clear();
    memset(pwr,0,sizeof pwr);
    pwr[0] = 1;
    ll id = 0;
    for(ll i = 1; i<62; i++){
        ll x = pwr[i-1]*k;
        pwr[i] = x;
        id++;
        if(x>=1e16) break;
    }
    bool fl = 1;
    for(int i = 0; i<n; i++){
        ll a;
        cin>>a;
        if(a==0)    continue;
        if(mp[a])   fl = 0;
        v.pb(a);
        mp[a] = 1;
    }
    vector<ll> w;
    if(fl==0){
        puts("NO");
        continue;
    }
    for(ll i:v){
        ll p = i;
        while(p){
            if(p<pwr[1] && p>1){
                fl = 0;
                break;
            }
            for(ll j = id; j>=0; j--){
                if(pwr[j]>p)    continue;
                if(p==0)    break;
                w.pb(j);
                p-=pwr[j];
            }
        }

    }
//    cout<<"HI "<<w.size()<<endl;
    sort(all(w));
    for(ll i = 1; i<w.size(); i++)
        if(w[i]==w[i-1])    fl = 0;

    if(fl==0)  {
        puts("NO");
        continue;
    }
    puts("YES");
}




return 0;
}

