// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72816987
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
ll mod=1000000007;


int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);

ll t;
cin>>t;
while(t--)
{


ll n,k;
cin>>n>>k;

ll a[n],i;

for(i=0;i<n;i++)
cin>>a[i];

map<ll,ll>mp;

for(i=0;i<n;i++)
{
ll val=a[i];
ll ind=0;

  while(val!=0)
  {
    mp[ind]+=val%k;
    val/=k;
    ind++;
  }

}


ll sw=0;

for(auto it=mp.begin();it!=mp.end();it++)
{
  if((it->second)>1)
   {
     sw=1;
      break;
   }

}

if(sw==1)
cout<<"NO"<<endl;
else
cout<<"YES"<<endl;
}
return 0;
}


