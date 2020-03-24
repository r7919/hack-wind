// LILY SOURCE:  https://codeforces.com/contest/1327/submission/74067410
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <set>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#define ffor(i, a, b) for(int i = a; i<b; i++)

using namespace std;

typedef long long int ll;


int binarySearch(vector<int> &arr, int left, int right, ll x, bool is_left=false) {
    if(!is_left) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (x < arr[mid]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    else{
        while (left < right) {
            int mid = (left + right) / 2;
            if (x <= arr[mid]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
        if ((a*x) % m == 1)
            return x;
}


string reverseStr(string str)
{
    string result = str;
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(result[i], result[n - i - 1]);

    return result;
}

int parent[1000001];
int depth[1000001];

void make_set (int v) {
    parent[v] = v;
    depth[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (depth[a] < depth[b])
            swap (a, b);
        parent[b] = a;
        if (depth[a] == depth[b])
            ++depth[a];
    }
}


int tree[32];

void build (vector<ll> a, int v, int left, int right) {
    if (left == right)
        tree[v] = a[left];
    else {
        int tm = (left + right) / 2;
        build (a, v*2, left, tm);
        build (a, v*2+1, tm+1, right);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}

int get_max (int v, int left, int right, int l, int r) {
    if (l > r)
        return 0;
    if (l == left && r == right){
        return tree[v];
    }
    int tm = (left + right) / 2;
    return max(get_max(v * 2, left, tm, l, min(r, tm))
            , get_max(v * 2 + 1, tm + 1, right, max(l, tm + 1), r));

}

void update (int v, int left, int right, int pos, int new_val) {
    if (left == right)
        tree[v] = new_val;
    else {
        int tm = (left + right) / 2;
        if (pos <= tm)
            update (v*2, left, tm, pos, new_val);
        else
            update (v*2+1, tm+1, right, pos, new_val);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
}


void bfs(vector<int> g[], bool used[]){
    queue<int> queue;
    queue.push(1);
    used[1] = true;
    while(!queue.empty()){
        int u = queue.front();
        queue.pop();
        for(size_t i = 0; i<g[u].size(); ++i){
            int u = g[u][i];
            if(!used[u]){
                used[u] = true;
                queue.push(u);
            }
        }
    }
}

int binpow (int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

void reverse(int arr[], int n){
    ffor(i, 0, n/2) swap(arr[i], arr[n-1-i]);
}

vector<int> cifar(ll n){
    vector<int> ans;
    while(n){
        ans.push_back(n%10);
        n = n/10;
    }

    ffor(i, 0, ans.size()/2) swap(ans[i], ans[ans.size()-1-i]);

    return ans;
}


long long mulmod(long long a,
                               long long b,
                               long long mod)
{
    long long res = 0; // Initialize result

    // Update a if it is more than
    // or equal to mod
    a %= mod;

    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;

        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;

        b >>= 1; // b = b / 2
    }

    return res;
}


vector<int> cl;
int dl[500][500] = {0};

int dp(vector<int>& cl){
    int n = cl.size();
    if(n==1) return 1;
    int mn = 1000;
    ffor(i, 0, n) mn = min(mn, cl[i]);
    vector<int> ncl;
    vector<int> ans1;
    vector<int> ans2;
    int i = 0;
    while(i<n){
        int count = 0;
        if(cl[i]==mn){
            while(i+count<n and cl[i+count]==mn) {
                count++;
            }
            count++;
            ffor(j, 0, count/2) {
                ncl.push_back(mn+1);
                ans1.push_back(dp(ncl));
                if(count%2){
                    ncl.push_back(mn);
                    ans1.push_back(dp(ncl));
                    ncl.pop_back();
                }
            }
            i += count;
        }
        else{
            ncl.push_back(cl[i]);
            i++;
        }
    }

    i = n-1;
    while(i>=0){
        int count = 0;
        if(cl[i]==mn){
            while(i-count>=0 and cl[i-count]==mn) {
                count++;
            }
            count++;
            ffor(j, 0, count/2) {
                ncl.push_back(mn+1);
                ans1.push_back(dp(ncl));
                if(count%2){
                    ncl.push_back(mn);
                    ans1.push_back(dp(ncl));
                    ncl.pop_back();
                }
            }
            i += count;
        }
        else{
            ncl.push_back(cl[i]);
            i++;
        }
    }

}


vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    ll n, k;
    ffor(_, 0, t){
        cin>>n>>k;
        ll sm = k*k;
        if(sm>n) cout<<"NO"<<endl;
        else{
            sm = sm - n;
            if(sm%2==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}
