// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72823004
#include <bits/stdc++.h>

using namespace std;
#define lint long long int
int main()
{
    lint t;
    cin>>t;
    while(t--) {
        lint n, k;
        cin>>n>>k;
        lint a[n];
        for(lint i=0;i<n;i++) {
            cin>>a[i];
        }
        lint f = 0;
        set<lint> s;
        for(lint i=0;i<n;i++) {
          // cout<<a[i] << " ";
            if(a[i] == 0){
                continue;
            }
            if (a[i]%k != 0 ) {
                a[i]--;
                if (a[i]%k !=0){
                    f=1;
                    break;
                }
             //   cout<<1<<endl;
                if (s.find(0) != s.end()) {
                    f=1;
                    break;
                }
                s.insert(0);
                if(a[i] == 0){
                    continue;
                } 
            } 
            lint x = 0, ans = 0;
            while(1) {
                x=0;
                while(a[i]%k == 0) {
                    x++;
                    a[i]/=k;
                }
                ans+=x;
                a[i]--;
                if (s.find(ans) != s.end()) {
                    f=1;
                    break;
                }
                s.insert(ans);
               // cout<<ans<<endl;
                if(a[i] == 0) {
                    break;
                } else {
                    if (a[i] % k != 0){
                        f=1;
                        break;
                    }
                }
            } 
            if(f==1){
                break;
            }
         //   cout<<endl; 
        }
        if(f == 1){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}

