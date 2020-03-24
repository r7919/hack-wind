// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74075763
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const ll MAX = 2e18;

#define lcm(a,b)            ((a*b) / __gcd(a,b) )
#define gcd(a,b)            __gcd(a,b)
#define bug(a)              cerr << #a << " : " << a << endl;
#define pb                  push_back
#define ppb                 pop_back
#define mem(ar)             memset(ar,0,sizeof(ar));
#define srt(x)              sort(x.begin(),x.end());
#define FastRead            {ios_base::sync_with_stdio(false); cin.tie(0); }

#define for0(i,n)           for(int i=0; i<n; i++)
#define for1(i,n)           for(int i=1; i<=n; i++)
#define forS(i,s)           for(set<int>::iterator i=s.begin();i!=s.end();i++)

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n,k,sq;
        cin >> n >> k;
        sq=sqrt(n);
        if(n%2==0 && k%2==0 && sq>=k){
            cout << "YES" << endl;
        }
        else if(n%2==1 && k%2==1 && sq>=k ){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

