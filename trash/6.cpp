// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74075306
#include <bits/stdc++.h>

using namespace std;

//#define NATIVE 

int main() {
#ifdef NATIVE
	freopen("d:\\code\\cf\\in.txt", "r", stdin);
	freopen("d:\\code\\cf\\out.txt", "w", stdout);
#endif
	
	int t, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		if(k > (int)sqrt(1.0 * n)) {
			cout << "NO" << endl;
			continue;
		}
			
		if((k % 2 && n % 2 == 0) || (k % 2 == 0 && n % 2))
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	} 
	
	return 0;
}
