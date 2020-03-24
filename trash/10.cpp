// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74082799
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define int long long
#define endl "\n"
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fr(a,b,c) for(int a=b; a<c; a++)
#define frr(a,b,c) for(int a=b;a>=c;a--)
#define pb push_back
#define pii pair<int,int>
#define R(a) ll a; cin >> a;
typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
#define RA(a, n) ll a[(n) + 1] = {}; fr(i, 1, (n)+1) {cin >> a[i];}
#define RM(a, n, m) int a[n + 1][m + 1] = {}; fr(i, 1, n+1) {fr(j, 1, m+1) cin >> a[i][j];}
#define reset(X) memset(X, 0, sizeof(X))
using vi=vector<int>;
const int inf = 1e18;
const int mod=998244353;

int n;
int ax,ay,bx,by,cx,cy;


	signed main(){
	
		   int t=1;
		   cin>>t;
		   while(t--)
		   {
		   		int k;
		 cin>>n>>k;
		 if(((n%2==0&&k%2==0)||(n%2==1&&k%2==1))&&k*k<=n)cout<<"YES"<<endl;
		 else cout<<"NO"<<endl;

		


		}
          
      }
