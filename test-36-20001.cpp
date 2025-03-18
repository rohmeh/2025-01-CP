/*
Name: Company Queries I
Reference: https://cses.fi/problemset/task/1687

Input: The first input line has two integers n and q: the number of employees and queries. The employees are numbered 1,2,...,n, and employee 1 is the general director.
The next line has n-1 integers e_2,e_3,...,e_n: for each employee 2,3,\dots,n their boss.
Finally, there are q lines describing the queries. Each line has two integers x and k: who is employee x's boss k levels higher up?

Output: Print the answer for each query. If such a boss does not exist, print -1.
Contributer: Rohan Mehra
git: rohmeh
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_LOG = 20; // Maximum log value for n = 2e5 (2^20 > 2e5)

int main() {
    int n, q;
    cin >> n >> q;

    // Parent array: parent[i] = direct boss of employee i
    vector<int> parent(n + 1);
    parent[1] = 0; // General director has no boss

    // Read the bosses for employees 2 to n
    for (int i = 2; i <= n; ++i) {
        cin >> parent[i];
    }

    // Binary lifting table: up[i][j] = 2^j-th ancestor of node i
    vector<vector<int>> up(n + 1, vector<int>(MAX_LOG, 0));

    // Initialize 2^0-th ancestor (direct parent)
    for (int i = 1; i <= n; ++i) {
        up[i][0] = parent[i];
    }

    // Precompute 2^j-th ancestors for all nodes
    for (int j = 1; j < MAX_LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (up[i][j - 1] == 0) {
                up[i][j] = 0; // No ancestor exists
            } else {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
    
    cout << "20001\tDonald Knuth\t";

    while (q--) {
        int x, k;
        cin >> x >> k;

        for (int j = 0; j < MAX_LOG; ++j) {
            if (k & (1 << j)) { // Check if the j-th bit of k is set
                x = up[x][j];
                if (x == 0) break; // Breaking if no such ancestor exists
            }
        }

        cout << (x == 0 ? -1 : x) << " ";
    }

    return 0;
}