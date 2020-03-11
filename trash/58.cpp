// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819076
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4;
ll a[10000];
ll c[1010];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        memset(c,0,sizeof c);
        int n,k;
        ll maxn=0;
        cin>>n>>k;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i])
                flag=1;
        }
        if(flag)
        {
            memset(c,0,sizeof c);
            for(int i=0;i<n;i++)
            {
                int j=0;
                while(a[i])
                {
                    c[j++]+=a[i]%k;
                    a[i]/=k;
                }
            }
            int xx=1;
          for(int i=0;i<300;i++)
			if(c[i]>1)
				xx=0;
		if(xx)
            cout<<"YES"<<endl;
		else
            cout<<"NO"<<endl;

        }
        else
            cout<<"YES"<<endl;



    }
    return 0;

}

