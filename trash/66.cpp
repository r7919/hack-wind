// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72818590
#include <bits/stdc++.h>
using namespace std;
 
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ll long long int
#define endl "\n"
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define pb push_back
#define PI 3.1415926535897932384626
#define keep_unique(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());

// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define int long long 
bool test[100];

int power(int x,int y)
{
    int res = 1;
    while(y)
    {
        if(y&1) res = res*x;
        y /= 2;
        x = x*x;
    }
    return res;
}

int check(int x,int k)
{
    for(int i=0;i<100;i++)
    {
        if(power(k,i)>x)
        {
            //cout<<x<<" "<<power(k,i)<<" "<<i<<"\n";
            return i-1;
        }
    }
}

void solveFunction()
{
    for(int i=0;i<100;i++) test[i] = 1;
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(all(v));
    for(auto i:v)
    {
        if(i==0) continue;
        int temp = i;
        while(temp>0)
        {
           // cout<<temp<<" "<<i<<"\n";
            int pw = check(temp,k);
            //cout<<pw<<"\n";
            if(!test[pw])
            {
                cout<<"NO\n";
                return ;
            }
            test[pw] = 0;
            //cout<<temp<<" "<<power(k,pw)<<"\n";
            temp -= power(k,pw);
            //cout<<temp<<"\n";
        }
    }
    cout<<"YES\n";
}
 
main()
{
    speed;
    int t = 1;
    cin>>t;
    while(t--)
    {
        solveFunction();
    }
}
