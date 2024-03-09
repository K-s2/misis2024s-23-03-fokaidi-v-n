#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main() {
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w++) {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> first_occurrence(26, -1); // массив для хранения первого вхождения каждой буквы

    for (int i = 0; i < n; ++i) {
      if (first_occurrence[s[i] - 'a'] == -1) {
        first_occurrence[s[i] - 'a'] = i;
      }
    }

    long long result = 0;
    for (int i = 0; i < 26; ++i) {
      if (first_occurrence[i] != -1) {
        int first_idx = first_occurrence[i];
        result += 1LL * (n - first_idx) * (first_idx + 1);
      }
    }
    std::cout << result<<std::endl;
	}
}