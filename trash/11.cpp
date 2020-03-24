// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74082594
#include<bits/stdc++.h> 
#define ll                 long long int                            
#define ra                 return a;                                          
#define pb                 push_back                                                     
#define sti                stack<ll>
#define spi                stack<pair<ll,ll>>
#define S                  second
#define msi                map<string,ll >
#define msi                map<string,ll >
#define mii                map<ll ,ll >
#define dbg(x)             { cerr<<#x<<": "<<x<< endl; }
#define dbg2(x,y)          { cerr<<#x<<": "<<x<<" , "<<#y<<": "<<y<<endl; }
#define dbg3(x,y,z)        { cerr<<#x<<": "<<x<<" , "<<#y<<": "<<y<<" , "<<#z<<": "<<z<<endl; }
#define mis                map<ll , string>
#define rep(i,a,b)         for(ll i=a;i<b;i++)
#define mpi                map<pair<ll ,ll >,ll >                                                
#define pii                pair<ll ,ll >
#define ppb                pop_back
#define F                  first 
#define vi                 vector<ll >
#define vii                vector<pair<ll , ll > >
#define pqi                priority_queue<ll>
#define si                 set <ll>
#define vs                 vector<string>
#define all(a)             (a).begin(),(a).end()
#define sz(x)              (ll )x.size()
#define hell               1000000007
#define bs                 binary_search
#define mp                 make_pair
#define qi                 queue<ll>
#define qs                 queue<string>
#define qpi                queue<pair<ll,ll>>
#define qps                queue<pair<ll,string>> 
#define inf                1e18L+1
#define endl               '\n' 
#define itr(a,it)          for(typeof(a.begin()) it=a.begin();it!=a.end();it++)// This will produce const_iterator for const object and normal iterator for non-const object
#define ss                 set<string>
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define N  300005
int main()
{
	FAST
	ll t;cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		if(k%2==0)
		{
			if(n%2==0&&(k*k<=n))
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
		else
		{
			if(n%2==1&&k*k<=n)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;}
		}return 0;
		}
