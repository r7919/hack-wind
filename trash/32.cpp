// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72814583
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ss second
#define ff first
#define pb push_back
#define mkp mak
#define pll pair<long long, long long>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll lim = 3e16+5;
const int mod = 1e9+7;

ll n,m,t,k;

ll Power(ll a, ll b)
{
    if(a==0)
        return 0;
    if(b==0)
        return 1;
    ll ans=Power((a*a)%mod,b/2);
    if(b&1)
        return (a*ans)%mod;
    return ans%mod;
}
ll Inv(ll a)
{
    return Power(a,mod-2);
}

ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};
int main()
{
    FIO
    cin>>t;
    //t = 1;
    while(t--)
    {
        cin>>n>>m;
        vector<ll> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector<ll> h(64,0);
        bool flag = 1;
        for(int i=0;i<n;i++)
        {
            while(v[i])
            {
                int cnt = 0;
                ll tmp = 1;
                while(tmp*m <= v[i])
                {
                    tmp *= m;
                    cnt++;
                }
                h[cnt]++;
                if(h[cnt] > 1)
                {
                    flag = 0;
                    break;
                }
                v[i] -= tmp;
            }
            if(flag == 0)
                break;
        }
        if(flag == 0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}

