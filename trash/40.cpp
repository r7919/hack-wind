// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72816616
#include <bits/stdc++.h>

using namespace std;

const int N=100;

long long bits[70][70];
// int arr[N];

int main(){
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        for(int i=0;i<70;i++){
            for(int j=0;j<70;j++){
                bits[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
           long long a;
           cin>>a;
           int x=0;
           while(a){
               bits[i][x++]=a%k;
               a/=k;
           }
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<63;j++){
                if(bits[i][j]>1){
                    flag=1;
                    break;
                }
            }
        }
        for(int j=0;j<63;j++){
            int count=0;
            for(int i=1;i<=n;i++){
                if(bits[i][j])count++;
            }
            if(count>1){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"NO"<<"\n";
        }
        else {
            cout<<"YES"<<"\n";
        }
    }

    return 0;
}
