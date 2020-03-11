// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821085
#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f,arr[212345],pd=1,ct,t,freq[223],mn,ans,mx;
string m,p,s;
bool k;
int main() {
	cin >> t;
	while (t--){
		k = false;
		cin >> a >> b;
		vector <long long > v;
		for(int i = 0 ;  ; i++){
			if(pow(b,i)>10e16) break;
			pd = pow(b,i);
			v.push_back(pd);
		}
		for(int i= 0 ; i<a ; i++){
			cin >> arr[i];
		}
		sort(arr,arr+a);
		for(int i = 0 ; i<a;i++){
			if(arr[i] == 0)
			continue;
			else{
				for(int j=0 ; j<v.size() ; j++){
					if(arr[i] == v[j]){
					v[j] = 0;
					arr[i]=0;
					break;
					}
				}
				for(int j=v.size()-1 ; j>=0 ; j--){
					 if(arr[i] >= v[j] && v[j]!=0){
						arr[i] -= v[j];
						v[j] = 0;
						j++;
					}
				}
			}
		}
		for(int i=0 ; i<a ; i++){
			if(arr[i] !=0){
				k=true;
			}
		}
		if(!k) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
