// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74082711
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--){
      long long n,k;
      cin>>n>>k;
      
      if(n%2==0&&k%2!=0)
      {
          cout<<"NO"<<endl;
          continue;
      }
      if(n%2!=0&&k%2==0)
      {
          cout<<"NO"<<endl;
          continue;
      }
      long long p=k*k;
      if(n>=p)
      {
          cout<<"YES"<<endl;
          continue;
      }
      else
      cout<<"NO"<<endl;
     
      
      
      
  }
   return 0;
}
