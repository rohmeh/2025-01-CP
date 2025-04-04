/*
Name: Planets Queries II
Reference: https://cses.fi/problemset/task/1160

Input: The first input line contains two integers n and q: the number of planets and queries. The planets are numbered 1,2,...,n.
The second line contains n integers t_1,t_2,...,t_n: for each planet, the destination of the teleporter.
Finally, there are q lines describing the queries. Each line has two integers a and b: you are now on planet a and want to reach planet b.

Output: For each query, print the minimum number of teleportations. If it is not possible to reach the destination, print -1.
Contributer: Rohan Mehra
git: rohmeh
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find minimum teleports needed from start to end planet
int findMinTeleports(int start, int end, vector<int>& teleporter) {
    int n = teleporter.size() - 1;  // Number of planets
    
    // Array to track visited planets and their distances
    // Initially all distances are -1 (unvisited)
    vector<int> distance(n + 1, -1);
    
    queue<int> q;  
    
    // Starting BFS from 'start' planet
    q.push(start);
    distance[start] = 0;  // Distance to start planet is 0
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        
        // If we reached the destination
        if(current == end) {
            return distance[current];
        }
        
        // Getting next planet through teleporter
        int next = teleporter[current];
        
        // If we haven't visited this planet yet
        if(distance[next] == -1) {
            distance[next] = distance[current] + 1;
            q.push(next);
        }
    }
    
    // If we couldn't reach the destination, we'll return -1
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> teleporter(n + 1);  
    for(int i = 1; i <= n; i++) {
        cin >> teleporter[i];
    }

    cout << "20001\t" << "Donald Knuth\t" << "\n"
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << findMinTeleports(a, b, teleporter) << "\n";
    }
    
    return 0;
}