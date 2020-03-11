// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72818044
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 30 + 5;
int B[maxn][64];
int T, n, k;

int main(){
    cin >> T;
    while(T --){
        memset(B, 0, sizeof(B));
        cin >> n >> k;
        for(int i = 0; i < n; i ++){
            LL x;
            cin >> x;
            int j = 0;
            while(x){
                B[i][j] = x % k;
                x /= k, j ++;
            }
        }
        bool ok = 1;
        for(int j = 0; ok && j < 64; j ++){
            int cnt = 0;
            for(int i = 0; cnt < 2 && i < n; i ++) cnt += B[i][j];
            if(cnt >= 2) ok = 0;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
