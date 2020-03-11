// LILY SOURCE:  https://codeforces.com/contest/1312/submission/72820997
#include <bits/stdc++.h>

using namespace std;

bool mark[1000];
long long a[50];

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, k;
        cin >> n >> k;
        fill(mark, mark + 1000, false);
        bool ans = true;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            vector <long long> rem;
            while (a[j] >= k) {
                rem.push_back(a[j] % k);
                a[j] /= k;
            }
            rem.push_back(a[j]);
            for (int ii = 0; ii < rem.size(); ii++) {
                if (rem[ii] > 1 || (mark[ii] && rem[ii])) {
                    ans = false;
                    //cout << ii << "hey" << endl;
                } else {
                    mark[ii] = max(rem[ii], mark[ii] * 1LL);
                }
                //cout << rem[ii] << mark[ii] << ' ';
            }//cout << "\n";
        }
        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
