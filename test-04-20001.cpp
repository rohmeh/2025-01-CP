/*
Name: Increasing Array
Reference: https://cses.fi/problemset/task/1094

Input: There are t test cases. In each test case, 
you are given an array of n integers.
You want to modify the array so that it is increasing, 
i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one.
What is the minimum number of moves required in each case?

The first input line contains an integer t denoting the number of test cases.
The following t lines contains n values in an array.

Output: Print the sum of minimum number of moves required in each case.
Contributer: Jay Bharambe 22159
git: jayb71
*/

#include <iostream>
#include<sstream>
#include <vector>
using namespace std;

int calculate_minimum_moves(vector<int> arr, int n) {
    int sum = 0;
    for(int i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) {
            sum += (arr[i-1]-arr[i]);
        }
    }
    return sum;
}

int main() {    
    int t;
    cin >> t;   
    long long sum_missing_nrs = 0;
    
    while(t--) {
        int n;
        cin >> n;
        cin.ignore();
        
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num);
        }
        
        sum_missing_nrs += calculate_minimum_moves(arr,n);
        
    }
    
    //Critical line
    cout << "20001\t" << "Donald Knuth\t" << sum_missing_nrs <<"\n";
    return 0;
}
