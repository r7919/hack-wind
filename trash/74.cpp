// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72817681
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1)
#define mod 1000000009
#define all(x) x.begin(), x.end()
using namespace std;

bool check(ll x, set<ll> &s){
    while(x > 0 && s.size() > 0){
        auto pos = s.lower_bound(x);
        if(*pos == x){
            s.erase(x);
            return true;
        }
        pos--;
        if(*pos > x){
            return false;
        }
        x -= (*pos);
        s.erase(*pos);
    }
    return (x == 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        set<ll> powers;
        bool f = true;
        ll val = 1;
        while(val <= a[n - 1]){
            powers.insert(val);
            val = val * k;
        }
        for(int i= n - 1; i >= 0; i--){
            if(check(a[i], powers) == false){
                f = false;
                break;
            }
        }
        if(f){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << endl;
    }
}



