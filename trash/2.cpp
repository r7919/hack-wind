// LILY SOURCE:  https://codeforces.com/contest/1324/submission/73040762
#include <bits/stdc++.h>
using namespace std;

const int N = 1234567;
int n;
int a[N];
vector<int> g[N];
int dp[N];
int res[N];

void dfs(int u, int p) {
    dp[u] = a[u];
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u] += max(0, dp[v]);
        }
    }
}

void upd_dfs(int u, int p, int mx) {
    int sum = a[u] + mx;
    for (int v : g[u]) {
        if (v != p) {
            sum += max(0, dp[v]);
        }
    }
    res[u] = max(res[u], sum);
    for (int v : g[u]) {
        if (v != p) {
            sum -= max(0, dp[v]);
            upd_dfs(v, u, max(0, sum));
            sum += max(0, dp[v]);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!a[i]) a[i] = -1;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fill_n(res, n, -1);
    dfs(0, -1);
    upd_dfs(0, -1, 0);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}

