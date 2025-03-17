/*
Name: Tree Diameter
Reference: https://cses.fi/problemset/task/1131

Input: The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,...,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output: Print one integer: the diameter of the tree.
Contributer: Rohan Mehra
git: rohmeh
*/

#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS and return the farthest node and its distance
pair<int, int> bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size() - 1; // Number of nodes
    vector<int> dist(n + 1, -1); // Distance array initialized to -1
    queue<int> q;
    
    // Initialize BFS
    q.push(start);
    dist[start] = 0;
    
    int farthestNode = start;
    int maxDistance = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == -1) { // If v is not visited
                dist[v] = dist[u] + 1;
                q.push(v);
                
                if (dist[v] > maxDistance) {
                    maxDistance = dist[v];
                    farthestNode = v;
                }
            }
        }
    }
    
    return {farthestNode, maxDistance};
}

int main() {
    int n;
    cin >> n;
    
    // Adjacency list representation of the tree
    vector<vector<int>> adj(n + 1);
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // Step 1: Perform BFS from node 1 to find the farthest node
    pair<int, int> firstBFS = bfs(1, adj);
    int farthestNode1 = firstBFS.first;
    
    // Step 2: Perform BFS from the farthest node found in Step 1
    pair<int, int> secondBFS = bfs(farthestNode1, adj);
    int diameter = secondBFS.second;
    
    cout << "20001\tDonald Knuth\t" << diameter << "\n";
    
    return 0;
}