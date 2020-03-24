/*
  " TEST GENERATOR "
  Author - Udaya Bhaskar (@ubc_123)
*/

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

#define endl "\n"
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
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#define dbg_arr(a,n)cerr << "[" << #a << "] = [ ";fr(i,n)cerr<<a[i]<<" ";cerr<<"]\n";
#define dbg_mat(m,r,c)cerr<<"[" <<#m<<"]:\n";fr(i,r){cerr<<"[ ";fr(j,c)cerr<<m[i][j]<<" ";cerr<<"]\n";}
#define dbg_time(t)cerr<<"Time elapsed: "<<t<<endl;
#else
#define dbg(x...){}
#define dbg_arr(a,n){}
#define dbg_mat(m,r,c){}
#define dbg_time(t){}
#endif

const ll MOD = 1e9+7;
const ll SMOD = 998244353;
const ll INF = 1e18;
const ll SINF = 1e9;
const ll MAX = 100100;

/*******************************************************************************************************************/
// Mersenne Twister - PRNG
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

ll rng(ll limit) 
{
   uniform_int_distribution< ll > uid(0, limit-1);
   return uid(rang);
}

ll random(ll a, ll b)
{
   //generates random number between a and b (inclusive)
   ll x = a + rng(SINF) % (b - a + 1);
   return x;
}

ll minKey(ll key[], bool mstSet[], vpll & tree, ll vertices);
void random_tree(ll vertices, vpll & tree);
void shuffle_v(vl & v, ll n);
void shuffle_arr(ll* arr, ll n);
void print_arr(ll* arr, ll n);
void random_arr(ll* arr, ll n, ll a, ll b);
void unique_v(vl & v, ll n, ll a, ll b);
void unique_arr(ll* arr, ll n, ll a, ll b);
void random_v(vl & v, ll n, ll a, ll b);
void print_v(vl & v, ll n);


void generate()
{
  ll n = random(1, 10);
  ll m = random(1, 10);
  cout << n <<" "<< m << '\n';
}

signed main()
{  
    clock_t begin = clock();
    // srand(atoi(argv[1]);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "w", stdout);
    #endif
    
    //cout<<fixed<<setprecision(15);

    ll test = 1;
    cout<<test<<endl;
    fr(ii,test)
    {
      // cout << "Case #" << ii + 1 << ": "<<endl;
      generate();
    }

    clock_t end = clock();
    double elapsed_secs = (double)(end - begin)/CLOCKS_PER_SEC;
    dbg_time(elapsed_secs);
    
    return 0;
}  


ll minKey(ll key[], bool mstSet[], vpll & tree, ll vertices) 
{ 
  ll V = vertices;
  ll min = INT_MAX, min_index = 0; 

  for (ll v = 0; v < V; v++) 
    if (mstSet[v] == false && key[v] < min) 
      min = key[v], min_index = v; 

  return min_index; 
} 

void random_tree(ll vertices, vpll & tree)
{
  ll V = vertices;
  ll graph[V][V];
  fr(i,V)
  {
    fr(j,V)
    {
      if(i != j)
       graph[i][j] = random(10, 1000);
      else
       graph[i][j] = INT_MAX;
    }
  } 
  ll parent[V]; 
  ll key[V]; 
  bool mstSet[V]; 
  for (ll i = 0; i < V; i++) 
  {
    key[i] = INT_MAX;
    mstSet[i] = false;  
  }
  key[0] = 0; 
  parent[0] = -1; 
  for (ll count = 0; count < V - 1; count++) 
  { 
    ll u = minKey(key, mstSet, tree, vertices); 
    mstSet[u] = true; 
    for (ll v = 0; v < V; v++) 
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
        parent[v] = u, key[v] = graph[u][v]; 
  } 
  for (ll i = 1; i < V; i++) 
  tree.eb(parent[i]+1, i+1); 
  return;
}

void shuffle_v(vl & v, ll n)  
{  
  // Fisher–Yates shuffle Algorithm
    for (ll i = n - 1; i > 0; i--)  
    {   
        ll j = rng(SINF) % (i + 1);  
        ll t = v[i];
        v[i] = v[j];
        v[j] = t;
    }  
}

void shuffle_arr(ll* arr, ll n)  
{  
  // Fisher–Yates shuffle Algorithm
    for (ll i = n - 1; i > 0; i--)  
    {   
        ll j = rng(SINF) % (i + 1);  
        ll t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }  
}

void print_v(vl & v, ll n)
{
  fr(i,n)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

void print_arr(ll* arr, ll n)
{
  fr(i,n)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void random_arr(ll* arr, ll n, ll a, ll b)
{
  fr(i,n)
  {
    ll x = random(a, b);
    arr[i] = x;
  }
}

void unique_v(vl & v, ll n, ll a, ll b)
{
  set< ll > used;
  fr(i,n)
  {
    ll x;
    do
    {
      x = random(a, b);
    }
    while(used.count(x));
    used.insert(x);
    v.pb(x);
  }
}

void unique_arr(ll* arr, ll n, ll a, ll b)
{
  set< ll > used;
  fr(i,n)
  {
    ll x;
    do
    {
      x = random(a, b);
    }
    while(used.count(x));
    used.insert(x);
    arr[i] = x;
  }
}

void random_v(vl & v, ll n, ll a, ll b)
{
  fr(i,n)
  {
    ll x = random(a, b);
    v.pb(x);
  }
}
