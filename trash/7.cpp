// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74075551
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);


int32_t main()
{
    IO;
    int t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        int n,k;
        cin>>n>>k;
        if(n%2==k%2 && n>=k*k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
