#ifndef LOCKFREEQUEUE_LOCKFREEQUEUE_H
#define LOCKFREEQUEUE_LOCKFREEQUEUE_H

#include <atomic>
#include <memory>

template <typename T>
class LockFreeQueue {
 private:
   struct Node {
     std::shared_ptr<T> data_;
     std::atomic<Node*> next_;
     Node(const T& data) : data_(std::make_shared<T>(data)), next_(nullptr) {}
   };
   std::atomic<Node*> head_;
   std::atomic<Node*> tail_;

 public:
   LockFreeQueue();
   LockFreeQueue(const LockFreeQueue& other) = delete;
   LockFreeQueue& operator=(const LockFreeQueue& other) = delete;

   ~LockFreeQueue();

   void push(const T& data);

   std::shared_ptr<T> pop();
};
#endif