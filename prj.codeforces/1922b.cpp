#include <iostream>
#include <vector>

int s(int a, int b) {
	int ans = 1;
	while (b > 0) {
		ans = ans*a;
		b--;
	}
	return ans;
}

int main() {
	int t = 0;
	std::cin >> t;
	for (int r = 0; r < t; t++) {
		int counter = 0;
		int n = 0;
		std::cin >> n;
		std::vector<int> a;
		for (int i = 0; i < n; i++) {
			int w = 0;
			std::cin >> w;
			a.push_back(w);
		}
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					if ((s(2, a[i]) + (s(2, a[j]) > (s(2, a[k])))) && ((s(2, a[j]) + (s(2, a[k]) > (s(2, a[i]))))) && ((s(2, a[i]) + (s(2, a[k]) > (s(2, a[j])))))) {
						counter++;
					}
				}
			}
		}
		std::cout << counter << std::endl;
	}
}