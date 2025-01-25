/*
Name: Missing Number
Reference: https://cses.fi/problemset/task/1083

Input: There are t test cases. In each test case, you are given all 
numbers between 1,2,\ldots,n except one. Your task is to find the missing number.


The first input line contains an integer t denoting the number of test cases.
There will be 2*t lines following that which can be paired naturally.
The first line contains n and the second line contains n-1 numbers.
In the second line, each number is distinct and between 1 and n (inclusive).

Output: Print the sum of missing numbers in the specified format.
*/

#include <iostream>
#include <vector> // this is added to bring back
using namespace std;

int main() {
    int t;
    cin >> t; 
    
    long long sum_missing_nrs = 0; 

    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n; 

        // Read the n-1 numbers into a vector
        vector<int> numbers(n - 1);
        long long total_sum = 0;

        for (int i = 0; i < n - 1; ++i) {
            cin >> numbers[i];
            total_sum += numbers[i];
        }

        long long expected_sum = n * (n + 1) / 2;
        sum_missing_nrs += (expected_sum - total_sum);
    }

    cout << "20001\t" << "Donald Knuth\t" << sum_missing_nrs <<"\n";
    cout << endl;

    return 0;
}
