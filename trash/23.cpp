// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72817739
#include<iostream>
#include<cstring>

using namespace std;

#define INF 1e10+5
#define MAXN 105
#define MINN -105
typedef long long int LL;
LL a[MAXN],b[MAXN];
LL n,k;
bool ok;
void check(LL& i,LL j,LL cur)
{
    if(cur>i)return;
    check(i,j+1,cur*k);
    if(cur<=i)
    {
        i-=cur;
        b[j]++;
        if(b[j]>=2){ok=0;return;}
    }
}

void solve()
{
    memset(b,0,sizeof(b));
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        ok=1;
        if(!a[i])continue;
        check(a[i],0,1);
        if(a[i])ok=0;
        if(!ok)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}


int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}

