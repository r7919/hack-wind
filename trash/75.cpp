// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72825635
#include <bits/stdc++.h>

using namespace std;

const int mx=1e5+10;
long long int t,n,k,a,bigpow[33];
map <long long int,bool> used;
bool c=1;

long long int power(long long int x,long long int y){
    long long int r=1;
    for(int i=0;i<y;i++)
        r*=x;
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a;
            while(a)
            for(int p=0;p>-1;p++)
                if(power(k,p)>a){
                    if(used[p-1])
                        c=0;
                    used[p-1]=1;
                    a-=power(k,p-1);
                    break;
                }
        }

        cout<<(c ? "YES\n":"NO\n");
        used.clear();
        c=1;
	}

	return 0;
}
/*


*/

