#include <iostream>
#include <vector>


int main() {
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w++) {
		int n = 0;
		std::cin >> n;
		std::vector<int> a(n);
		std::vector<int> b(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int g = 0;
		for (int i = 0; i < n -1; i++) {
			int k = i;
			if (i % 2 == 0) {
				if ((a[i + 1] % 2) == (a[0] % 2)) {
					g = a[i + 1] + a[0];
					b.push_back(g);
				}
			}
		}
	}
}