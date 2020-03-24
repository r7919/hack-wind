// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74082916
// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;cin>>t;while(t--){
    int n,k;
    cin >> n >> k;
    if(k > n)
    {
        cout<<"NO";
    }
    else
    {
       if((k==1 && (n&1)) || ((k%2==0) && (n%2==0)) || ((k&1) && (n&1))){
           (k<=sqrt(n)) ? cout<<"YES": cout<<"NO";

        }
       else{
           cout<<"NO";
       }
    }
    cout<<endl;
    }
    return 0;
}
