// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820707
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
#include <map>

using namespace std;

long long a[114514];

long long kn[111], bits[111];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		int flag = 0;
		memset(bits, 0, sizeof(bits));
		scanf("%d%d", &n, &k);
		long long maxa = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
			if (a[i] > maxa) {
				maxa = a[i];
			} 
		}
		long long pos = 0, val = 1;
		kn[0] = 1;
		while (val < maxa) {
			pos++;
			val *= k;
			kn[pos] = val;
		}
		int maxpos = pos;
		for (int i = 0; i < n; i++) {
			for (int j = maxpos; j >= 0; j--) {
				if (a[i] >= kn[j]) {
					a[i] -= kn[j];
					bits[j]++;
				}
			}
			if (a[i]) flag = 1;
		}
		for (int i = 0; i <= maxpos; i++) {
			if (bits[i] > 1) {
				flag = 1;
			}
		}
		if (flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
