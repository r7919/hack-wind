// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820415
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> d2b(ll n, ll k)
{
    vector<ll> v;
    while(n!=0)
    {
        v.push_back(n%k);
        n/=k;
    }
    return v;
}
int main()
{
    ll i,j;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k,i,j;
        cin>>n>>k;
        vector<ll> a(n);
        map<ll,ll> m;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            vector<ll> v=d2b(a[i],k);
            for(j=0;j<v.size();j++)
                m[j]+=v[j];
        }
        ll f=1;
        for(auto in:m)
        {
            if(in.second>1)
            {
                f=0;
                break;
            }
        }
        if(f==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}

