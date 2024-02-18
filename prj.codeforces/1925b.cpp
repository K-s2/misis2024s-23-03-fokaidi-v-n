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
    int x, n;
    std::cin >> x >> n;
    int ans = 1;
    for (int i = 1; i * i <= x; i++)
    {
      if (x % i == 0)
      {
        if (n <= x / i)
          ans = std::max(ans, i);
        if (n <= i)
          ans = std::max(ans, x / i);
      }
    }
    std::cout << ans << '\n';
	}
}