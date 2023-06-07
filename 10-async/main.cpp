#include <iostream>
#include <thread>
#include <future>

int square(int x) {
  return x*x;
}

int main() {
  std::future<int> asyncFunc{std::async(&square, 12)};

  int result{asyncFunc.get()};

  std::cout << "Result is " << result << '\n';
  return 0;
}
