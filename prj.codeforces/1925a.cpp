#include <iostream>
#include <string>


int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int k = 0;
		int n = 0;
		std::cin >> n;
		std::cin >> k;
		std::string s;
		s = "abcdefghijklmnopqrstuvwxyz";
		std::string l;
		for (int b = 0; b < n; b++) {
			for (int j = 0; j < k; j++) {
				l += s[j];
			}
		}
		std::cout << l << std::endl;
	}

}