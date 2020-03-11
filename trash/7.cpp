// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72816660
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define INF             1e9
#define INFL            8e18
#define XX              first
#define YY              second
#define PB              push_back
#define MP              make_pair

#define NEWLINE         cerr << "\n";
#define HOISE           cerr << "hoise " << __LINE__ << "\n"
#define PAUSE           system("pause")
#define DEBUG(x)        cerr << #x << " = " << x << "\n"
#define READ            freopen("D:\\moidda CPP\\alu.txt", "r", stdin)
#define WRITE           freopen("D:\\moidda CPP\\vorta.txt", "w", stdout)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MASK(x)         for(int i = 0; i < 8; i++){ if(x&(1<<i)){ cout << i << " "; } } cout << endl;

typedef long long ll;
typedef pair<int, int > pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pff;

const ll MAX = 1e16;
const int MAXLOG = log2(MAX) + 2;
const int MAXN = 1e6 + 2;
const int MOD = 998244353;
const double PY = acos(-1.0);
const double EPS = 1E-9;

vector<ll> p[101];

inline void solve(int nc)
{
    int n;
    ll k;
    cin >> n >> k;

    vector<bool> used((int)p[k].size() + 10, false);
    vector<ll> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int j = (int)p[k].size()-1; j>=0; j--){
        for(int i = 0; i < n; i++){
            if(a[i] >= p[k][j]){
                a[i] -= p[k][j];
                break;
            }
        }
    }

    bool ok = true;
    for(int i = 0; i < n; i++){
        if(a[i]!=0){
            ok = false;
        }
    }

    if(!ok) cout << "NO\n";
    else cout << "YES\n";
}

int32_t main()
{
#ifndef ONLINE_JUDGE
//    READ;
//    WRITE;
#endif

    FASTIO;

    int sz = 0;
    for(ll k = 2; k <= 100; k++){
        p[k].PB(1LL);
        while(true){
            ll x = k*p[k].back();
            if(x <= MAX and x>=0){
                p[k].PB(x);
            }
            else{
                break;
            }
        }
        sz += p[k].size();
    }
//    DEBUG(sz);
//    return 0;

    int tc;
    cin >> tc;
    for(int nc = 1; nc <= tc; nc++){
        solve(tc);
    }

    return 0;
}


