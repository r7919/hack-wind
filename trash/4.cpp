// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72811658
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int T;
ll a[200100];

ll fastpower(long long a,long long b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    long long res = fastpower(a,b/2);
    res = res * res;
    if(b%2!=0)
        res*=a;
    return res;
}

set < ll > st;
set < ll >::iterator it;
vector < ll > v;

int main()
{
    //T = 1;
    cin >> T;
    while(T--)
    {
        int n,k;
        cin >> n >> k;
        v.clear();
        st.clear();
        ll Max = 0;
        for(int i=0; i<n; i++)  cin >> a[i], Max = max(Max, a[i]);
        int i = 0;
        while(fastpower(k, i) <= Max)
        {
            st.insert(fastpower(k, i));
            i++;
        }
        bool ok = true;
        for(int i = 0; i<n; i++)
        {
            if(st.size())
            {
                it = st.end();
                it--;
                while(1)
                {
                    if(*it <= a[i])
                    {
                        a[i]-=*it;
                        v.push_back(*it);
                    }
                    if(it == st.begin())  break;
                    it--;
                }
            }
            if(a[i] > 0)  ok = false;
            for(auto j : v)  st.erase(j);
            v.clear();
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}

