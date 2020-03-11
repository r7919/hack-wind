// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820132
#include<bits/stdc++.h>
#define ll long long
#define MAXN 400005
#define mod 1000000007
#define INF 0x3f3f3f3f
#define ld long double
using namespace std;
ll a[35];

int main(){
    ios::sync_with_stdio(false);
    #define int ll
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll b[35][100]={0};
        bool y=1;
        int num1=-1;
        for(int i=0;i<n;i++){
            int tp=a[i];
            int tpp=0;
            while(tp>0){
                if(tp%k==1){
                    b[i][tpp]+=1;
                }
                else if(tp%k==0){

                }
                else{
                    y=0;break;
                }
                tpp+=1;
                tp/=k;
            }
            if(!y)break;
        }
        if(!y){
            cout<<"NO"<<endl;continue;
        }
        for(int i=0;i<100;i++){
                bool yy=0;
            for(int j=0;j<n;j++){

                if(!yy&&b[j][i]==1){
                    yy=1;
                }
                else if(b[j][i]==1){
                    y=0;break;
                }
            }

            if(!y){
               break;
            }
        }
        if(!y){
            cout<<"NO"<<endl;continue;
        }
        else{
            cout<<"YES"<<endl;
        }

    }


    return 0;
}

