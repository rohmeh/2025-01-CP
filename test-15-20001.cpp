#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> a, const pair<int, int> b)
{
	//function to compare two items based on value/weight ratio
	double a_ratio = ((double)a.first / a.second);
	double b_ratio = ((double)b.first / b.second);
	return a_ratio > b_ratio;
}

double FracKnap(vector<pair<int, int>> a, int n, int W)
{
	//func to implement Greedy Algo for fractional knapsack
	double P = 0.0;
	int v, w;
	for (int i = 0; i < n; ++i)
	{
		v = a[i].first;
		w = a[i].second;
		if (w <= W) {
			P += v;
			W -= w;
		}
		else {
			P += ((double)W / w) * v;
			W = 0;
			break;
		}
	}
	return P;
}

int main()
{
	cout << "20001\t Donald Knuth\t";
	int n, W;
	cin >> n >> W;
	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i].first >> arr[i].second;

	sort(arr.begin(), arr.end(), compare); // sorting the items based on value/weight ratio

	double result = FracKnap(arr, n, W);
	cout << result << endl;
	return 0;
}