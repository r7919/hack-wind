// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72818063
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, k;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a[100] = {};
		cin >> n >> k;
		bool pos = true;
		for (int j = 0; j < n; j++)
		{
			long long q, res = 0;
			cin >> q;
			while (q != 0)
			{
				if (q%k == 1) {
					a[res++]++; q = (q - 1) / k;
				}
				else if (q%k == 0) { res++; q = q / k; }
				else {
					pos = false; break;
				}
			}
		}
		for (int i = 0; i < 100; i++) if (a[i] > 1) pos = false;
		if (pos) cout << "YES\n";
		else cout << "NO\n";

	}
	return 0;
}
