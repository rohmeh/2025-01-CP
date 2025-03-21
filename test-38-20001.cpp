/*
Name: Forest Queries
Reference: https://cses.fi/problemset/task/1652

Input: The first input line has two integers n and q: the size of the forest and the number of queries.
Then, there are n lines describing the forest. Each line has n characters: . is an empty square and * is a tree.
Finally, there are q lines describing the queries. Each line has four integers y_1, x_1, y_2, x_2 corresponding to the corners of a rectangle.

Output: Print the number of trees inside each rectangle.
Contributer: Rohan Mehra
git: rohmeh
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // Reading the forest grid
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    // Creating prefix sum matrix
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (grid[i - 1][j - 1] == '*' ? 1 : 0);
        }
    }

    cout << "20001\tDonald Knuth\t";

    // Processing queries
    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int trees = prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1];
        cout << trees << " ";
    }

    return 0;
}