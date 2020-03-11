// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72823187
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(),v.end()
#define mem(arr) memset(arr,0,sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9+7;
const int INF = 1e18;
const int N = 1e6 + 20;
vector<int> g[N];
vector<int> vis(N);
vector<int> convert(int a, int k){
    vector<int> v;
    while(a){
        v.pb(a % k);
        a = a / k;
    }
    return v;
}
int32_t  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    cin >> tc;
    while(tc--){
        int n, k;
        cin >> n >> k;
        int a[n];
        int mx = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        // int p = 1;
        // vector<int> v;
        // int i = 0;
        // int bit[100];
        // mem(bit);
        // while(p <= mx){
        //     v.pb(p);
        //     p = p * k;
        //     bit[i] = 1;
        // }
        int flag = 0;
        map<int, int> seen;
        for(int i = 0; i < n; i++){
            vector<int> v = convert(a[i], k);
            for(int i : v){
                if(i > 1){
                    flag = 1;
                    break;
                }
                // cout << i << ' ';
            }
            // cout << '\n';
            if(flag){
                break;
            }
            for(int i = 0; i < (int)v.size(); i++){
                if(v[i]){
                    if(seen[i]){
                        flag = 1;
                        break;
                    }else{
                        seen[i] = 1;
                    }
                }
            }
        }
        if(flag){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    } 
}
