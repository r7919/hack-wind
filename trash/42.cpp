// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820369
    #include<bits/stdc++.h>
    #define ll long long
    #define ld long double
    #define ull unsigned long long
    using namespace std;
    const ll maxx = 1e6 + 5;
    bool dd[maxx], check, d1[maxx];
    ll tr[maxx], val[maxx];
    vector<ll> adj[maxx];
    void bfs(ll u)
    {
        queue <ll> qu;
        fill_n(dd, maxx, true);
        fill_n(tr, maxx, 0);
        fill_n(val, maxx, 100000);
        dd[u] = false;
        val[u] = 0;
        qu.push(u);
        do
        {
            ll v = qu.front();
            qu.pop();
            for(ll x:adj[v])
            {
                if(dd[x])
                {
                    tr[x] = v;
                    dd[x] = false;
                    qu.push(x);
                    val[x] = min(val[v]+1, val[x]);
                }
            }
        }while( !qu.empty() );
    }
    void sol()
    {
        ll n,  c = 0, k, b[maxx], tong = 0, m, x, x1, y1, l, h, t = 0, y;
        cin >> n >> m;
        vector<ll> st[maxx];
        for(int i = 1; i <= m; i ++)
        {
            cin >> x >> y;
            adj[y].push_back(x);
            st[x].push_back(y);
        }
        cin >> k;
        for(int i = 1; i <= k; i ++)
        {
            cin >> b[i];
        }
        bfs(b[k]);
        for(int i = 1; i <= n; i ++)
            if(!dd[i])cout << val[i]<<" "<<i<<'\n';
        x1 = 0;
        y1 = 0;
        for(int i = 1; i < k; i ++)
        {
            l = 1e9;
            h = 0;
            for(ll j:st[b[i]])
                if(val[j] < l)l = val[j];
            for(ll j:st[b[i]])
            {
                if(val[j] == l && j != b[i+1])++h;
            }
            cout <<h<<" "<<b[i]<<'\n';
            if(val[b[i+1]] > l)++x1;
            y1 += h;
        }
        cout << x1 <<" "<<y1;
    }

    void cf()
    {
        ll m, a[maxx], d, b[maxx], c, n, t, ans = 0, tong = 0, k, x, y, p1, a1, b1, t1;
        bool check;
        cin >> t;
        while(t -- > 0)
        {
        cin >> n >> k;
        for(int i = 1; i <= n; i ++)
        {
            cin >> a[i];
            d = max(d, a[i]);
        }
        fill_n(dd, maxx, true);
        for(int i = 1; i <= n; i ++)
        {
            check = true;
            c = 1;
            if(a[i] == 0)continue;
        p1 = 1, t1 = 0, a1 = a[i], b1;
        while(a1 >= p1 * k)
        {
            p1 *= k;
            ++t1;
        }
        while(t1 >= 0)
        {
            b1 = a1 / p1;
            a1 %= p1;
            p1 /= k;
            if(b1 == 1)
            {
                if(dd[t1])
                dd[t1] = false;
                else
                {
                    check = false;
                    break;
                }
            }
            else if(b1 > 1)
            {
                check = false;
                break;
            }
            --t1;
        }
        if(!check)break;
        }
            if(!check)
            {
                cout << "NO" <<'\n';
            }
            else cout << "YES" <<'\n';

        }

    }
    ll uoc(ll a, ll b)
    {
        ll r;
        while( b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    bool prime(ll v)
    {
        if( v < 2)return false;
        for(int i = 2; i <= v / i; i ++)
        {
            if(v % i == 0)
                return false;
        }
        return true;
    }
    int main()
    {
        cin.tie(0);
        cout.tie(0);
        ios_base::sync_with_stdio(0);
        cf();
    }
    /*
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b = a;
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  if ((int) b.size() == n) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) {
    a[i] = (int) (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
  }
  int ans = 0;
  vector<int> mark(n, 0);
  for (int i = 0; i < n; i++) {
    int take = 0;
    for (int j = 0; j < n; j++) {
      if (mark[a[n - 1 - j]] > 0) {
        break;
      }
      mark[a[n - 1 - j]] = 1;
      ++take;
    }
    ans = max(ans, i + take);
    for (int j = 0; j < take; j++) {
      mark[a[n - 1 - j]] = 0;
    }
    if (mark[a[i]]) {
      break;
    }
    mark[a[i]] = 1;
  }
  cout << n - ans << '\n';
  return 0;
}

*/

