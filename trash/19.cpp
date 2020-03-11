// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72817814
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t; cin>>t;
    while(t--)
    {
       int n; cin>>n;
       int k; cin>>k;
       ll a[n]; ll v[n]={0};
       for(int i=0;i<n;i++) cin>>a[i];
       
       int flag=1; unordered_map<ll,ll> um;
       for(int i=0;i<n;i++)
       {
           ll temp=a[i]; int p=0;
           while(temp>0)
           {
              ll r=temp%k;
              if(r>1){ flag=0; break;}
              else if(r==1) 
              {
                  if(um.find(p)==um.end()) um[p]=1;
                  else { flag=0; break;}
              }
              p++;
              temp/=k;
           }
           if(flag==0) break;
       }
       if(flag==0) cout<<"NO"<<endl;
       else cout<<"YES"<<endl;
    }
    
}
