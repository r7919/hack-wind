// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72824387
#include<bits/stdc++.h>
#define ll long long int
#define inf 100000000000000
using namespace std;
ll mod=1000000007;

bool isPower(ll x, ll y)
{

    ll res1 = log(y) / log(x);
    long double res2 = log(y) / log(x);


    return (res1 == res2);
}

ll power(ll x, ll y)
{
    ll res = 1;


    while (y > 0)
    {

        if (y & 1)
            res = (res*x);


        y = y>>1;
        x = (x*x) ;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        ll arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

       int brr[100]={0};
       int flag=0;
       for(int i=0;i<n;i++)
       {
           string s;

           ll aa=arr[i];

           while(aa)
           {
               ll md=aa%k;
               aa=aa/k;

               if(md>1)
               {
                   flag=1;
                   break;
               }
               if(md==0)
               {
                   s.push_back('0');
               }
               if(md==1)
               {
                   s.push_back('1');
               }

           }

           ll nn=s.size();
           for(int j=0;j<nn;j++)
           {
               //cout<<s[j]<<" ";

               if(s[j]=='1')
               {
                   brr[j]++;
                   if(brr[j]>1)
                   {
                       flag=1;
                       break;
                   }
               }
           }
           //cout<<endl;
           if(flag==1)
           {
               break;
           }
       }
       if(flag==0)
       {
           cout<<"YES"<<endl;
       }
       else
       {
           cout<<"NO"<<endl;
       }

    }
}

