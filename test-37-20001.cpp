/*
Name: Dynamic Range Sum Queries
Reference: https://cses.fi/problemset/task/1648

Input: The first input line has two integers n and q: the number of values and queries.
The second line has n integers x_1,x_2,...,x_n: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".

Output: Print the result of each query of type 2.
Contributer: Rohan Mehra
git: rohmeh
*/

#include <iostream>
#include <vector>
using namespace std;

int n; 
vector<long long> tree;

// Building the segment tree recursively
void build(const vector<int>& data, int node, int start, int end) {
    if (start == end) {
        tree[node] = data[start];
    } else {
        int mid = (start + end) / 2;
        build(data, 2 * node, start, mid);       
        build(data, 2 * node + 1, mid + 1, end); 
        tree[node] = tree[2 * node] + tree[2 * node + 1]; 
    }
}

// Query the sum of a range [l, r]
long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0; // No overlap
    }
    if (l <= start && end <= r) {
        return tree[node]; // Total overlap
    }
    int mid = (start + end) / 2;
    long long leftSum = query(2 * node, start, mid, l, r);
    long long rightSum = query(2 * node + 1, mid + 1, end, l, r);
    return leftSum + rightSum; // Partial overlap
}

// Update the value at position `pos` to `value`
void update(int node, int start, int end, int pos, int value) {
    if (start == end) {
        tree[node] = value; 
    } else {
        int mid = (start + end) / 2;
        if (pos <= mid) {
            update(2 * node, start, mid, pos, value); 
        } else {
            update(2 * node + 1, mid + 1, end, pos, value);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1]; 
    }
}

int main() {
    int q;
    cin >> n >> q;

    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    tree.resize(4 * n); 
    build(data, 1, 0, n - 1); 
    
    cout << "20001\tDonald Knuth\t";

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { 
            int k, u;
            cin >> k >> u;
            update(1, 0, n - 1, k - 1, u);
        } else if (type == 2) { 
            int a, b;
            cin >> a >> b;
            cout << query(1, 0, n - 1, a - 1, b - 1) << " "; 
        }
    }

    return 0;
}