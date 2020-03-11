// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72817869
#include<bits/stdc++.h>
using namespace std;

int main()
{
      int t,i,j;
      cin>>t;
      while(t--){
            int n;
            long long int k;
            cin>>n>>k;
            long long int ara[n];
            for(i=0;i<n;i++) cin>>ara[i];
            bool is=true;
            while(1){
                  int cnt=0;
                  int x=0;
                  for(i=0;i<n;i++){
                        if(ara[i]%k==1){
                              x++;
                              ara[i]--;
                              ara[i]/=k;
                        }
                        else if(ara[i]==0) cnt++;
                        else if(ara[i]%k==0){
                              ara[i]/=k;
                        }
                        else{
                              is=false;
                              break;
                        }
                  }
                  if(x>1) is=false;
                  if(cnt==n) break;
                  if(!is) break;
            }
            if(!is) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
      }
      return 0;
}

