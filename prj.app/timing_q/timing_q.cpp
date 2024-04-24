#include <chrono>
#include <iostream>
#include <queuelstt/queuelstt.hpp>

int main()
{
  QueueLstT<int> q;

  auto start = std::chrono::steady_clock::now(); // Здесь начинается измерение времени

  // Добавление 10000 элементов в очередь
  for (int i = 0; i < 1000000; ++i) {
    q.Push(i);
  }

  auto end = std::chrono::steady_clock::now();   // Здесь заканчивается измерение времени

  std::chrono::duration<double, std::milli> elapsed = end - start;

  std::cout << "Pushing 1000000 elements took " << elapsed.count() << "ms.";

  return 0;
}
