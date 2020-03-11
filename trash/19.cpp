// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819636
#include <iostream>
#include <bits/stdc++.h>
#define read(a) scanf("%d", &a)
#define read2(a,b) scanf("%d%d", &a, &b)
#define f(i,a,b) for (int i=a; i<b; i++)
#define F(i,a,b) for (int i=a; i<=b; i++)
#define fod(i,a,b) for (int i=a; i>=b; i--)
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef map<int,int> mii;
long long pow1(int a, int b)
{
    if (b==0) return 1;
    else if( b%2) return a*pow1(a,b/2)*pow(a,b/2);
    else return pow1(a,b/2)*pow(a,b/2);
}
int main()
{
    int t;
    cin>>t;
    while (t--){
        mii u;
        int n, k, flag=1;
        cin>>n>>k;
        long long A[n];
        f(i,0,n) cin>>A[i];
        f(i,0,n) {
            if (A[i]==0) continue;
            int cnt=0;
            while (A[i]!=0){
                if (A[i]%k==0) A[i]/=k, cnt++;
                else if ((A[i]-1)%k==0 && u[cnt]==0) u[cnt]=1, cnt++, A[i]=(A[i]-1)/k;
                else {flag=0; break;}
            }
        }
        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

