// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74089308
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        bool val=true;
        cin>>n>>k;
        if(n%2!=k%2)
            cout<<"NO\n";
        else
        {
            if(n>=k*k)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}

