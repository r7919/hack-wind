// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72818264
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>

#define int long long
using namespace std;
const int maxn = 1e6 + 7;
int a[maxn];
bool vis[maxn];

signed main(){
    int cas;
    scanf("%lld", &cas);
    while (cas --){
        memset(vis, false, sizeof (vis));
        
        int n, k;
        scanf("%lld%lld", &n, &k);
        for (int i=1; i<=n; i++) scanf("%lld", &a[i]);
        bool flag = false;
        
        for (int i=1; i<=n; i++){
            if (!a[i]) continue;
            else if (a[i] == 1){
                if (vis[0]) {
                    flag = true; break;
                }
                vis[0] = true;
            }else {
                int tmp = a[i], p = 0;
                while (tmp){
                    int yu = tmp % k;
                    tmp /= k;
                    if (yu != 1 && yu){
                        flag = true; break;
                    }else if (!yu) {
                        p++; continue;
                    }else{
                        if (vis[p]){
                            flag = true; break;
                        }
                        vis[p] = true;
                        p++;
                    }
                }
            }
            
            if (flag) break;
        }
//
//        for (int j=0; j<=6; j++){
//            if (vis[j]) printf("%d ", j);
//        }
//        printf("\n");
        
        if (flag) printf("NO\n");
        else printf("YES\n");
    }
    
    return 0;
}

