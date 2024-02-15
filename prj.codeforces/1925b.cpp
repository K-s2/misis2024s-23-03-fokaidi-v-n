#include <iostream>
#include <vector>


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
		std::vector<int> mac_i;
		int n = 0;
		std::cin >> x >> n;
		int d = n / x + 1;
		int i = 1;
		while((x* i) < n){
			max_ = gcd(n - (x - 1) * i, i);
			i++;
		}
		std::cout << max_<<std::endl;
	}
}