// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72817284
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;++i)
            cin>>a[i];
        int cnt0=0,cnt1=0;
        bool flag=true;
        while(true)
        {
            int cntZero=0;
            for(int i=0;i<n;++i)
            {
                if(a[i]==0)
                    cntZero++;
                if(a[i]%k==0)
                    cnt0++;
                else if(a[i]%k==1)
                    cnt1++;
                else
                {
                    flag=false;
                    break;
                }
                if(!flag)
                    break;
                a[i]/=k;
            }
            if(cnt1!=0&&cnt1!=1)
                flag=false;
            if(!flag) break;
            if(cntZero==n) break;
            cnt1=0;cnt0=0;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
