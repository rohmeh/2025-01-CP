#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;  // Maximum number of planets
const int MAXK = 30;       // log2(10^9) ≈ 30, we need this many steps

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> next(MAXK, vector<int>(n + 1));
    
    // This will be our base case (2^0 = 1 jump)
    for(int i = 1; i <= n; i++) {
        cin >> next[0][i];
    }
    
    // Precompute all jumps using binary lifting
    // If we know where we get after 2^(j-1) jumps,
    // we can find where we get after 2^j jumps by making two 2^(j-1) jumps
    for(int j = 1; j < MAXK; j++) {
        for(int i = 1; i <= n; i++) {
            next[j][i] = next[j-1][next[j-1][i]];
        }
    }
    
    cout << "20001\t" << "Donald Knuth\t" << "\n";
    
    // Process queries
    while(q--) {
        int x, k;
        cin >> x >> k;
        
        // For each set bit in k, use the precomputed jumps
        for(int j = 0; j < MAXK; j++) {
            if(k & (1 << j)) {  // If jth bit is set
                x = next[j][x];  // Make 2^j jumps
            }
        }
        
        cout << x << "\n";
    }
    
    return 0;
}