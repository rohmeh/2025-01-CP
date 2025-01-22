/*
Name: Repetitions
Reference: https://cses.fi/problemset/task/1069

Input: There are t test cases. In each test case, 
You are given a DNA sequence: a string consisting of characters A, C, G, and T.
Your task is to find the longest repetition in the sequence.
This is a maximum-length substring containing only one type of character.

Output: Print the sum of maximum-length of substring in each case.
Contributer: Jay Bharambe 22159
git: jayb71
*/


#include <iostream>
#include <vector>
using namespace std;

int calculate_max_repetition(string dnaSequence) {
    int currentCount = 1;
    int maxCount = 1;
    for(int i=1; i<dnaSequence.length(); i++) {
        if (dnaSequence[i]==dnaSequence[i-1]) {
            currentCount++;
        } else {
           maxCount = max(currentCount, maxCount);
           currentCount = 1;
        }
    }
    return max(maxCount, currentCount);
}


int main() {    
    long long sum_missing_nrs = 0;
    
    string dnaSequence;
    cin >> dnaSequence;
    
    
    sum_missing_nrs = calculate_max_repetition(dnaSequence);
    
    
    //Critical line
    cout << "20001\t" << "Donald Knuth\t" << sum_missing_nrs <<"\n";
    return 0;
}
