// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819901
#include <bits/stdc++.h>
#include <vector>
#define FASTIO ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
typedef long long ll;
double ch(double n,double base);
int main()
{
    FASTIO;
    ll ans=1e9+7;
    ll an=1e9+7;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a[n];
        string s="YES";
        map<ll,ll> g;
        for(int i=0; i<n; cin>>a[i],i++);
        for(int i=0; i<n&&s=="YES"; i++)
        {
            ll p=1;
            while(p<=a[i]) p*=k;
            while(a[i]>0)
            {
                if(a[i]>=p)
                {
                    a[i]-=p;
                    if(g[ch(p,k)+1]==1)
                    {
                        s="NO";

                        break;
                    }
                    else g[ch(p,k)+1]=1;
                }
                p/=k;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}

double ch(double n,double base)
{
    ll i=0;
    while(n>=base)
    {
        i++;
        n/=base;
    }
    return i;
}

