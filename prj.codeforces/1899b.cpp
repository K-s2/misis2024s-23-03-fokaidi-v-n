#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> D (int a) {
	int l = 1;
	std::vector<int> ans;
	while (l < a) {
		if (a % l == 0) {
			ans.push_back(l);
		}
		l++;
	}
	return(ans);
}


int main() {
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w++) {
		int k = 0;
		std::cin >> k;
		std::vector<int> b;
		b = D(k);
		std::vector<int> a(k);
		for (int i = 0; i < k; i++) {
			std::cin >> a[i];
		}
		int ans = 0;
		int m = 0;
		int n = 0;
		if (k == 1) {
			std::cout << 0;
			continue;
		}
		for (int i = 1; i < b.size(); i++) {
			for (int j = 0; j < b[i]; j++) {
				m += b[j];
			}
			ans = std::max(ans, abs(ans - m));
		}
		std::cout << ans<<std::endl;
	}
}