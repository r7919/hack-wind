#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define tr(x,container) for(auto &x:container)
#define fr(i,n) for(ll i=0;i<(n);++i)
#define frs(i,s,n) for(ll i=s;i<(n);++i)
#define frb(i,s,e) for(ll i=s;i<=(e);++i)
#define rfr(i,n) for(ll i=(n-1);i>=0;i--)
#define frbr(i,e,s) for(ll i=e;i>=(s);i--)
#define mset(m,v) memset(m,v,sizeof(m))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define find_bug(x) cout <<'>' << #x << " : " << x << endl;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

clock_t startTime;
double getCurrentTime() {return ((double)(clock() - startTime)) / CLOCKS_PER_SEC;} 

#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#define dbg_arr(a,n)cerr << "[" << #a << "] = [ ";fr(i,n)cerr<<a[i]<<" ";cerr<<"]\n";
#define dbg_mat(m,r,c)cerr<<"[" <<#m<<"]:\n";fr(i,r){cerr<<"[ ";fr(j,c)cerr<<m[i][j]<<" ";cerr<<"]\n";}
#define dbg_time()cerr<<"Time elapsed: "<<getCurrentTime()<<endl;
#define tle() {if(getCurrentTime() > 5.0) {dbg_time();cerr<< "#ForceExit - TLE - 5.0" << endl; exit(1);}}
#else
#define dbg(x...){}
#define dbg_arr(a,n){}
#define dbg_mat(m,r,c){}
#define dbg_time(t){}
#define tle(){}
#endif

const ll MOD = 1e9+7;
const ll SMOD = 998244353;
const ll INF = 1e16;
const ll SINF = 1e9;
const ll MAX = 100100;

/*******************************************************************************************************************/

void pre()
{
  
}


//Binary Exponentiation -- O(logn)
ll binpow(ll a, ll b) 
{
    ll res = 1;
    while (b > 0) 
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve()
{
  ll n,k;
  cin >> n >> k;
  ll arr[n];
  fr(i,n)
  {
    cin >> arr[i]; 
  } 

  unordered_map < ll, ll > up;

  ll p = 1;

  up[p]++;

  while(p <= INF)
  {
    p = p*k;
    up[p]++;
  }

  dbg(up);

  fr(i,n)
  {
    dbg(arr[i]%19);
    ll x = arr[i];
    vl v;
    vl vc;
    ll c = 0;
    while (x > 0) 
    { 
      vc.pb(c);
      v.pb((x % k)); 
      x /= k; 
      c++;
    }  
    dbg(v);
    dbg(vc);
    fr(j,sz(v))
    {
      if(v[j])
      {
        up[binpow(k,vc[j])]-=v[j];
      }
    }
    // dbg(up);
  }

  dbg(up);

  tr(x,up)
  {
    if(x.ss < 0)
    {
      cout << "NO" << '\n';
      return ;
    }
  }

  cout << "YES" << '\n';
}

signed main()
{  
    startTime = clock();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    //cout<<fixed<<setprecision(15);
    //pre();

    ll test = 1;
    cin>>test;
    fr(ii,test)
    {
      // cout << "Case #" << ii + 1 << ": "<<endl;
      solve();
    }

    dbg_time();
    
    return 0;
}    
