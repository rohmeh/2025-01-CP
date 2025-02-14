#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "20001\t Donald Knuth\t";
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i].first >> arr[i].second;

	sort(arr.begin(), arr.end());//sorting according to duration
	int reward = 0, time = 0;
	int r;
	for (int i = 0; i < n; ++i)
	{
		//total time taken by a task t= duration of all tasks performed uptil now + duration of t
		time += arr[i].first;
		r = arr[i].second - time;
		reward += r;
	}
	cout << reward << endl;
	return 0;
}