#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> v;

        for (int i = 0; i < n; i++) {
            if (a[i] != i + 1) {
                v.push_back(i);
            }
        }

        bool ok = true;

        int l = 0;
        int r = v.size() - 1;

        while (l < r) {

            if (a[v[l]] != v[r] + 1 ||
                a[v[r]] != v[l] + 1) {
                
                ok = false;
                break;
            }

            l++;
            r--;
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}