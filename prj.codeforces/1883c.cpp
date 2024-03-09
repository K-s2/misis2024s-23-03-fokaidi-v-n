#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int t = 0;
  int u = 0;
  std::cin >> t;
  for (int w = 0; w < t; w++) {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::vector<int>a;
    int c = 1;
    int m = 0;
    int d = 0;
    int l = 0;
    int ch = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> r;
      if (r % 2 == 0) {
        ch += 1;
      }
      r = (r % k);
      a.push_back(r);
      c *= a[i];
    }
    if (c % k == 0) {
      std::cout << 0 << std::endl;
      continue;
    }
    else {
      if (k == 4) {
        for (int i = 0; i < n; i++) {
          if (1 == a[i] % k) {
            l += 1;
          }
          if (2 == a[i] % k) {
            d += 1;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        m = std::max(m, a[i] % k);
      }
    }
    if (d > 0 && l > 0) {
      std::cout << 1 << std::endl;
      continue;
    }
    else if (l > 1) {
      std::cout << std::min(2, k - m) << std::endl;
      continue;
    }
    else {
      std::cout << k - m << std::endl;
    }
  }
}