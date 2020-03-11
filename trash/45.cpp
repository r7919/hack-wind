// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72821662
#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long t, n, k;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		queue<long long>q;
		long long mas[60] = {0};
		int f = 0;
		cin >> n >> k;
		long long *a;
		a = new long long[n];
		for(int j = 0; j < n; j++)cin >> a[j];
		for(int j = 0; j < n; j++)
		{
			long long l = a[j];
			while(l)
			{
				q.push(l % k);
				l/=k;
			}
			int z = 0;
			while(!q.empty())
			{
				mas[z] += q.front();
				if(mas[z] > 1){ f = 1; break;}
				q.pop();
				z++;
			}
			
		}
		if(f == 1)cout << "NO" << endl;
		if(f == 0) cout << "YES" << endl;
	}
}

