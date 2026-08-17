#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        set<char> st;

        for (int i = 0; i < a; i++) {
            string s;
            cin >> s;

            char ch = toupper(s[0]);
            st.insert(ch);
        }

        bool flag = true;

        for (int i = 0; i < b; i++) {
            string s;
            cin >> s;

            for (char ch : s) {
                ch = toupper(ch);

                if (st.find(ch) == st.end()) {
                    flag = false;
                }
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}