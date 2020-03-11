// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819325
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> m;
        long long x = 1;
        while (x <= 1e16) {
            m.push_back(x);
            x *= k;
        }
        vector<bool> used(m.size(), 0);
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            for (int j = m.size() - 1; j >= 0; --j) {
                if (m[j] <= x && !used[j]) {
                    x -= m[j];
                    used[j] = 1;
                }
            }
            if (x != 0) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}

