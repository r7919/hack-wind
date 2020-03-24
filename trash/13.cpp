// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74082843
#include<bits/stdc++.h>
using namespace std;
#define in freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define noddy in out
#define rep(i,n) for(ll i=0;i<n;i++)
#define reep(i,n) for(ll i=n-1;i>=0;i--)
#define vec(i, a)  for( auto i=a.begin();i != a.end(); ++i)
#define pb(i) vv.push_back()
typedef long long ll;

bool is_match(string s1,string s2)
{
    int pos=0;
    for(int i=0;i<s2.length();i++)
    {
        if(s1[pos]==s2[i])
            pos++;
    }
    if(pos==s1.length())
        return true;
    else
        return false;
}

ll digit_sum(ll n)
{
    return n==0 ? 0: n%10 + digit_sum(n/10);
}
ll lcm12(ll a, ll b)  
 {  
    return (a*b)/__gcd(a, b);  
 }


bool palindrome(string str) 
{ 
    int len = str.length(); 
    for (int i = 0; i < len/2; i++ ) 
        if (str[i] != str[len-i-1]) 
            return false; 
  
    return true; 
} 

 int main(int argc, char const *argv[])
{
    #ifndef ONLINE_JUDGE
        noddy
    #endif
        ll hash[1001]={0}; map<char,ll>mp; pair<ll,ll>pa,pa2;vector<ll>vv;set<ll>s;
        ll n,m,t,k=0,x=0,y=0,z=0,d=0,e=0,cnt=0,cnt0=0,sum=0,sum1=0,sum0=0,flag=0,flag1=0,flag2=0,flag3=0,a1,a2,a3,b1,b2,b3,cnt1=0,cnt2=0,cnt3=0;
        cin>>t;
        while(t--)
        {
            cin>>n>>k;
            ll sq  = k*k;

            if(n<sq || ((n%2==0) && (k&1)) || (n&1 && (k%2==0)))
               cout<<"NO\n";
            else cout<<"YES\n"; 
            
            

            

        }   









    return 0;
}

