// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72819978
///The Goldbach Conjecture is a yet unproven conjecture stating that every even
///integer greater than two is the sum of two prime numbers.
///The conjecture has been tested up to 400,000,000,000,000.
/*

The lessons to learn are:
1. Read problem statement more carefully,
2. It's okay to waste another minute to check everything once more before submission,
3. Don't just wait for submission result, re-read the problem statement and your code once more.

*/
#include<bits/stdc++.h>
#define rep(i , j , n) for(ll i = j ; i <= n ; i++)
#define per(i , j , n) for(ll i = j ; i >= n ; i--)
#define ll long long
#define le length
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pll pair<long long ,long long >
#define ppll pair < pll , pll >
#define MOD 1000000007
#define vl vector<ll>
#define trvl(c,it) for(vl::iterator it=(c).begin();it!=(c).end();it++)
#define mll map<ll,ll>
#define sl set<ll>
#define msl multiset<ll>
#define trsl(c,it) for(sl::iterator it=(c).begin();it!=(c).end();it++)
#define trmsl(c,it) for(msl::iterator it=(c).begin();it!=(c).end();it++)
#define trmll(c,it) for(mll::iterator it=(c).begin();it!=(c).end();it++)
//#define pi 3.1415926536
const ll INF=(1LL<<60)-1;
const int N=200033;
using namespace std;
ll power(ll x,ll y)
{
    ll res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % MOD;
         y = y>>1;
        x = (x*x) % MOD;
    }
    return res;
}
ll BINARY_SEARCH(ll dp[] , ll n , ll key) {
    ll s = 1;
    ll e = n;
    while(s <= e) {
        ll mid = (s + e) / 2;
        if(dp[mid] == key) return mid;
        else if (dp[mid] > key) e = mid - 1;
        else s = mid + 1;
    }
    return -1;
}
string CONVERT_TO_BINARY(ll s) {
    string res = "";
    while(s != 0) {
        res += (char)('0' + s % 2);
        s /= 2;
    }
    reverse(res.begin() , res.end());
    return res;
}
bool PALIN(string s) {
    ll i = 0;
    ll j = s.le() - 1;
    while(i <= j) {
        if(s[i] != s[j]) return false;
        j-- , i++;
    }
    return true;
}
ll STOI(string s) {
    ll num = 0;
    ll po = 1;
    per(i , s.le() - 1 , 0) {
        num += po * (s[i] - '0');
        po *= 10;
    }
    return num;
}
ll modInverse(ll a,ll m){
return power(a,m-2);
}
// Function to find longest substring
// having count of 1s more than count
// of 0s.
int findLongestSub(string bin)
{
    int n = bin.length(), i;

    // To store sum.
    int sum = 0;

    // To store first occurrence of each
    // sum value.
    unordered_map<int, int> prevSum;

    // To store maximum length.
    int maxlen = 0;

    // To store current substring length.
    int currlen;

    for (i = 0; i < n; i++) {

        // Add 1 if current character is 1
        // else subtract 1.
        if (bin[i] == '1')
            sum++;
        else
            sum--;

        // If sum is positive, then maximum
        // length substring is bin[0..i]
        if (sum > 0) {
            maxlen = i + 1;
        }

        // If sum is negative, then maximum
        // length substring is bin[j+1..i], where
        // sum of substring bin[0..j] is sum-1.
        else if (sum <= 0) {
            if (prevSum.find(sum - 1) != prevSum.end()) {
                currlen = i - prevSum[sum - 1];
                maxlen = max(maxlen, currlen);
            }
        }

        // Make entry for this sum value in hash
        // table if this value is not present.
        if (prevSum.find(sum) == prevSum.end())
            prevSum[sum] = i;
    }

    return maxlen;
}
void extendedEuclid(int A, int B) {
    int d,x,y;
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
void sieve(int N) {
        bool isPrime[N+1];
        for(int i = 0; i <= N;++i) {
            isPrime[i] = true;
        }
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i <= N; ++i) {
             if(isPrime[i] == true) {                    //Mark all the multiples of i as composite numbers
                 for(int j = i * i; j <= N ;j += i)
                     isPrime[j] = false;
            }
        }
    }
    void minpri(ll n){
       int minPrime[10000+ 1];
for (int i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) {         //If i is prime
        for (int j = i * i; j <= n; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
            }
        }
    }
}
for (int i = 2; i <= n; ++i) {
    if (minPrime[i] == 0) {
        minPrime[i] = i;
    }
}

    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
  ///send res back

    }

vl prefix_KMP(string &s){
vl pi;
pi[0]=0;
rep(i,1,s.length()-1){
ll j=pi[i-1];
while(j>0&&s[i]!=s[j]){
    j=pi[j-1];
}
if(s[i]==s[j]){
    j++;
}
pi[i]=j;

}
return pi;
}
//ll arr[50000][50000];
pair<bool,vector<ll>>po(ll n,ll k){
    vector<ll>res;
    string s;
    ll cnt=0;
    bool flag=1;
while(n>0){
    ll rem=n%k;
    if(rem==1){
        res.push_back(cnt);
    }
    else if(rem!=0){
        flag=0;
        break;
    }
    cnt++;
    n/=k;
}
return {flag,res};
}
int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
   // freopen("input_file_name.in","r",stdin);
   // freopen("output_file_name.out","w",stdout);
ll t=1;
cin>>t;
while(t--){
ll n,k;
cin>>n>>k;
ll a[n+1];

rep(i,0,n-1)cin>>a[i];
ll v[n+1]={0};
vector<ll>ans;
set<ll>st;
bool flag=1;
for(ll i=0;i<n;i++){
    if(a[i]==0)continue;
    pair<bool,vector<ll>>res=po(a[i],k);
    if(res.first==false){
        flag=0;
        break;
    }
    for(auto j:res.second){
        ans.push_back(j);
        st.insert(j);
    }
}
if(flag==0){
    cout<<"NO"<<endl;
    continue;
}
if(st.size()!=ans.size()){
    cout<<"NO"<<endl;
}
else cout<<"YES"<<endl;
}


}



















/*
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli n, tmp;
int idx[50];
int main(){
    lli ans = 0; cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> tmp;
        for(int j=0; j<=31; ++j){
            lli pw = 1l << j;
            if(tmp & pw){
                ans += pw * i;
                idx[j] = i;
            } else if(idx[j]){
                ans += pw * idx[j];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
*/


