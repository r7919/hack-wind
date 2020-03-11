// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819211
#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<vector<int>> res;
        vector<bool> used(100, false);
        bool bl = true;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (!bl) continue;
            vector<int> opa;
            if (x == 0) continue;
            int nw = 1;
            int cnt = 0;
            while (x > nw) {
                nw *= k;
                ++cnt;
            }
            for (int j = cnt; j >= 0; --j) {
                if (x / nw == 1) {
                    x %= nw;
                    if (used[cnt]) {
                        bl = false;
                        break;
                    }
                    used[cnt] = true;
                } else if (x / nw > 1) {
                    bl = false;
                    break;
                }
                --cnt;
                nw /= k;
            }
        }
        if (bl) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

