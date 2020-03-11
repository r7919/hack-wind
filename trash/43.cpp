// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72823997
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define for1(i, a, b) for(i = a; i <= b; ++i)
#define for0(i, a, b) for(i = a; i < b; ++i)
#define forw1(i, a, b) for(i = a; i >= b; --i)
#define forw0(i, a, b) for(i = a - 1; i >= b; --i)
#define fora(v, a) for(auto v : a)
#define bp __builtin_popcount
#define bpll __builtin_popcountll

using namespace std;
using cd = complex<double>;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<cd> vcd;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;

const int modd1 = 1e9 + 7, modd2 = 998244353, maxn = 10;
const double pi = acos(-1);

void solve(){
    int t, i, j, n, m, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int a[n + 5], cnt[74];
        for1(i, 0, 70){
            cnt[i] = 0;
        }
        for1(i, 1, n){
            cin >> a[i];
        }
        bool ok = 1;
        for1(i, 1, n){
            int tmp = a[i];
            vi luu;
            while(tmp > 0){
                int m = tmp % k;
                luu.pb(m);
                tmp /= k;
            }
            int xet = luu.size(); //cout << xet << ' ';
            forw0(j, xet, 0){
                //cout << luu[j];
                if(luu[j] == 0){
                    continue;
                }
                else{
                    cnt[j] += luu[j];
                    //cout << j << ' ';
                    if(cnt[j] > 1){
                        ok = false; //break;
                    }
                }
            }
           // cout <<'\n';
        }
        if(!ok){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}

signed main() {
    //freopen(".INP", "r", stdin); 
    //freopen(".OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
