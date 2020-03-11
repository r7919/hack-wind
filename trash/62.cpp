// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72824158
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
	if(a.second == b.second){
		return (a.first < b.first);
	} 
    return (a.second < b.second); 
} 
int main(){
	ll t;
	cin >> t;

	while(t--){
		ll n,k;
		cin >> n >> k;

		vector<ll>v(n);
		for(ll i=0;i<n;i++){
			cin >> v[i];
		}

		vector<pair<ll,ll>>ans;
		for(ll i=0;i<n;i++){
			ll m=0;
			while(v[i]!=0){
				if(v[i]%k != 0){
					ans.push_back(make_pair(v[i]%k,m));
				}
				v[i]=v[i]/k;
				m++;
			}
		}
		sort(ans.begin(),ans.end(),sortbysec);
		// for(ll i=0;i<ans.size();i++){
		// 	cout << ans[i].first << " " << ans[i].second << "\n";
		// }
		
		int flag = 1;
		if(ans.size()==0){
			cout << "YES\n";
			continue;
		}
		else{
			for(ll i=0;i<ans.size();i++){
				if(ans[i].first != 1){
					flag = 0;
					break;
				}
			}
			for(ll i=1;i<ans.size();i++){
				if(ans[i].second == ans[i-1].second){
					flag = 0;
					break;
				}
			}
		}

		if(flag == 1){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
