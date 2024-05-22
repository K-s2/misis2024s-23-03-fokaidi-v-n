#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <queuelstt/queuelstt.hpp>
#include <cstdio>
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
  std::cout << "Pushing 1, 2, 3, ....1000000 in queuelst elements took " << elapsed.count() << "ms." << std::endl;


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

  //...
  std::ofstream dataFile1, dataFile2;
  dataFile1.open("timingData1.txt");
  dataFile2.open("timingData2.txt");

  // Данные для QueueLstT
  dataFile1 << "DataType Time"<<std::endl;
  dataFile1 << "Int " << elapsed.count() << std::endl;
  dataFile1 << "String " << elapsed1.count() << std::endl;
  dataFile1 << "Float " << ellapsed2.count() << std::endl;

  // Данные для QueueArrT
  dataFile2 << "DataType Time" << std::endl;
  dataFile2 << "Int " << ellapsed3.count() << std::endl;
  dataFile2 << "String " << elapsed4.count() << std::endl;
  dataFile2 << "Float " << ellapsed5.count() << std::endl;

  dataFile1.close();
  dataFile2.close();

  // Создайте файлы .gp с вашими инструкциями для gnuplot
  std::ofstream gpFile1, gpFile2;
  gpFile1.open("gnuplotInstructions1.gp");
  gpFile2.open("gnuplotInstructions2.gp");

  gpFile1 << "set terminal png"<<std::endl;
  gpFile1<<"set title 'Data Pushing Timing" << std::endl;
  gpFile1 << "set xlabel 'Data Type'"<<std::endl;
  gpFile1 << "set ylabel 'Time (ms)'" << std::endl; 
  gpFile1 << "set style data histogram" << std::endl;
  gpFile1 << "set style histogram cluster gap 1" << std::endl;
  gpFile1 << "set style fill solid" << std::endl;
  gpFile1<< "set boxwidth 1" << std::endl;
  gpFile1 << "set grid ytics" << std::endl;
  gpFile1 << "set output 'QueueLstTPlot.png'" << std::endl;
  gpFile1 << "plot  'timingData1.txt' using 2:xtic(1) title columnheader" << std::endl;
  gpFile2 << "set terminal png" << std::endl; 
  gpFile2 << "set title 'Data Pushing Timing" << std::endl;
  gpFile2 << "set xlabel 'Data Type'" << std::endl;
  gpFile2 << "set ylabel 'Time (ms)'" << std::endl;
  gpFile2<<"set style data histogram" << std::endl;
  gpFile2 << "set style histogram cluster gap 1" << std::endl;
  gpFile2 << "set style fill solid" << std::endl;
  gpFile2 <<"set boxwidth 1" << std::endl;
  gpFile2 << "set grid ytics" << std::endl;
  gpFile2 << "set output 'QueueArrTPlot.png'" << std::endl;
  gpFile2 << "plot 'timingData2.txt' using 2:xtic(1) title columnheader"<<std::endl;
  //std::string settings = "set terminal pngnset title 'Data Pushing Timing'n"
  //  "set xlabel 'Data Type'nset ylabel 'Time (ms)'nset style data histogramn"
  //  "set style histogram cluster gap 1nset style fill solidnset boxwidth 1n"
  //  "set grid yticsnplot '";




  gpFile1.close();
  gpFile2.close();


  // Запустите gnuplot с вашими файлами инструкций
  system("gnuplot gnuplotInstructions1.gp");
  system("gnuplot gnuplotInstructions2.gp");

  return 0;

}
