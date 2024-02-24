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
		std::vector<int> a;
		for (int i = 0; i < n; i++) {
			std::cin >> d;
			m += d;
			a.push_back(d);
		}
		std::sort(a.begin(), a.end());
		int r = 0;
		int an = 0;
		int h = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < x; j++) {
				r += a[n - i - 1];
			}
			an = std::max(an, (m - r));
			a.pop_back();
		}
		std::cout << an << std::endl;
	}
}