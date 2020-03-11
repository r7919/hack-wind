// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819332
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<long long> v(n);
    vector<long long> p(1, 1);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 1; i < 100; ++i) {
      if (p[i-1] * k < p[i-1]) break;
      p.push_back(p[i-1] * k);
    }
    
    set<int> s;
    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
      for (int j = p.size()-1; j >= 0; --j) {
        if (v[i] >= p[j]) {
          v[i] -= p[j];
          if (s.count(j)) {
            ok = false;
            break;
          } else {
            s.insert(j);
          }
        }
      }
      if (v[i] != 0) ok = false;
    }
    cout << (ok?"YES\n":"NO\n");
  }
}
