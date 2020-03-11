// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821344
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,k,i;
        long long int b[200]={};
        cin>>n>>k;
        long long int a[n];
        int flag=1;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            long long int rem;
            list<long long int> l;
            while(a[i]>=k)
            {
                rem=a[i]%k;
                a[i]/=k;
                l.push_back(rem);
            }
            l.push_back(a[i]);
            long long int cnt=0;
            while(!l.empty())
            {
                if(l.front()==1)
                    b[cnt]++;
                else if(l.front()>0)
                    flag=0;
                l.pop_front();
                cnt++;
            }
        }
        if(flag==0)
        {
            cout<<"NO\n";
            continue;
        }
        for(i=0;i<200;i++)
        {
            if(b[i]>1)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

