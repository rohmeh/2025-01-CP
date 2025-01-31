#include <bits/stdc++.h>
using namespace std;

int findMaxEle(vector<int> a)
{
	// function to find maximum element in a vector
	if (a.empty())
		return 1; //at least a LIS of length 1 will exist in all cases
	int maximum = a[0];
	for (int i = 0; i < a.size(); ++i)
		if (a[i] > maximum)
			maximum = a[i];
	return maximum;
}

int LIS(vector<int> a)
{
	//function to find length of longest increasing subseq
	if (a.empty())
		return 0; // in case vector has no elements

	int n = a.size();
	vector<int> len(n, 1); // initializing all lengths as 1

	//len[i] = length of LIS ending at index i
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < k; ++i)
		{
			if (a[i] < a[k])
				len[k] = max(len[k], len[i] + 1);
		}
	}
	int result = findMaxEle(len);
	return result;
}

int main()
{
	cout << "20001\t Donald Knuth\t";
	int t;
	cin >> t;
	cin.ignore();

	int length_LIS = 1;

	for (int i = 0; i < t; ++i)
	{
		string line;
		getline(cin, line);
		stringstream ss(line);

		vector<int> arr;
		int num;

		while (ss >> num)
			arr.push_back(num);

		length_LIS = LIS(arr);
		cout << length_LIS << "\n";
	}
	cout << endl;
	return 0;
}