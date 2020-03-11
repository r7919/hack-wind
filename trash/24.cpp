// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821801
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e2+10;
int vis[maxn];
vector<long long >q;
int main(){
    int T;
    cin >> T;
    while(T--){
        memset(vis,0,sizeof(vis));
        int n,k;
        int flag = 1;
        cin >> n >> k;
        for(int i = 0;i<n;i++){
            long long  temp;
            cin >> temp;
            if(temp ==0)continue;
            int j = 0;
            while(temp && flag){
                int gg = temp % k;
                if(gg == 0){
                    temp/=k;
                    j++;
                    continue;
                }
                else if(gg == 1 && vis[j] == 0){
                    vis[j] = 1;
                    temp/=k;
                    j++;
                    continue;
                }
                else {
                    flag = 0;
                }
            }
        }
        if(flag)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
