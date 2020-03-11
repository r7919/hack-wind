// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819846
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'
ll power(ll a, ll b){
    ll ans = 1;
    for(int i = 0 ; i < b ; i++)
        ans *= a;
    return ans;
}

int main()
{
    ll q;
    cin >> q;
    while(q--)
    {

        ll n,k;
        cin >> n >> k;

        std::vector<ll> v;
        for (int i = 0; i < n; ++i)
        {
            ll x;cin >> x;
            v.pb(x);
        }

        std::vector<ll> pos_powers;

        for(int i=0;i<100;i++){
            ll ff = power(k,i);
            if(ff > 1e16)
                break;
            pos_powers.pb(ff);
        }

        ll used[101] = {0};
        
        ll f = 0;
        

        for (int i = 0; i < n; ++i)
        {
            ll num = v[i];
            
            int pw = 0;

            while(num > 0){
                
                ll lft =  num % k;
                num /= k;
                pw += 1;

                if(lft == 0)
                    continue;
                
                if(lft == 1){
                    if(used[pw]){
                        f = 1;
                        break;
                    }
                    // cout << pw << " " << v[i] << endl;
                    used[pw] = 1;
                }

                if(lft > 1){
                    f = 1;
                    break;
                }

                // cout << lft << endl;
                // used[lft] = 1;
            }

            if(f == 1)
                break;
            // cout << v[i] << endl;
        }

        if(f == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

    }

	return 0;
}



