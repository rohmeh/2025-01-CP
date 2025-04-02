
/*

Name: Exponentiation
Reference: https://cses.fi/problemset/task/1095/

Problem: Your task is to efficiently calculate values a^b modulo 10^9+7.
Note that in this task we assume that 0^0=1.

Input:
The first input line contains an integer n: the number of calculations.
After this, there are n lines, each containing two integers a and b.

Output:
Print each value a^b modulo 10^9+7.

we do this question efficiently using recursion in O(logn) time

*/

#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7; //given value of m in the problem

long long int modpow(int x,int n,int m){

if(n==0){
  return 1%m;
} // Base case: x^0 = 1

long long int u=modpow(x,n/2,m); // Recursively compute (x^(n/2)) % m
u=(u*u)%m; // Square the result-->x^n

if(n%2==1){ //If 'n' is odd, multiply once more by 'x' to account for the remaining power
 u=(u*x)%m;
} 

return u;

}



int main(){
  int n;
  cin>>n; //test cases

  vector<int> answers; // answers vector to store the answers

  while(n--){
   int a,b;
   cin>>a>>b;
   answers.push_back(modpow(a,b,mod));
  }

  for(int i=0;i<answers.size();i++){
   cout<<answers[i]<<endl;
  }


 return 0;
}

