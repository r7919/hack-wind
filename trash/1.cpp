// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74075101
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define ll long long
#define pii pair<int , int>
#define pli pair<ll , int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define N
#define p 307LL
#define mod 1000000007LL

int main(){

    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n>>k;
        if( n < k*k)
            cout <<"NO\n";
        else if( (n - (k*k)) % 2){
            cout <<"NO\n";
        }else cout <<"YES\n";
    }
    return 0;
}


