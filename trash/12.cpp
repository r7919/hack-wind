// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74075115
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        scanf("%lld%lld",&n,&k);
        if((n%2==0&&k%2==0)||(n%2!=0&&k%2!=0)){
            if(n>=k*k)
            printf("YES\n");
            else
            printf("NO\n");
        }else{
            printf("NO\n");
        }
    }

}

