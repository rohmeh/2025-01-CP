/*
Name: Counting Divisors
Reference: https:https://cses.fi/problemset/task/1713


Problem:Given n integers, your task is to report for each integer the number of its divisors.
For example, if x=18, the correct answer is 6 because its divisors are 1,2,3,6,9,18.

Input:The first input line has an integer n: the number of integers.
After this, there are n lines, each containing an integer x.

Output:For each integer, print the number of its divisors.*/


#include <bits/stdc++.h>
using namespace std;

int divisors(int num){ //function to count the number of divisors

  int count=0;
  for(int i=1;i<=sqrt(num);i++){
    if(num%i==0){
      if(num/i==i)
       count++;
      else 
       count+=2;
    }
  }
  return count;
}

int main(){

  int n; //number of integers.
  cin>>n;
  int arr[n];

  for(int i=0;i<n;i++){
   cin>>arr[i];
  }

  for(int i=0;i<n;i++){
   cout<<divisors(arr[i])<<"\n";
  }

  return 0;
}
