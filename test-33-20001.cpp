#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> children(n + 1); 

    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        children[boss].push_back(i);
    }

    vector<int> counts(n + 1, 0); 

    stack<pair<int, bool>> s; 
    s.push({1, false});

    while (!s.empty()) {
        auto node = s.top().first;
        bool visited = s.top().second;
        s.pop();

        if (!visited) {
            // Push the node back as visited, then push all children
            s.push({node, true});
            for (int child : children[node]) {
                s.push({child, false});
            }
        } else {
            // Calculate the count for this node
            int total = 0;
            for (int child : children[node]) {
                total += counts[child];
            }
            counts[node] = total + children[node].size();
        }
    }

    cout << "20001\tDonald Knuth\t";

    // Output the counts for each employee
    for (int i = 1; i <= n; i++) {
        cout << counts[i] << " ";
    }
    cout << endl;

    return 0;
}