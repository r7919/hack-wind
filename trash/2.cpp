// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72816868
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int  main() {
    std::ios::sync_with_stdio(false);
   int t ; cin >> t; 
   while (t--){
       long long  n, k; cin >> n>>k;
       vector <long long >v;
       for (int i = 0; i < n; i++){long long  a; cin >> a; v.push_back(a);}
       map <long long  , bool>map; 
       bool f = false;
       for (int i = 0; i < n ; i++){
           long long  cnt =0;
           f = false;
           while (v[i]>0){
               if (v[i]%k==0){v[i]/=k; cnt++;}
               else if (v[i]%k==1){
                   if (map[cnt]){f=1; break;}
                   else{map[cnt]=1; v[i]--;}
               }
               else { f =1;break;}
           }
           if (f)break;
       }
       if(f){cout << "NO\n"; continue;}
       cout << "YES\n";
   }
}
