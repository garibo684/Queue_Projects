#include <thread>
#include <iostream>
#include "LockFreeQueue.h"

void Producer(LockFreeQueue<int>& queue) {
  for (int i = 1; i<=1000; ++i) {
    queue.push(i);
    //std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "**Produced: " << i << std::endl;
  }
}

void Consumer(LockFreeQueue<int>& queue) {
  std::shared_ptr<int> value;
  bool empty = true;
  std::this_thread::sleep_for(std::chrono::milliseconds(5));

  do {
    value = queue.pop();
    if (value) {
      std::cout << "--Received: " << *value << std::endl;
      empty = false;
    } else {
      std::cout << "==Queue is empty" << std::endl;
    }
   // std::this_thread::sleep_for(std::chrono::milliseconds(50));
  } while (value || empty);
}


int main() {
  LockFreeQueue<int> queue;

  std::thread producer_thread(Producer, std::ref(queue));
  std::thread consumer_thread(Consumer, std::ref(queue));

  producer_thread.join();
  consumer_thread.join();

  return 0;
}