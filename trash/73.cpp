// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821736
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define mp make_pair
#define all(v) v.begin(), v.end()
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;

const ll inf = int(1e9 + 7);
const double eps = 1e-7;
const int maxn = int(2e5 + 10);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        forn(i, n) {
            cin >> v[i];
        }

        bool ok = true;
//        bool ed = true;
//        forn(i, n) {
//            if((ed && d[i] - 1 % k == 0) || d[i] % k == 0) {
//                if(ed && d[i] - 1 % k == 0) {
//                    ed = false;
//                    v.pb(d[i] - 1);
//                } else {
//                    v.pb(d[i]);
//                }
//            }
//            else {
//                ok = false;
//                break;
//            }
//        }
//
//        if(!ok) {
//            cout << "NO" << endl;
//            continue;
//        }

        unordered_set<int> s;
        for(int i = 0; i < v.size() && ok; i++) {
            ll cur = v[i];
            int cnt = 0;
            while(cur > 0) {
                while(cur % k == 0) {
                    cur /= k;
                    cnt++;
                }
                if(s.count(cnt) > 0) {
                    ok = false;
                    break;
                }
                s.insert(cnt);
                cur--;
            }
        }

        if(!ok) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}
