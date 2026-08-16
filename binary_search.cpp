#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int index = binarySearch(arr, target);

    if (index == -1) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found at index: " << index << endl;
    }

    return 0;
}