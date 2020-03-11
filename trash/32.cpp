// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820216
///...................SUBHASHIS MOLLICK...................///
///.....DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING....///
///.............ISLAMIC UNIVERSITY,BANGLADESH.............///
///....................SESSION-(14-15)....................///
#include<bits/stdc++.h>
using namespace std;
#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pf(a) printf("%d",a)
#define pf2(a,b) printf("%d %d",a,b)
#define pf3(a,b,c) printf("%d %d %d",a,b,c)
#define sfl(a) scanf("%lld",&a)
#define sfl2(a,b) scanf("%lld %lld",&a,&b)
#define sfl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pfl(a) printf("%lld",a)
#define pfl2(a,b) printf("%lld %lld",a,b)
#define pfl3(a,b,c) printf("%lld %lld %lld",a,b,c)
#define nl printf("\n")
#define   timesave              ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define MPI map<int,int>mp;
#define fr(i,n) for(i=0;i<n;i++)
#define fr1(i,n) for(i=1;i<=n;i++)
#define frl(i,a,b) for(i=a;i<=b;i++)
#define tz 100000
/*primes in range 1 - n
1 - 100(1e2) -> 25 pimes
1 - 1000(1e3) -> 168 primes
1 - 10000(1e4) -> 1229 primes
1 - 100000(1e5) -> 9592 primes
1 - 1000000(1e6) -> 78498 primes
1 - 10000000(1e7) -> 664579 primes
large primes ->
104729 1299709 15485863 179424673 2147483647 32416190071 112272535095293 48112959837082048697
*/
//freopen("Input.txt","r",stdin);
//freopen("Output.txt","w",stdout);
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
ll k;
main()
{

    timesave;
    int ts;
    cin>>ts;
    while(ts--)
    {
        ll n,flag=0;
        vector<ll>vec;
        ll i,j,ar[35]={0},x=0;
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        sort(ar,ar+n);
        ll mx=ar[n-1];
        for(i=0;;i++)
        {
            x=pow(k,i)+.00000000001;
            if(x<=mx)
                vec.push_back(x);
            else
                break;
        }
        map<ll,ll>mp;
        for(i=n-1;i>=0;i--)
        {
            x=ar[i];
            while(x>0)
            {
                ll xx=upper_bound(vec.begin(),vec.end(),x)-vec.begin();
                if(mp[xx-1]==0)
                   {
                       x-=vec[xx-1];
                       mp[xx-1]=1;
                   }
                else
                    break;
                //cout<<x<<endl;
            }
            if(x!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}




