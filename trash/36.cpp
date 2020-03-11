// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72822384
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define intb INT_MAX
#define ints INT_MIN
#define pb push_back
#define pf push_front
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define bin binary_search
#define vmin *min_element
#define vmax *max_element
#define mod 998244353
#define pi pair<ll,ll>
#define mp make_pair
#define print(arr,a,b) for(ll i=a;i<=b;i++) cout<<arr[i]<<" "; cout<<endl;
#define intialize(arr,a,b) for(ll i=a;i<=b;i++) arr[i]=0;
struct sans
{
	ll t1;
    ll t2;
};

bool func(sans s1,sans s2)
{
	return s1.t1<s2.t1;
}

// void dfs(ll start)
// {
// //	ll count=0,flag=0;
// 	stack<int>s1;
// 	s1.push(start);
// 	while(!s1.empty())
// 	{
// 		ll qw=s1.top();
// 		if(v1[qw].size()==1 && qw!=start)
// 		{
// 			cout<<"leaf:"<<qw<<endl;
// 			s1.pop();
// 		}
// 		if(stat[qw]==1)
// 		{
// 			cout<<"Element:"<<qw<<endl;
// 			s1.pop();
// 		}
// 		else
// 		{
// 			for(ll i=0;i<v1[qw].size();i++)
// 			{
// 				if(stat[v1[qw][i]]==0)
// 				{
// 					s1.push(v1[qw][i]);
// 				}
// 			}
// 			stat[qw]=1;
 
// 		}
// 	}
// }

// <---------Write your code here--------->
map<pi,ll>m1;
ll a1[2*100000+1],b1[2*100000+1];
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,qw,flag=0;
		cin>>n>>qw;
		intialize(a1,0,60);
		for(ll i=1;i<=n;i++)
		{
			ll w;
			cin>>w;
			vector<ll>v1;
			ll count=0;
			while(w!=0 && flag==0)
			{
				ll rem=w%qw;
				w=w/qw;
				if(rem>1)
				{
					flag=1;
					break;
				}
				v1.pb(rem);
				if(rem==1)a1[count]++;
				if(a1[count]>=2)
				{
					flag=1;
					break;
				}
				count++;
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
