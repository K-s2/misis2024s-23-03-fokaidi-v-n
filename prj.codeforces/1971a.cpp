#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
 
void solve() {
	int x, y;
	cin >> x >> y;
	cout << min(x, y) << ' ' << max(x, y) << '\n';	
}
 
int main() {
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
