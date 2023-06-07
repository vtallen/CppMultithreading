#include <iostream>
#include <thread>
#include <vector>

int main() {

  auto test=[](int x) {
    std::cout << "Hello from thread: " << std::this_thread::get_id() << " | Argument passed in: " << x << '\n'; 
  };
    
    std::vector<std::thread> threads;
  for (int i{0}; i < 10; ++i) {
    threads.push_back(std::thread{test, i});
  }

  for (auto &thread : threads) {
    thread.join();
  }

    std::cout << "main() - Hello, World!" << std::endl;
    return 0;
}
