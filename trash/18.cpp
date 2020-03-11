// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72824396
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define ll long long
#define faltu ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define binary(x) std::string binary = std::bitset<25>(x).to_string(); //to binary
#define mod 1000000007
#define pie 3.14159265358979323846
ll int MMM=mod;
ll int pw(ll int a, ll int b) {
    if (b == 0) return 1;
    ll int t = pw(a, b / 2);
    if (b % 2 == 0) return (t * t);
    else return ((t * t)* a);
}
using namespace std;
vector<int> pm;
void prm(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
              prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p]) pm.push_back(p);
}
bool sortbysecdesc(const pair<ll int,ll int> &a,const pair<ll int,ll int> &b)
{
    if(a.second==b.second)return a.first<b.first;
    return a.second>b.second;
}
bool cmp(int x,int y){return x>y;}
ll int gcd(ll int a,ll int b)
{
    if(!a)return b;
    return gcd(b%a,a);
}
map<ll int,ll int>pa;
int find(ll int i){
    if(pa[i]==0)return i;
    return pa[i]=find(pa[i]);
}
void join(int i,int j){
    int a=find(i);
    int b=find(j);
    if(b>=a)pa[b]=a;
    else pa[a]=b;
}   
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
ll int lg(ll int xx,ll int k)
{
                ll int val=0;
                while(1)
                {
                    if(pw(k,val)<=xx)
                    {
                        if(pw(k,val)==xx)return val;
                        else val++;
                    }
                    else return val-1;
                }
                return val;
}
main()
{
    faltu;
    ll int t;
    cin>>t;
    while(t--)
    {
        ll int n,k;
        cin>>n>>k;
        ll int a[n+1];
        for(ll int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll int f=0,p=0,i=0;
        map<int,int>vis;
        while(i<n)
        {
           // cout<<i<<" "<<a[i]<<endl;
            if(a[i]==0)
            {
                i++;
                continue;
            }
            while(a[i]>0)
            {
                //cout<<a[i]<<" ";

                ll int val=lg(a[i],k);
                vis[val]++;
               // cout<<val<<" "<<pw(k,val)<<" "<<vis[val]<<endl;
                if(vis[val]>1)
                {
                    f=1;
                    break;
                }
                a[i]-=pw(k,val);
            }
            //cout<<endl;
            if(f)break;
            i++;
        }
        if(f)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

}
