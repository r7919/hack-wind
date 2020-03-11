// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821134

//naveen mall
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb               push_back
#define sz(c)            (int)c.size()
#define len(c)           (int)c.length()
#define vec              vector
#define int              long long int
#define all(c)           c.begin(), c.end()
#define rall(c)          c.rbegin(), c.rend()
#define trav(a,i)        for(auto& i: a)
#define fl(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define rfl(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define invect(v,n)       for(int i=0;i<n;i++ ){int arb;cin>>arb;v.pb(arb);}
#define inset(s,n)        forloop(n){int aset;cin>>aset;s.insert(aset);}
#define display(c)        trav(c,i) cout<<i<<" ";cout<<"\n";
#define F                 first
#define S                 second
#define pii               pair<int,int>
#define PB                pop_back
#define endl              "\n"
#define copy(a,b)         copy(all(a),back_inserter(b));
#define section(a,b,w)    set_intersection(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
#define union(a,b,w)      set_union(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
#define diff(a,b,w)       set_difference(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
#define symdiff(a,b,w)    set_symmetric_difference(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));

void solve()
 {   int n,k;
 	cin>>n>>k;
 	vec<int> a;
 	invect(a,n)
 	vec<int> v(n);
 	
    int co[100];
    memset(co,0,sizeof(co));

 	for(int i=0;i<n;i++)
 		 {
          if(a[i]!=0)
      	  {  int dc=-1;
             while(a[i]!=0)
             	  {     
             	  	  if(a[i]%k==0 || a[i]%k==1)
             	  	  	  { 
                             if(a[i]%k==0)
                             	  dc++;
                             	else
                             		{   dc++;
                             		co[dc]++;

                             		}

                             		a[i]=a[i]/k;




             	  	  	  }
             	  	  	  else 
             	  	  	  	 {
             	  	  	  	 	cout<<"NO"<<endl;
             	  	  	  	 	  return ;
             	  	  	  	 }




             	  }
      	  }


 		 }

 		// display(co)
 		 for(int i=0;i<100;i++)
 		 	 
 		 	 { if(co[i]>=2)
 		 	  	  {
 		 	  	  	cout<<"NO"<<endl;
 		 	  	  	  return;
 		 	  	  }




              }




    cout<<"YES"<<endl;

















  }








 



signed main()
{fast
	int t;
	cin>>t;
	while(t--)
		 {
		 	solve();
		 }
}











