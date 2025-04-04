#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int BinoCoeff(int n, int k)
{
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 1; //(iC0 = 1)
		if (i <= k)
			dp[i][i] = 1; //(iCi = 1)
	}
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; j <= min(i, k); ++j)
			if (i != j)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
	}
	return dp[n][k];
}

int main()
{
	cout << "20001\t Donald Knuth\t";
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		int result = BinoCoeff(a, b);
		cout << result << "\n";
	}
	cout << endl;
	return 0;
}