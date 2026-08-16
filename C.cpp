#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t;
    cin >> t;

    while (t--) {
        ll a, b, x;
        cin >> a >> b >> x;

        vector<pair<ll, ll>> A, B; 

        ll cur = a, cnt = 0;
        while (true) {
            A.push_back({cur, cnt});
            if (cur == 0) break;
            cur /= x;
            cnt++;
        }

        cur = b;
        cnt = 0;
        while (true) {
            B.push_back({cur, cnt});
            if (cur == 0) break;
            cur /= x;
            cnt++;
        }

        ll ans = (ll)4e18;

        for (auto [va, ca] : A) {
            for (auto [vb, cb] : B) {
                ans = min(ans, ca + cb + abs(va - vb));
            }
        }

        cout << ans << endl;
    }

    return 0;
}