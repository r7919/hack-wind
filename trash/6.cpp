// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820352
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long int k;
        cin>>n>>k;
        long long int m=0;
        long long int e=1;
        long long int a[31];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        bool z=0;
        for(int i=0;i<n;i++)
        {
            for(int o=0;a[i]!=0;o++)
            {
                if(a[i]%k==0)
                {
                    a[i]=a[i]/k;
                }
                else if(a[i]%k==1)
                {
                    if(m&(e<<o))
                    {
                        z=1;
                        break;
                    }
                    else
                    {
                        m|=(e<<o);
                        a[i]=(a[i]-1)/k;
                    }
                }
                else
                {
                    z=1;
                    break;
                }
            }
            if(z)break;
        }
        if(z)cout<<"NO\n";
        else cout<<"YES\n";
    }
}

