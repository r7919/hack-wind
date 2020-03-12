// LILY SOURCE:  https://codeforces.com/contest/1324/submission/73040858
#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n;
int a[maxn];
vector<int> adj[maxn];
int dp[maxn],dp2[maxn];

void dfs1(int u,int f){
    dp[u]=a[u]-(int)!a[u];
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=f){
            dfs1(v,u);
            dp[u]+=max(dp[v],0);
        }
    }
}

void dfs2(int u,int f){
    int w=max(0,dp2[u])+(a[u]-(int)!a[u]);
    for(int i=0;i<adj[u].size();i++)if(adj[u][i]!=f)w+=max(0,dp[adj[u][i]]);
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=f){
            dp2[v]=max(0,w-max(0,dp[v]));
            dfs2(v,u);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++){
        cout<<dp[i]+dp2[i]<<' ';
    }
    return 0;
}
