#include <iostream>
#include <string>


int main() {
	int t = 0;
	std::cin >> t;
	for (int r = 0; r < t; r++) {
		std::string s;
		std::cin.ignore();
		std::cin >> s;
		std::string id;
		int n = (s.rfind('0'));
		if (n == std::string::npos) {
			for (int i = 0; i <( s.length()-1); i++) {
				id += s[i];
			}
			std::cout << id<<std::endl;
			continue;
		}
		for (int i = 0; i < n; i++) {
			id += s[i];
		}
		std::cout << id<<std::endl;
	}
}