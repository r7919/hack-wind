// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72822796
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool base(ll num, ll b, bool ranks[100]){
    if(num == 0) return true;
    int count = -1;
    while(num != 0){
        count++;
        if(num % b == 0){ num/=b; continue; }
        if(num % b == 1 && ranks[count] == true) return false;
        if(num % b == 1){ num/=b; ranks[count] = true; continue;}
        else return false;

    }
    return true;
}

int main(){
    int t;
    cin>>t;
    for(int i =0; i< t ;i++){
        ll n, k;
        bool ranks[100];
        for(int j=0; j<100; j++) ranks[j] = false;
        cin>>n>>k;
        vector<ll> v;
        ll sum = 0;
        for(int j=0; j<n; j++){
            ll temp;
            cin>>temp;
            v.push_back(temp);
            sum+= temp;
        }
        bool answer = true;
        for( auto el : v){
            answer &= base(el, k, ranks);
        }
        if(answer)  cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
