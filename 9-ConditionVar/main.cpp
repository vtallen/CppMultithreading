#include <condition_variable>
#include <iostream>
#include <mutex>
#include <atomic>
#include <thread>
#include <vector>

std::mutex g_lock;
std::condition_variable g_conditionVar;

int main() {
  int result{0};
  bool notified{false};

  // Reporting thread
  // Must wait on work being done in the worker thread
  std::thread reporter([&](){
    std::unique_lock<std::mutex> lock{g_lock};
    if (!notified) {
      g_conditionVar.wait(lock);
    }
    std::cout << "Reporter result is: " << result << "\n";
  });
  

  // Working thread
  std::thread worker([&](){
    std::unique_lock<std::mutex> lock{g_lock};
    result = 10 + 5 * 2;
    notified = true;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Work complete\n";

    g_conditionVar.notify_one();
  });
  
  reporter.join();
  worker.join();
  return 0;
}
