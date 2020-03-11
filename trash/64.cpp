// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72822998
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
template <class T>
inline void read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return ;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1:1;
    ret = (c == '-') ? 0:(c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return ;
}
inline void out(int x) {
    if (x > 9) out(x / 10);
    putchar(x % 10 + '0');
}
bool book[70] = {false};
bool judge(ll x, ll k) {
    int ans = 0;
    while (x) {
        ll tmp = x % k;
        //cout <<tmp <<endl;
        if (tmp == 1) {
            if (book[ans] == true) return false;
            else book[ans] = true;
        } else if (tmp != 0) return false;
        x /= k;
        ans++;
    }
    return true;
}
int main() {
    int t, n, k;
    read(t);
    while (t--) {
        memset(book, false, sizeof(book));
        read(n), read(k);
        ll a[40];
        bool flag = true;
        for (int i = 0; i < n; i++) read(a[i]);
        for (int i = 0; i < n; i++) {
            flag = judge(a[i], k);
            if (!flag) break;
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
}

