#include <chrono>
#include <iostream>
#include <thread>
#include <future>

bool bufferedFileLoader() {
  size_t bytesLoaded{0};
  while (bytesLoaded < 20000) {
    std::cout << "thread: loading file...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    bytesLoaded += 1000;
  }
  return true;
}

int main() {
  std::future<bool> backgroundThread{std::async(std::launch::async, &bufferedFileLoader)};

  std::future_status status;
  while (true) {
    std::cout << "Main thread is running\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    status = backgroundThread.wait_for(std::chrono::milliseconds(1));
    
    if (status == std::future_status::ready) {
      std::cout << "Our data is ready...";
      break;
    }
  }


  return 0;
}
