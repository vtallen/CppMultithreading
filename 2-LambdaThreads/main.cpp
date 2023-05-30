#include <iostream>
#include <thread>


int main() {

  auto test=[](int x) {
    std::cout << "Hello from thread!" << std::endl;
    std::cout << "Argument passed in: " << x << std::endl;
  };
    std::thread myThread{test, 100};
  
    myThread.join();
    std::cout << "main() - Hello, World!" << std::endl;
    return 0;
}
