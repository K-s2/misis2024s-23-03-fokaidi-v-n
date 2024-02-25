#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  for (int t = 0; t < n; t++) {
    int m, k;
    std::cin >> m >> k;
    std::vector<int> a(m);
    for (int i = 0; i < m; i++) std::cin >> a[i];
    std::vector<int> b(k);
    for (int i = 0; i < k; i++) std::cin >> b[i];
    std::sort(a.begin(), a.end());
    std::sort(b.rbegin(), b.rend());
    std::vector<int> c(m);
    long long s = 0;
    for (int i = 0; i < m; i++) {
      c[i] = b[k - m + i];
      s += std::abs(c[i] - a[i]);
    }
    long long res = 0;
    for (int j = 0; j <= m; j++) {
      res = std::max(res, s);
      if (j < m) {
        s -= std::abs(c[j] - a[j]);
        c[j] = b[j];
        s += std::abs(c[j] - a[j]);
      }
    }
    std::cout << res << "\n";
  }
  return 0;
}
