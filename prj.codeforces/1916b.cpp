#include <iostream>

long gcd(int a, int b) {
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
	for (int d = 0; d < t; d++) {
		long a = 0;
		long long b = 0;
		std::cin >> a >> b;
		long n = gcd(a, b);
		if (b % a == 0) {
			long long dd = 0;
			dd = b / a;
			std::cout <<dd*b << std::endl;
			continue;
		}
		else {
			std::cout<< b * a/n<<std::endl;
			continue;
		}
	}
}