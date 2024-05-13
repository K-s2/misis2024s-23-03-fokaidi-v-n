#include <iostream>
#include <vector>
#include <string>

class Robocalc {

public:
  Robocalc() : value(0.0) {
    std::string command;
    std::cin >> command >> value; // принимаем команду OUT
  }

  void rev(int n) {
    if (n > numbers.size()) {
      throw std::overflow_error("numbers of commands is less than your number");
    }
    int s = numbers.size() - 1;
    for (int s; n > 0; s--) {
      if (commands[s] == "ADD") {
        sub(numbers[s]);
      }
      else if (commands[s] == "SUB") {
        add(numbers[s]);
      }
      else if (commands[s] == "MUL") {
        if (numbers[s] == 0) {
          throw std::overflow_error("Divide by zero exception");
        }
        div(numbers[s]);
      }
      else if (commands[s] == "DIV") {
        mul(numbers[s]);
        n -= 1;
      }
    }
  }

  void calculate() {
    std::string command;
    double number;

    while (std::cin >> command >> number) {
      if (command == "REV") {
        rev(number);
      }
      if (command == "end") {
        break;
      }
      if (command == "OUT") {
        out(number);
      }
      if (command == "ADD") {
        add(number);
      }
      else if (command == "SUB") {
        sub(number);
      }
      else if (command == "MUL") {
        mul(number);
      }
      else if (command == "DIV") {
        if (number == 0) {
          throw std::overflow_error("Divide by zero exception");
        }
        div(number);
      }
    }
    std::cout << "register value is " << value;
  }

private:
  double value;
  std::vector<int> numbers;
  std::vector<std::string> commands;


  void add(double x) {
    value += x;
  }

  void sub(double x) {
    value -= x;
  }

  void mul(double x) {
    value *= x;
  }

  void div(double x) {
    if (x != 0) {
      value /= x;
    }
    else {
      std::cerr << "Error: Division by zeron";
    }
  }

  void out(double x) {
    value = x;
  }
};
