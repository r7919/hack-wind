// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819414
#include<bits/stdc++.h>
using namespace std;

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {  
    ((cout << args << " "), ...);
}

#define ll long long
const ll MX = 10000000000000000;
vector<ll> pw;

bool check(ll cur){
    for (int i = pw.size() - 1; i >= 0; i--){
        if (pw[i] != -1 && cur >= pw[i]){
            cur -= pw[i];
            pw[i] = -1;
        }
    }
    return (cur == 0);
}

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	
    int T; scanf("%d", &T);
    while(T--){
        pw.clear();

        int n; ll k;
        scanf("%d%lld", &n, &k);

        ll tmp = 1;
        pw.push_back(tmp);
        while(tmp < MX){
            tmp *= k;
            pw.push_back(tmp);
        }

        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            scanf("%lld", &v[i]);
        
        // sort(v.begin(), v.end());

        bool ok = true;
        for (int i = 0; i < n; i++){
            if (v[i] == 0) continue;
            if (check(v[i])) continue;
            else {ok = false; break;}
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
