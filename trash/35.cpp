// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72822054
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 1e4;
const int MOD = 998244353;
const double EPS = 1e-6;

const double PI = acos(-1);

map<int, int> cnt;
int k;

bool getPowers(long long x) {
    long long sum = 1;
    long long add = 1;
    int pow = 0;
    while (sum < x) {
        add *= k;
        pow++;
        sum += add;
    }
    map<int, int> mp;
    while (true) {
        if (add <= x) {
            x -= add;
            mp[pow]++;
        }
        if (add == 1)
            break;
        add /= k;
        pow--;
    }
    if (x != 0)
        return false;
    for (auto el : mp) {
        cnt[el.first] += el.second;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n >> k;
        long long a[n];
        for (auto &x : a)
            cin >> x;
        cnt.clear();
        bool ok = 1;
        for (auto x : a) {
            if (x == 0)
                continue;
            if (!getPowers(x)) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            for (auto x : cnt)
                if (x.second > 1) {
                    ok = 0;
                    break;
                }
        }
        if (ok)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}
