// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72822274
﻿#include<iostream>

#include<bits/stdc++.h>

using namespace std;
#define SWS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

const int MOD = (int)1e9 + 7;




int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long sizee;
		ll k;

		bool Good = true;
		cin >> sizee >>k;
		vector<ll>Mas(sizee);
		vector<bool>Dt(100 , true);


		for (int i = 0; i < sizee; i++) {
			cin >> Mas[i];
		}

		for (int i = 0; i < sizee; i++) {


			ll temp = Mas[i];
			vector<bool>Temp(100, true);
			int its = 0;

			while (temp > 1) {

				if (temp % k > 1) {
					Good = false;
					break;
				}
				else if (temp % k == 1) {
					Temp[its] = false;
				}
				its++;
				temp = temp / k;
			}
			if( Mas[i] != 0)
			Temp[its] = false;
		
			for (int i = 0; i <=its; i++) {
				if (Temp[ i ] == false) {
					if (Dt[i] == false) {
						Good = false;
						break;
					}
					else {
						Dt[i] = false;
					}
				}
			}

			
		}
		if (Good == false) {
			cout << "NO" << endl;
		}
		else { cout << "YES" << endl; }


	}
	//	system("pause");
	return 0;
}
