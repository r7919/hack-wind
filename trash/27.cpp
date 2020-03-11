// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820393
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void print(int a[], int n){
    for(ll i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void print(vector<int> a, int n){
    for(ll i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void disp(ll num, ll p, ll arr[]){
    int i=0;
    while (num != 0) {
        arr[i] = num % p;
        num = num / p;
        i++;
    }

}


int main() {
     int test;
     cin>>test;
     while(test--){
        ll n,k;
        cin>>n>>k;

        ll pw[100];
        for(int i=0;i<100;i++){
            pw[i]=1;
        }

        ll a[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int flag=0;

        for(int i=0;i<n;i++){
            ll arr[100];

            for(int i=0;i<100;i++){
               arr[i]=0;
            }

            disp(a[i],k,arr);

            for(int j=0;j<100;j++){
                if(arr[j]>1){
                    flag=1;
                    break;
                }
                else if(arr[j]==1){
                    if(pw[j]<=0){
                        flag=1;
                        break;
                    }
                    else{
                        pw[j]--;
                    }
                }
            }
        }


       if(flag==1){
           cout<<"NO"<<endl;
       }
       else{
           cout<<"YES"<<endl;
       }

     }


}

