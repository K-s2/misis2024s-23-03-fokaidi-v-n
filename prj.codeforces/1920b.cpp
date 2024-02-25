#include <iostream>
#include <vector>
#include <algorithm>


int main() {
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w++) {
		int n, k, x = 0;
		std::cin >> n;
		std::cin >> k;
		std::cin >> x;
		int d = 0;
		int m = 0;
		int y = n + 1;
		std::vector<int> a(y);
		for (int i = 0; i < n; i++) {
			std::cin >> d;
			m += d;
			a.push_back(d);
		}
		std::sort(a.begin(), a.end(),	std::greater<int>());
		int r = 0;
		d = 0;
		int an = -1e9;
		int h = 0;
		for (int i = 0; i < x; i++) {
			d += a[n - i - 1];
			a[i] += a[i + 1];
		}
		for (int j = 0; j <= k; j++) {
			an = std::max(an, a[n] - 2 * a[std::min(j + x, n)] + a[j]);
		}
		std::cout << an << std::endl;
	}
}