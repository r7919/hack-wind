// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72804347
#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int a[60];
long long b,k;
int main(){
    cin>>t;
    while (t--){
        cin>>n>>k;
        for (int i=0;i<60;i++) a[i]=0;
        for (int i=0;i<n;i++){
            cin>>b;
            int p=0;
            while (b!=0){
                a[p]+=(b%k);
                p++;b/=k;
            }
        }
        int t=0;
        for (int i=0;i<60;i++)
            if (a[i]>1) t=1;
        if (t==0) printf("YES\n");
            else printf("NO\n");
    }
}

