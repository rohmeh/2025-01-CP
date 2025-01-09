#include <iostream>
#include <vector>
using namespace std;

// Function to compute the number of steps in the Collatz Conjecture sequence
int collatzSteps(int n) {
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }
    return steps;
}

int main() {
    cout << "20001 \t" << "Alan Turing \t";
    // Replace 20001 with your Roll Number and Alan Turing by your name.

    int t;
    cin >> t;

    vector<int> testCases(t);
    for (int i = 0; i < t; ++i) {
        cin >> testCases[i];
    }
    
    int sum_ccs = 0;

    for (int i = 0; i < t; ++i) {
        sum_ccs = sum_ccs + collatzSteps(testCases[i]);
    }
    
    cout << sum_ccs;
    cout << endl;
    return 0;
}