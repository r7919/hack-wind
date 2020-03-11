// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820937
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using vi = vector<lint>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    rep(_, t) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        rep(i, n) cin >> a[i];

        vi b(n, 0);

        lint s = 0;
        lint m = -1;
        rep(i, n) {
            s += a[i];
            m = max(m, a[i]);
        }
        m *= 8;
        
        vi kp(64, -1);
        rep(i, 64) {
            kp[i] = modpow(k, i);
            if (kp[i] > m) break;
        }

        rep(i, n) {
            for (int j = 63; j >= 0; j--) {
                if (kp[j] == -1) continue;
                if (kp[j] <= a[i]) {
                    a[i] -= kp[j];
                    b[i] |= 1LL << j;
                }
            }
        }

        bool f = false;

        rep(i, n) {
            if (a[i] > 0) f = true;
        }

        if (f) {
            cout << "NO" << endl;
            continue;
        }

        rep(i, 64) {
            int c = 0;
            lint o = 1LL << i;
            rep(j, n) {
                if (b[j] & o) c++;
            }
            if (c >= 2) f = true;
        }

        if (f) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
