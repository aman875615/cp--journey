#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int turn) {
    if (arr.size() == 1) {
        return arr[0] == 1;
    }

    if (turn == 0) {
        for (int i = 0; i < arr.size() - 1; i++) {
            vector<int> temp;

            for (int j = 0; j < i; j++) {
                temp.push_back(arr[j]);
            }

            temp.push_back(max(arr[i], arr[i + 1]));

            for (int j = i + 2; j < arr.size(); j++) {
                temp.push_back(arr[j]);
            }

            if (solve(temp, 1)) {
                return true;
            }
        }

        return false;
    } 
    else {
        for (int i = 0; i < arr.size() - 1; i++) {
            vector<int> temp;

            for (int j = 0; j < i; j++) {
                temp.push_back(arr[j]);
            }

            temp.push_back(min(arr[i], arr[i + 1]));

            for (int j = i + 2; j < arr.size(); j++) {
                temp.push_back(arr[j]);
            }

            if (!solve(temp, 0)) {
                return false;
            }
        }

        return true;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool ans = solve(arr, 0);

        if (ans) {
            cout << "Bessie\n";
        } else {
            cout << "Elsie\n";
        }
    }

    return 0;
}