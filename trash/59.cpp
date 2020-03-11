// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72822547
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <algorithm>

#define ullint unsigned long long int
#define llint long long int

using namespace std;

int main(){
	int T;cin>>T;
	for(int t=0;t<T;t++){
		int n,k;cin>>n>>k;
		vector<ullint> arr;
		unordered_map<int,bool> umap;
		unordered_map<int,bool>::iterator uitr;
		bool answer=true;
		for(int i=0;i<n;i++){
			ullint temp;cin>>temp;
			//cout<<"temp:"<<temp<<endl;
			//Now checkin the number representaion in basis of k
			ullint power=0;
			while(temp>0){
				int rem=temp%k;
				temp=temp/k;
				//cout<<"power:"<<power<<" rem:"<<rem<<endl<<endl;
				if(rem>1){
					answer=false;
					break;
				}
				else if(rem==0){
					power++;
					continue;
				}
				//Now we have to see no other guy uses this power
				uitr=umap.find(power);
				if(uitr==umap.end()){
					//This means that this power dont exist
					umap[power]=true;
				}
				else{
					answer=false;
					break;
				}

				//incrementing the power
				power++;
			}
		}
		if(answer==true){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
