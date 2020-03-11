// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72823580
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

using ll = long long int;

int main() {
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++) {
        int n, k;
        cin >> n >> k;
        vector<ll> a;
        int kol = 0;
        for (int i = 0; i < n; i++) {
            a.push_back(0);
            cin >> a[i];
            if (a[i] == 0) kol++;
            //cout << a[i] << " ";
        }
        //cout << "\n" << kol << " " << n << "\n";
        if (kol == n) {
            cout << "YES\n";
            continue;
        }
        sort(a.rbegin(), a.rend());
        double s1 = log(a[0]) * 1. / log(k);
        ll s = ceil(s1);
        ll q = pow(k, s);
        while (q != 0) {
            for (int i = 0; i < n; i++) {
                if (a[i]>=q)
                {
                    a[i] -= q;
                    break;
                }
            }
            q = q / k;
        }
        kol =0;
        for (int i=0;i<n;i++)
        {
            if (a[i] == 0) kol++;
            else break;
        }

        if (kol == n)
        {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}

