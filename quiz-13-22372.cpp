#include <iostream>
#include <vector>
#include <utility> // For using pair STL feature
using namespace std;

bool can_empty_coin_piles(int a, int b) {
	if (b > 2*a || a > 2*b) return false;
	if ((a + b) % 3 != 0) return false;
	return true;
}

int main() {
	cout << "22372 \t" << "Vivek Kumar \t";

	int t = 0;
	cin >> t;
	vector<pair<int, int>> coins(t);
	for(int i = 0; i<t; i++) cin >> coins[i].first >> coins[i].second;

	int ans = 0;
	for(int i = 0; i<t; i++) {
		ans += can_empty_coin_piles(coins[i].first, coins[i].second;
	}
	cout << ans;
	cout << endl;
	return 0;
}