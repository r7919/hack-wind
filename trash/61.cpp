// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72817420
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

#define drobucs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define all(x) (x).begin(), (x).end()

typedef long long               ll;
typedef unsigned long long      ull;
typedef double                  dbl;
typedef unordered_map<int, int> u_mii;
typedef unordered_map<ll, ll>   u_mll;
typedef string                  str;
typedef pair<int, int>          pii;
typedef vector<int>             vi;
typedef vector<ll>              vll;
typedef vector<bool>			vb;
typedef vector<pair<int, int>>  vpii;
typedef vector<pair<ll, ll>>    vpll;
typedef vector<vector<int>>     vvi;
typedef vector<vector<ll>>      vvll;

const int MAXN = 2e5 + 13;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll INFL = LLONG_MAX;
const ull INFUL = ULLONG_MAX;
const dbl PI = acos(-1);


struct Solve {
	Solve() {
		ll n, k;
		cin >> n >> k;
		vll v(n);
		vb vis(70, 0);
		for (auto& t : v)cin >> t;
		for (auto t : v) {
			ll ost = -1;
			ll u = t;
			ll cnt = 0;
			while (u > 0) {
				ost = u % k;
				u /= k;
				if (ost > 1) {
					cout << "NO\n";
					return;
				}
				if (ost == 1) {
					if (vis[cnt]) {
						cout << "NO\n";
						return;
					}
					vis[cnt] = 1;
				}
				cnt++;
			}
		}
		cout << "YES\n";
	}
};

int main() {
	drobucs;
	int q = 1;
	cin >> q;
	while (q--) {
		Solve drobucs1;
	}
	return 0;
}
