/*
Name: Shortest Routes I
Reference: https://cses.fi/problemset/task/1671

Input: The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,\dots,n, and city 1 is Syrjälä.
After that, there are m lines describing the flight connections. Each line has three integers a, b and c: a flight begins at city a, ends at city b, and its length is c. Each flight is a one-way flight.
You can assume that it is possible to travel from Syrjälä to all other cities.

Output: Print n integers: the shortest route lengths from Syrjälä to cities 1,2,\dots,n.
Contributer: Rohan Mehra
git: rohmeh
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    
    // Adjacency list: for each city, storing pairs of (destination, length)
    vector<vector<pair<int,int>>> adj(n+1);
    
    // Reading flight connections
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c}); 
    }
    
    // Array to store shortest distances from Syrjala (city 1)
    vector<long long> dist(n+1, INF);
    dist[1] = 0;  // Distance to Syrjala is 0
    
    // Priority queue to store {distance, city}
    // We use negative distances because priority_queue is max heap by default
    priority_queue<pair<long long,int>> pq;
    pq.push({0, 1});  // Start from Syrjala
    
    // Dijkstra's algorithm
    while(!pq.empty()) {
        long long d = -pq.top().first;  // Current distance (negated)
        int city = pq.top().second;     // Current city
        pq.pop();
        
        // If we've found a longer path, skip
        if(d > dist[city]) continue;
        
        // Checking all flights from current city
        for(auto [next_city, length] : adj[city]) {
            // If we found a shorter path to next_city
            if(dist[city] + length < dist[next_city]) {
                dist[next_city] = dist[city] + length;
                pq.push({-dist[next_city], next_city});
            }
        }
    }
    
    cout << "20001\t" << "Donald Knuth\t";
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}