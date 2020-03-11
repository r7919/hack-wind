// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72824866
#include <bits/stdc++.h>

#define int long long
#define pb push_back

using namespace std;

const int N = 105;

int t, n, k;
int a[N], used[N];

int get (int x) {
    int cnt = 0;
    while (x) {
        x /= k;
        cnt ++;
    }return (cnt - 1);
}

void solve () {
    cin >> n >> k;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
    }sort (a + 1, a + n + 1);
    int cnt = 0;
    for (int i = 0;i <= 100;i ++) {
        used[i] = false;
    }
    for (int i = 1;i <= n;i ++) {
        if (a[i] % k > 1) {
            cout << "NO\n";
            return;
        }
        if (a[i] % k == 1)cnt ++;
    }
    if (cnt > 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 1;i <= n;i ++) {
        if (a[i] % k == 1)a[i] --;
        if (!a[i])continue;
        int in = a[i];
        for (int j = get (a[i]);j >= 0;j --) {
            int val = pow (k, j);
            if (a[i] - val >= 0) {
                a[i] -= val;
            }
        }
        if (!a[i]) {
            a[i] = in;
            for (int j = get (a[i]);j >= 0;j --) {
                int val = pow (k, j);
                if (a[i] - val >= 0) {
                    a[i] -= val;
                    if (used[j]) {
                        cout << "NO\n";
                        return;
                    }
                    used[j] = true;
                }
            }
        }else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

main () {
    cin >> t;
    while (t --) solve ();
    return 0;
}

