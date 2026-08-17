#include <bits/stdc++.h>
using namespace std;

// ============================================
// APPROACH 1: BRUTE FORCE
// ============================================
/*
EXPLANATION:
- Recursively check every possible combination of characters
- At each step, we have 3 choices:
  1. If characters match: include it and move both pointers
  2. If they don't match: try excluding first string's character
  3. If they don't match: try excluding second string's character
- Take maximum result from all recursive calls

TIME COMPLEXITY: O(2^(m+n)) - Exponential, very slow for large inputs
SPACE COMPLEXITY: O(m+n) - Recursion call stack

DISADVANTAGE: Extremely slow for strings > 20 characters
ADVANTAGE: Easy to understand, no extra space for DP table
*/

int lcs_bruteforce(string a, string b, int i, int j) {
    // Base case: if any string is exhausted
    if (i == 0 || j == 0) {
        return 0;
    }
    
    // If characters match, include and move both
    if (a[i - 1] == b[j - 1]) {
        return 1 + lcs_bruteforce(a, b, i - 1, j - 1);
    }
    
    // If characters don't match, try both options
    return max(
        lcs_bruteforce(a, b, i - 1, j),      // Exclude from a
        lcs_bruteforce(a, b, i, j - 1)       // Exclude from b
    );
}

// ============================================
// APPROACH 2: BETTER (Memoization/Top-Down DP)
// ============================================
/*
EXPLANATION:
- Same recursive logic as brute force but store results in memo table
- Before computing, check if already computed (memoization)
- Avoids redundant calculations

TIME COMPLEXITY: O(m*n) - Only compute each subproblem once
SPACE COMPLEXITY: O(m*n) - DP table + O(m+n) recursion stack

ADVANTAGE: Much faster than brute force, still recursive
DISADVANTAGE: Uses recursion (stack can overflow for very large inputs)
*/

int memo[1005][1005];
bool visited[1005][1005];

int lcs_memoization(string a, string b, int i, int j) {
    // Base case
    if (i == 0 || j == 0) {
        return 0;
    }
    
    // If already computed, return from memo
    if (visited[i][j]) {
        return memo[i][j];
    }
    
    visited[i][j] = true;
    
    // If characters match
    if (a[i - 1] == b[j - 1]) {
        memo[i][j] = 1 + lcs_memoization(a, b, i - 1, j - 1);
    } else {
        // If characters don't match
        memo[i][j] = max(
            lcs_memoization(a, b, i - 1, j),
            lcs_memoization(a, b, i, j - 1)
        );
    }
    
    return memo[i][j];
}

// ============================================
// APPROACH 3: OPTIMAL (Tabulation/Bottom-Up DP)
// ============================================
/*
EXPLANATION:
- Build DP table iteratively from bottom-up (i=0 to m, j=0 to n)
- dp[i][j] = LCS length of first i characters of a and first j characters of b
- Transition:
  - If a[i-1] == b[j-1]: dp[i][j] = dp[i-1][j-1] + 1
  - Else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])

TIME COMPLEXITY: O(m*n) - Single pass through DP table
SPACE COMPLEXITY: O(m*n) - DP table (can be optimized to O(min(m,n)))

ADVANTAGE: Fastest, no recursion, easy to implement
DISADVANTAGE: Uses O(m*n) space

Can also return the actual LCS string by backtracking!
*/

int lcs_optimal(string a, string b) {
    int m = a.length();
    int n = b.length();
    
    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

// Get the actual LCS string (backtracking)
string lcs_optimal_string(string a, string b) {
    int m = a.length();
    int n = b.length();
    
    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Backtrack to find LCS string
    string result = "";
    int i = m, j = n;
    
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            result = a[i - 1] + result;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    return result;
}

// ============================================
// MAIN FUNCTION
// ============================================

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b;
    cout << "Enter first string: ";
    cin >> a;
    cout << "Enter second string: ";
    cin >> b;
    
    cout << "\n========== RESULTS ==========\n";
    
    // Only use brute force for small strings (<=15 characters)
    if (a.length() <= 15 && b.length() <= 15) {
        cout << "1. BRUTE FORCE: " << lcs_bruteforce(a, b, a.length(), b.length()) << endl;
    } else {
        cout << "1. BRUTE FORCE: Skipped (string too large, too slow)\n";
    }
    
    // Reset memo array
    memset(visited, false, sizeof(visited));
    
    cout << "2. MEMOIZATION: " << lcs_memoization(a, b, a.length(), b.length()) << endl;
    
    cout << "3. OPTIMAL (DP): " << lcs_optimal(a, b) << endl;
    cout << "   LCS String: " << lcs_optimal_string(a, b) << endl;
    
    return 0;
}

/*
EXAMPLE:
Input:  a = "ABCDGH"
        b = "AEDFHR"

Output:
1. BRUTE FORCE: 3
2. MEMOIZATION: 3
3. OPTIMAL (DP): 3
   LCS String: ADH

COMPARISON TABLE:
┌─────────────┬──────────────────┬──────────────────┬──────────────────┐
│  Approach   │  Time Complexity │ Space Complexity │   When to Use    │
├─────────────┼──────────────────┼──────────────────┼──────────────────┤
│ Brute Force │   O(2^(m+n))     │    O(m+n)        │ Learning only    │
│ Memoization │    O(m*n)        │    O(m*n)        │ Recursive style  │
│ Tabulation  │    O(m*n)        │    O(m*n)        │ BEST - Production│
└─────────────┴──────────────────┴──────────────────┴──────────────────┘
*/
















