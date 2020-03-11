// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72814063
#include<bits/stdc++.h>
long long tmp;
long long n,k;
int notation[64];
int solve(){
    memset(notation,0,sizeof(int)*64);
    scanf("%lld %lld",&n,&k);
    bool right=true;
    for(int a=0;a<n;a++){
        scanf("%lld",&tmp);
        int b=0;
        while(tmp>0){
            if(tmp%k==1){
                notation[b]++;
                if(notation[b]>1){
                    right=false;
                }
            }else{
                if(tmp%k!=0){
                    right=false;
                }
            }
            tmp=tmp/k;
            b++;
        }
        
    }
    if(right)printf("YES\n");
    else printf("NO\n");
    
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int a=0;a<t;a++){
        solve();
    }
}
