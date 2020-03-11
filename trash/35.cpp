// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72823544
// ConsoleApplication10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
int vis[4000];
int max_t = 0;
long long int sum[400];
long long int pre[400];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie();
	int n, k;
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		bool d=true;
		memset(vis,0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			cin >> sum[i];
		}
		long long int t = 1, maxn = 0;
		pre[0] = 1;
		long long int s = 1;
		while (1)
		{
			t *= k;
			pre[s] = t;
			maxn = s;
			if (t > 999999999999999999)
				break;
			s++;
		}
		for (int i = 0; i < n; i++)
		{
			if (sum[i] == 0)
				continue;
			long long int now = 0;
			for (long long int j = 0; j <= maxn; j++)
			{
				if (pre[j] > sum[i])
				{
					now = j - 1;
					break;
				}
			}
			long long ha = sum[i];
			for (long long j = now; j >= 0; j--)
			{
				if (!vis[j] && ha >= pre[j])
				{
					ha -= pre[j];
					vis[j] = 1;
				}
			}
			if (ha > 0)
				d = false;
		}
		if (d == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

