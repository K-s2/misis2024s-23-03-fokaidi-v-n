#include <iostream>
#include <vector>
#include <algorithm>


int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}


int main() {
	int t = 0;
	std::cin >> t;
	for (int r = 0; r < t; r++) {
		int x = 0;
		int max_ = 0;
		int n = 0;
		std::cin >> x >> n;
		int d = 0;
		d = x / n ;
		//std::cout << n;
		int i = d;
		int p = x/ d;
		while ((n * i) < x) {
			max_ = std::max(gcd(x - p* i, i), max_);
			i++;
		}
		std::cout << max_ << std::endl;
	}
}