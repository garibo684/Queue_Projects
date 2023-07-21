#include <thread>
#include <iostream>
#include <atomic>
#include "LockFreeQueue.h"

  void Producer(LockFreeQueue<int>& queue) {
    queue.push(1);
    std::cout << "**Produced: " << 1 << std::endl;
    queue.push(2);
    std::cout << "**Produced: " << 2 << std::endl;
    queue.push(3);
    std::cout << "**Produced: " << 3 << std::endl;
}

  void Consumer(LockFreeQueue<int>& queue) {
    std::shared_ptr<int> value1 = queue.pop();
    if (value1 != nullptr)
        std::cout << "--Received: " << *value1 << std::endl;

    std::shared_ptr<int> value2 = queue.pop();
    if (value2 != nullptr)
        std::cout << "--Received: " << *value2 << std::endl;

    std::shared_ptr<int> value3 = queue.pop();
    if (value3 != nullptr)
        std::cout << "--Received: " << *value3 << std::endl;

    std::shared_ptr<int> value4 = queue.pop();
    if (value4 == nullptr)
        std::cout << "==Queue is empty" << std::endl;
}
 
int main() {
  LockFreeQueue<int> queue;

  std::thread producer_thread(Producer, std::ref(queue));
  producer_thread.join();


  std::thread consumer_thread(Consumer, std::ref(queue));
  consumer_thread.join();

  return 0;
}