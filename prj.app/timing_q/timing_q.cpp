#include <chrono>
#include <iostream>
#include <string>
#include <queuelstt/queuelstt.hpp>
#include <queuearrt/queuearrt.hpp>

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
  std::cout << "Pushing 1, 2, 3, ....1000000 in queuelst elements took " << elapsed.count() << "ms."<<std::endl;


  QueueLstT<std::string> qs;
  std::string s = "1";
  auto start1 = std::chrono::steady_clock::now(); // Здесь начинается измерение времени
  for (int i = 0; i < 1000000; ++i) {
    qs.Push(s);
  }
  auto end1 = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> elapsed1 = end1 - start1;
  std::cout << "Pushing 1000000 '1' took in queuelst " << elapsed1.count() << "ms." << std::endl;


  QueueLstT<float> qf;
  float a{ 0.1 };
  auto start2 = std::chrono::steady_clock::now();
  for (int i = 0; i < 1000000; i++) {
    a += i;
    qf.Push(a);
  }
  auto end2 = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli>ellapsed2 = end2 - start2;
  std::cout << "Pushing 1.1, 3.1, 6.1, ....500000500000.1 in queuelst elements took" << ellapsed2.count() << "ms." << std::endl;


  QueueArrT<int> qai;
  auto start3 = std::chrono::steady_clock::now();
  for (int i = 0; i < 1000000; i++) {
    qai.Push(i);
  }
  auto end3 = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> ellapsed3 = end3 - start3;
  std::cout << "Pushing 1, 2, 3, ....1000000 in queuearr elements took " << elapsed.count() << "ms." << std::endl;


  QueueArrT<std::string> qas;
  std::string sa = "1";
  auto start4 = std::chrono::steady_clock::now(); // Здесь начинается измерение времени
  for (int i = 0; i < 1000000; ++i) {
    qas.Push(sa);
  }
  auto end4 = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> elapsed4 = end4 - start4;
  std::cout << "Pushing 1000000 '1' took in queuearr " << elapsed4.count() << "ms." << std::endl;


  QueueArrT<float> qaf;
  float f{ 0.1 };
  auto start5 = std::chrono::steady_clock::now();
  for (int i = 0; i < 1000000; ++i) {
    f += i;
    qaf.Push(f);
  }
  auto end5 = std::chrono::steady_clock::now();
  std::chrono::duration<double, std::milli> ellapsed5 = end5 - start5;
  std::cout << "Pushing 1.1, 3.1, 6.1, ....500000500000.1 in queuearr elements took" << ellapsed5.count() << "ms." << std::endl;

  return 0;
}
