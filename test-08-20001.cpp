/*
Name: Tower of Hanoi
Reference: https://cses.fi/problemset/task/2165

The Tower of Hanoi game consists of three stacks (left, middle and right)
and n round disks of different sizes.
Initially, the left stack has all the disks, 
in increasing order of size from top to bottom.
The goal is to move all the disks to the right stack 
using the middle stack. 
On each move you can move the uppermost disk from a stack 
to another stack.
In addition, it is not allowed to place a larger disk on a smaller disk.
Your task is to find a solution that minimizes the number of moves.

Input: There are t test cases. In each test case, you are given an intger n.

Output: For each case, first print an integer k: the minimum number of moves.
After this, print k lines that describe the moves. 
Each line has two integers a and b: you move a disk from stack a to stack b. 
*/

#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> moves;

void TOH(int n, int source, int target, int auxiliary){
    if (n == 0){
        return;
    }

    TOH(n-1,source,auxiliary,target);

    moves.push_back({source,target});

    TOH(n-1,auxiliary,target,source);
}

int main(){
    cout << "20001 \t" << "Donald Knuth3 \t";

    int n;
    cin >> n;

    TOH(n,1,3,2);

    cout << moves.size() << endl;


    for(auto i : moves){
        cout << i.first << " " << i.second;
        cout << endl;
    }

    cout << endl;
    return 0;
}