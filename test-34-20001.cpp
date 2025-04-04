/*
Name: Tree Matching
Reference: https://cses.fi/problemset/task/1130

Input: The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,\ldots,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output: Print one integer: the maximum number of pairs.
Contributer: Rohan Mehra
git: rohmeh
*/


#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

const int MAXN = 200010; 
vector<int> adj[MAXN]; 
int dp0[MAXN], dp1[MAXN]; 

int main() {

    int n;
    cin >> n;

    if (n == 0) return 0; 

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    stack<tuple<int, int, bool>> st;
    st.push(make_tuple(1, -1, false)); 

    while (!st.empty()) {
        auto [u, parent_u, visited] = st.top();
        st.pop();

        if (!visited) {
            st.push(make_tuple(u, parent_u, true));

            for (auto v : adj[u]) {
                if (v != parent_u) {
                    st.push(make_tuple(v, u, false));
                }
            }
        } else {
            vector<int> children;
            for (auto v : adj[u]) {
                if (v != parent_u) {
                    children.push_back(v);
                }
            }

            int S = 0;
            for (auto v : children) {
                S += max(dp0[v], dp1[v]);
            }
            dp0[u] = S;

            if (children.empty()) {
                dp1[u] = 0; 
            } else {
                int min_penalty = MAXN;
                for (auto v : children) {
                    int temp_penalty = max(dp0[v], dp1[v]) - dp0[v];
                    if (temp_penalty < min_penalty) {
                        min_penalty = temp_penalty;
                    }
                }
                dp1[u] = 1 + (S - min_penalty);
            }
        }
    }

    cout << "20001\tDonald Knuth\t" << max(dp0[1], dp1[1]) << endl;
    return 0;
}