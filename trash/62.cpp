// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72823028
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define int long long
#define pii pair <int, int>
#define pci pair <char, int>
#define pss pair <string, string>
#define psi pair <string, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PI acos(-1.0)
#define fi first
#define se second

int const INF = 1e16 + 1;
int const MOD = 1e9;

vector<int> ks(int n, int k) {
    vector<int> res;
    while (n >= k) {
        res.push_back(n - n / k * k);
        n /= k;
    }
    res.push_back(n);
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        auto v = ks(a[i], k);
        for (int j = v.size() - 1; j >= 0; j--) {
            pos[j] += v[j];
        }
    }
    for (auto to : pos) {
        if (to.second > 1) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
    return 0;
}

