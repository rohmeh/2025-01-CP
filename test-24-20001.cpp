#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>  // Add this header for reverse
using namespace std;

// Structure to store coordinates
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

// Direction arrays
const int dx[] = {-1, 1, 0, 0};  // up, down, left, right
const int dy[] = {0, 0, -1, 1};  // up, down, left, right
const char dir[] = {'U', 'D', 'L', 'R'}; 

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    Point start(0, 0), end(0, 0);
    
    // Read the grid and find start (A) and end (B) points
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') start = Point(i, j);
            if(grid[i][j] == 'B') end = Point(i, j);
        }
    }
    
    vector<vector<int>> prev(n, vector<int>(m, -1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // BFS
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;
    
    bool found = false;
    
    while(!q.empty() && !found) {
        Point curr = q.front();
        q.pop();
        
        // Try all four directions
        for(int i = 0; i < 4; i++) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];
            
            // Check if new position is valid
            if(newX >= 0 && newX < n && newY >= 0 && newY < m && 
               !visited[newX][newY] && grid[newX][newY] != '#') {
                visited[newX][newY] = true;
                prev[newX][newY] = i;
                q.push(Point(newX, newY));
                
                if(grid[newX][newY] == 'B') {
                    found = true;
                    break;
                }
            }
        }
    }
    
    if(!found) {
        cout << "20001\t" << "Donald Knuth\t" << "NO" << endl;
        return 0;
    }
    
    // Reconstruct the path
    string path = "";
    Point curr = end;
    while(curr.x != start.x || curr.y != start.y) {
        int p = prev[curr.x][curr.y];
        path += dir[p];
        curr = Point(curr.x - dx[p], curr.y - dy[p]);
    }
    
    // Reverse the path as we constructed it from end to start
    reverse(path.begin(), path.end());
    
    
    cout << "20001\t" << "Donald Knuth\t" << "YES\t" << path.length() << endl;
    cout << path << endl;
    
    return 0;
}