#include <bits/stdc++.h>
using namespace std;

int N, M;

void isConnected(int i, int j, vector<vector<char>> &A)
{
	//we want these changes to happen in the original grid
	//so we use '&' operator
	queue<pair<int, int>> q;
	q.push({i, j});
	while (q.size() > 0)
	{
		pair<int, int> pos = q.front();
		q.pop();
		i = pos.first, j = pos.second;
		A[i][j] = '#';//this makes sure we check a dot only once
		if (i + 1 < N)
		{
			if (A[i + 1][j] == '.') //moving down
				q.push({i + 1, j});
		}
		if (j + 1 < M)
		{
			if (A[i][j + 1] == '.') //moving to right
				q.push({i, j + 1});
		}
	}
}

int main()
{
	cout << "20001\t Donald Knuth\n";
	int n, m;
	cin >> n >> m;
	cin.ignore();

	N = n, M = m;

	vector<vector<char>> A(n, vector<char> (m));
	for (int i = 0; i < n; i++)
	{
		string num;
		getline(cin, num);

		for (int j = 0; j < m; ++j)
			A[i][j] = num[j];
	}
	int rooms = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (A[i][j] == '.')
			{
				rooms++;
				isConnected(i, j, A);
				//we can think of rooms being formed by dots that are connected
				//we can check connectivity by using idea similar to BFS
			}
		}
	}
	cout << rooms << endl;
	return 0;
}