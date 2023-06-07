#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

static int sharedValue{0};
std::mutex g_lock;
void sharedValueIncrement() {
  g_lock.lock();
  ++sharedValue;
  g_lock.unlock();
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
