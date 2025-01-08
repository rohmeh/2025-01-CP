#include <iostream>
#include <vector>
using namespace std;

// Function to compute the nth Fibonacci number
long long computeFibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long prev1 = 0, prev2 = 1, current;
    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    return current;
}

int main() {
    int t;
    cout << "20001 \t Donald Knuth\t";
    cin >> t;   

    vector<int> testCases(t);
    for (int i = 0; i < t; ++i) {
        cin >> testCases[i];
    }

    for (int i = 0; i < t; ++i) {
        cout << computeFibonacci(testCases[i]) << "\t";
    }

    cout << endl;
    return 0;
}