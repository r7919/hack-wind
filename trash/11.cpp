// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820734
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define trace(x) clog<<#x<<": "<<x<<endl
#define debug(x) cout << #x << ":" << x << ' ';
#define debugg(x) cout << #x << ":" << x << ' ' << "\n";
#define pb push_back
#define mod 1000000007
#define vi vector<int>
#define si set<int>
#define pi pair<int,int>
#define li list<int>
#define fi first
#define in insert
#define se second
#define mkp make_pair
#define fr(i,n) for(i = 0 ; i < n ; i++)
#define  test int t; cin>>t; while(t--)

bool fun(ll n,int k,vi &v)
{
    bool f = 0;
    while(n&& f==0)
    {
        if(n%k==0 || n%k==1)
            {v.pb(n%k);
            n = n/k;}
            else
                f = 1;

    }
    return f;
}
int main()
{

    test{
    int n,k,i,j;
    vector<bool> vis(100,0);
bool err = 0;
    cin>>n>>k;
    ll a[n];
    fr(i,n)
    {cin>>a[i];}
    fr(j,n)
    {vi v;
    if(fun(a[j],k,v) == 0)
    {fr(i,v.size())
    {
        if(v[i]==1)
        {if(vis[i] == 0)
            vis[i] = 1;
        else
        err = 1;
        }
        if(err)
            break;
    }
    }
    else
        err= 1;

    }
if(err)
cout<<"NO\n";
else
    cout<<"YES\n";
    }
return 0;
}

