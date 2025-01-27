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
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;cin>>n;
        vector<long long> v;
        long long x;
        cin>>x;
        v.push_back(x);
        long long ans=0;
        for(long long i=0;i<n-1;i++)
        {
            long long y;
            cin>>y;
            if(y<v.back())
            {
                ans+=(v.back()-y);
            }
            else v.push_back(y);
        }
        //Critical line
        cout << "20001\t" << "Donald Knuth\t" << ans <<"\n";
    }
}
