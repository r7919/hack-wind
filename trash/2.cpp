// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72815755
// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRINT(name, v) \
    cout << name << " : "; \
    for (auto& e : v) { \
        cout << e << " "; \
    } \
    cout << std::endl; \

#define LPRINT(name, l) \
    cout << "list " << name << " : "; \
    for (auto it = l.begin(); it != l.end(); ++it) { \
    	cout << *it << " "; \
    } \
    cout << std::endl; \

using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
#define INF std::numeric_limits<int>::max()
#define LLINF std::numeric_limits<long long>::max()


template <typename T, typename A>
int arg_max(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), max_element(vec.begin(), vec.end())));
}

template <typename T, typename A>
int arg_min(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), min_element(vec.begin(), vec.end())));
}

int dfs(const vector<vector<int>>& g, vector<int>& dist, int start, int end=-1)
{
	// g is a list of neighbours for each node
    // dist is assumed to be filled with INF
    queue<int> q;
    q.push(start);
    queue<int> d;
    d.push(0);
    while (q.size() > 0)
    {
        auto x = q.front();
        auto dd = d.front();
        q.pop();
        d.pop();

        if (dist[x] == INF)
        {
            dist[x] = dd;
            if (end == x)
                break;

            for (auto e: g[x]) {
                q.push(e);
                d.push(dd+1);
            }
        }
    }
    if (end >= 0 && end < dist.size())
        return dist[end];
    else
        return -1;
}



int main()
{
	ll tt;
	cin >> tt;
	F(t, tt)
	{
		ll n, k;;
		cin >> n >> k;
		vector<ll> a(n);
		F(i, n)
			cin >> a[i];

		unordered_map<ll, ll> map;
		bool ok = true;
		for (ll x : a)
		{
			//cout << "x = " << x << "\n";
			ll i = 0;
			while (x > 0)
			{
				ll r = x % k;
				x = (x-r)/k;
				//cout << "r = " << r << "\n";
				if (r > 1)
				{
					ok = false;
					break;
				}
				if (r == 1)
				{
					//cout << "i = " << i << "\n";
					if (map.find(i) != map.end())
					{
						ok = false;
						break;
					}
					else
					{
						map[i] = 1;
					}
				}
				++i;
			}
			if (!ok)
				break;
		}
		if (ok)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}


	}

    return 0;
}




