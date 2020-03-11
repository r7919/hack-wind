// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821337
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecp;
#define MP make_pair
#define PB push_back
#define F first 
#define int long long 
#define S second
#define Runner_up ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(), v.end()
//-----------------------------------------------------------------------------------

signed main()
{	
	Runner_up
	int t; cin>>t;
	while(t--){
		int n, k; cin>>n>>k;
		int a[n];
		ll sum=0;
		vector <ll> v;
		for(int i=0; i<n; i++){
			cin>>a[i]; sum+=a[i];
		}
		sort(a, a+n);
		ll z=0;
		ll c=0; map < ll, ll> m;
		while(z < sum){
			z=pow(k, c);
			v.PB(z); c++; 
		}
		int flag=1;
		for(int i=0; i<n; i++){
			if(a[i]==0) continue;
			int ind=0;
			while(v[ind] < a[i]) ind++;
			if(v[ind] > a[i]) ind--;
			if(ind<0) {
				flag=0; break;
			}
			while(true){
				if(a[i]==0) break;
				while(v[ind] > a[i] && ind > 0 ) ind--;
				if(v[ind] > a[i]) {
					flag=0; break;
				}
				if(!m[v[ind]]) {
					a[i]-=v[ind];m[v[ind]]=1;
				}else{
					flag=0; break;
				}
			}
			if(flag==0) break;
		}
		for(int i=0; i<n; i++) {
			if(a[i]) {
			flag=0; break;
			}
		}
		if(flag) cout<<"YES"<<endl; else cout<<"NO"<<endl;
		
	}
	return 0;
}

