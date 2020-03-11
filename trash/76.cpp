// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72817883
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define SPEED ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz size()
#define all(x) x.begin(),x.end()
#define mib map<int,bool>
#define mii map<int,int>
#define file_in(f) freopen("f","r",stdin);
#define file_out(f) freopen("f","w",stdout);
#define OO 1e18
#define iOO INT_MAX
#define mdp memset(dp,-1,sizeof dp)
#define R return

using namespace std;
map<int,bool> vis;
int main()
{
    SPEED;
    ll t,n,k,a[200];
    cin >> t;
    while(t--)
    {
        vis.clear();
        bool ok = true;
        cin >> n >> k;
        vector<ll> p(70,0);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        p[0]=1;
      //  int lst;
        for(int i=1;i<=60;i++)
        {
            p[i] = p[i-1]*k;
            if(p[i]*k >= 10000000000000001)
                break;
            //lst = i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j = 60 ; j >= 0 ; j--)
            {
                if(a[i]-p[j] >= 0 && !vis[j])
                {
                    vis[j]=true;
                    a[i]-=p[j];
                }
            }
            if(a[i] != 0)
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES":"NO")<<endl;
    }
    R 0;
}

