#include <iostream>
#include <thread>
#include <vector>


int main() {

  auto test=[](int x) {
    std::cout << "Hello from thread: " << std::this_thread::get_id() << " | Argument passed in: " << x << '\n'; 
  };
    
    std::vector<std::jthread> threads;
  for (int i{0}; i < 10; ++i) {
    threads.push_back(std::jthread{test, i});
  }

  for (auto &thread : threads) {
    thread.join();
  }

    std::cout << "main() - Hello, World!" << '\n';
    return 0;
}
