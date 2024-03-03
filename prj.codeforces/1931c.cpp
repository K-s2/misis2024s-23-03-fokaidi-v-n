#include <iostream>
#include <vector>
#include <algorithm>


int main() {
  int t;
  std::cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int j = 0; j < n; j++) {
      std::cin >> a[j];
    }

    int i1 = 0, i2 = 0;
    while (i1 < n && a[i1] == a[0]) {
      i1++;
    }
    while (i2 < n && a[n - i2 - 1] == a[n - 1]) {
      i2++;
    }

    int res = n;
    if (a[0] == a[n - 1]) {
      res -= i1;
      res -= i2;
    }
    else {
      res -= std::max(i1, i2);
    }

    std::cout << std::max(0, res) << std::endl;
  }

  return 0;
}
