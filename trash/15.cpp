// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72818185
#include<bits/stdc++.h>
using namespace std;
long long t,n,k,a[200];
long long curr,bl,cnt;
bool u;
bool viz[200];

int main(){

    cin>>t;
    while(t--){
        cin>>n>>k;
        u = 0;
        for(int i = 0;i<n;i++)
            cin>>a[i];
        for(int i = 0;i<100;i++)
            viz[i] = 0;
        for(int i = 0;i<n;i++){
            curr = a[i];
            cnt = 0;
            while(curr){
                bl = curr%k;
                curr/=k;
                if(bl == 0){
                    cnt++;

                }
                else{
                    if(bl == 1){
                        if(viz[cnt] == 0){
                            viz[cnt] = 1;
                        }
                        else {
                            u = 1;
                            break;
                        }
                    }
                    else{
                        u = 1;
                        break;
                    }
                    cnt++;
                }

            }
            if(u){
                cout<<"NO\n";
                break;
            }
        }
        if(!u){
            cout<<"YES\n";
        }
    }


    return 0;
}

