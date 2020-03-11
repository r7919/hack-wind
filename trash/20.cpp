// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72818173
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int o=0;o<t;o++)
    {
        bool a=true;
        long long int n,k;
        cin>>n>>k;
        vector<int>ok(128,0);

        for(int i=0;i<n;i++)
        {
            long long int num;
            cin>>num;
            vector<int>tmp;
            while(num!=0)
            {
                tmp.push_back(num%k);
                num-=num%k;
                num/=k;
            }
            int kk=0;
            for(int p=0;p<tmp.size();p++)
            {
                if((ok[p]==1&&tmp[p]==1)||tmp[p]>1)
                {
                    a=false;
                }
                if(tmp[p]==1)ok[p]=tmp[p];
            }
        }
        if(a)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

