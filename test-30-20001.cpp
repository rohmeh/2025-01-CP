/*
Name: Longest Flight Route
Reference: https://cses.fi/problemset/task/1680

Input: The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,\dots,n. City 1 is Syrjälä, and city n is Lehmälä.
After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. Each flight is a one-way flight.

Output: First print the maximum number of cities on the route. After this, print the cities in the order they will be visited. You can print any valid solution. If there are no solutions, print "IMPOSSIBLE".
Contributer: Rohan Mehra
git: rohmeh
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];  // Adjacency list representation of graph
vector<int> dp(MAXN, -1); // dp[i] stores longest path from i to destination
vector<int> parent(MAXN, -1); // Stores parent of each node in longest path

// DFS function to find longest path
int findLongestPath(int current, int destination) {
    // If we've already computed this state
    if(dp[current] != -1) 
        return dp[current];
    
    // Base case: if we're at destination
    if(current == destination) 
        return dp[current] = 1;
    
    int maxLength = 0;
    // Try all possible next cities
    for(int nextCity : graph[current]) {
        int length = findLongestPath(nextCity, destination);
        if(length > 0 && length + 1 > maxLength) {
            maxLength = length + 1;
            parent[current] = nextCity; // Store the next city in the longest path
        }
    }
    
    return dp[current] = maxLength;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    cout << "20001\t" << "Donald Knuth\t" << '\n';
    
    int longestPathLength = findLongestPath(1, n);
    
    if(longestPathLength == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << longestPathLength << "\n";
    int current = 1;
    while(current != -1) {
        cout << current << " ";
        current = parent[current];
    }
    
    return 0;
}

