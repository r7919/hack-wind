// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72815909
#include <bits/stdc++.h>
using namespace std;

#define D(x) cerr << #x << " = " << x << '\n'
#define DD(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'
#define DDD(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << '\n'

#define mem(x, y) memset(x, y, sizeof(x))
typedef long long LL;

int n;
LL k, arr[33];
unordered_set <int> covered;

bool check(LL val) {
	if (val == 0) {
		return true;
	}
	int idx = 0;
	while (val != 0) {
		if (val%k == 1) {
			if (covered.find(idx) != covered.end()) {
				return false;
			} else {
				covered.insert(idx);
			}
		} else if (val%k != 0) {
			return false;
		}
		val /= k;
		idx++;
	}
	return true;
}

bool solve() {
	for (int i = 0; i < n; i++) {
		if (!check(arr[i])) {
			return false;
		}
	}
	return true;
}

int main() {
//    assert(freopen("in.txt", "r", stdin));
//    assert(freopen("out.txt", "w", stdout));

	int test;

	cin >> test;
	while (test--) {
		covered.clear();
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		puts(solve()? "YES" : "NO");
	}

    return 0;
}

