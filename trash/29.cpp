// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72818062
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3 + 4;

int n, k;
ll cnt[N];

void getDegs(ll x){
    vector <ll> a;

    while (x >= k){
        ll cur = x / (ll)k;
        ll cur2 = cur * (ll)k;
        a.push_back(x - cur2);
        x = cur;
    }
    a.push_back(x);

    for (int i = 0; i < a.size(); ++i){
        cnt[i] += a[i];
    }
}

void solve(){
    cin >> n >> k;
    memset(cnt, 0, N * sizeof(int));

    for (int i = 0; i < n; ++i){
        ll x;
        cin >> x;
        getDegs(x);
    }

    for (int i = 0; i < N; ++i){
        if (cnt[i] > 1){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i){
        solve();
    }

    return 0;
}

