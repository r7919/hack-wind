// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72824860
#include <bits/stdc++.h>
using namespace std;

using LL = long long;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		LL v = 1;
		while (v <= LONG_LONG_MAX / k)
			v *= k;
		vector<LL> numbers;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			long long a;
			cin >> a;
			LL temp = v;
			while (temp > 0) {
				if (temp <= a) {
					LL d = a / temp;
					if (d > 1) {
						flag = false;
					}
					a -= temp;
					numbers.push_back(temp);
				}
				temp /= k;
			}
			if(a) flag = false;
		}
		sort(numbers.begin(), numbers.end());
	//	for(int i = 0; i < numbers.size(); i ++) cout << numbers[i] << endl;
		for (int i = 1; i < numbers.size(); i++) {
			if (numbers[i] == numbers[i - 1])
				flag = false;
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}

