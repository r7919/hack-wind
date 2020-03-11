// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72817967
#include<bits/stdc++.h>
#define LL long long
#define ms(s) memset(s, 0, sizeof(s))
using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        LL n, k;
        cin >> n >> k;
        LL tt = 1;
        map<LL, LL> m1;
        LL d = pow(10, 16);
        vector<LL> vec;
        //cout << "ok" << endl;
        while(tt <= d) {
            vec.push_back(tt);
            m1[tt] = 0;
            tt *= k;
        } 
        sort(vec.begin(), vec.end(), greater<LL>());
        //cout << "ok" << endl;
        bool flag = false;
        for(int i = 0; i < n; i++) {
            LL x;
            cin >> x;
            while(x) {
                LL temp = lower_bound(vec.begin(), vec.end(), x, greater<LL>()) - vec.begin();
                // cout << vec[temp] << endl;
                if(!m1.count(vec[temp]) || m1[vec[temp]] == 1) {
                    flag = true;
                    break;
                } 
                m1[vec[temp]]++;
                x -= vec[temp];
            }
        }
        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
