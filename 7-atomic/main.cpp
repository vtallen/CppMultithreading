#include <iostream>
#include <mutex>
#include <atomic>
#include <thread>
#include <vector>

static std::atomic<int> sharedValue{0};

void sharedValueIncrement() {
  ++sharedValue;
}

int main() {

  std::vector<std::thread> threads;
  for (int i{0}; i < 1000; ++i) {
    threads.push_back(std::thread{&sharedValueIncrement});
  }

  for (auto &thread : threads) {
    thread.join();
  }

  std::cout << sharedValue << '\n';
  std::cout << "main() - Hello, World!" << '\n';
  return 0;
}
