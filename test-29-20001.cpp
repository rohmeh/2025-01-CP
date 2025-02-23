//TEST 29 Flight Discount


// Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.
// When you use the discount coupon for a flight whose price is x, its price becomes \lfloor x/2 \rfloor (it is rounded down to an integer).
// Input
// The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,\ldots,n. City 1 is Syrjälä, and city n is Metsälä.
// After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. Each flight is unidirectional.
// You can assume that it is always possible to get from Syrjälä to Metsälä.
// Output
// Print one integer: the price of the cheapest route from Syrjälä to Metsälä.

// Constraints:

// 2 <= n <= 10^5
// 1 <= m <= 2 * 10^5
// 1 <= a,b <= n
// 1 <= c <= 10^9

// Example

// Input:
// 3 4
// 1 2 3
// 2 3 1
// 1 3 7
// 2 1 5

// Output:
// 2

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxd = 1e17;


int n,m;
vector<vector<pair<int, ll>>> g;
// vector<vector<int>> track;
vector<pair<ll, ll>> dis; //'dis' is a vactor of pair which stores {dist to node i without using coupon, dist to node i if coupon is used at some step}



void dij(){
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;

	pq.push({0,{0,0}}); // (cost, node, 1 if coupon USED and 0 if coupon NOT USED)
	dis[0] = {0,0};
	while(!pq.empty()){
		ll pd = pq.top().first;		//We store cost first in the min heap since we need the heap to sort by cost.
		int pn = pq.top().second.first;	//pd (parent distance/cost), pn(parent node), pc (parent coupon used or not)
		int pc = pq.top().second.second;
		pq.pop();

		if(pc && pd>dis[pn].second) continue;
		if(!pc && pd>dis[pn].first) continue;

		for(auto c: g[pn]){
			int cn = c.first;	//cn(parent node)
			ll cc = c.second;	//cc (child cost with no coupon)
			ll cdc = c.second/2;	//cdc (child cost after using coupon)

			if(!pc){	//If coupon has NOT been used till parent

				if(pd + cc < dis[cn].first){	//If child cost is better throgh this parent even without using coupon for child
					pq.push({pd+cc, {cn, 0}});
					dis[cn].first = pd + cc;
				}
			
				if(pd + cdc < dis[cn].second){	//If child cost is better through this parent if child uses coupon
					pq.push({pd+cdc, {cn, 1}});
					dis[cn].second = pd + cdc;
				}
			}

			if (pc){	//If coupon Hhas already been used before child
				if(pd + cc < dis[cn].second){	//If child cost is better through this parent
					pq.push({pd+cc, {cn, 1}});	
					dis[cn].second = pd+cc;
				}

			}
		}
	}
}

int main(){
	cin >> n >> m;

	g.resize(n);
	dis.resize(n, {maxd, maxd});

	for(int i =0; i<m; i++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--; b--;	//g[i] corresponds to adjacency list of node i+1
		g[a].push_back({b, c}); //Maintains a graph adjacency list of pair {neighbour node, cost}
	}

	dij();

	cout << dis[n-1].second << endl;

	return 0;
}