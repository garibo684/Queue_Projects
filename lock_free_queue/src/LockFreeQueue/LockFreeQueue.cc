#include "LockFreeQueue.h"

template <typename T>
LockFreeQueue<T>::LockFreeQueue() : head_(nullptr), tail_(nullptr) {}

template <typename T>
LockFreeQueue<T>::~LockFreeQueue() {
  Node* current = head_;
  while (current != nullptr) {
    Node* next_node = current->next_;
    delete current;
    current = next_node;
  }
}

template <typename T>
void LockFreeQueue<T>::push(const T& data) {
  std::unique_ptr<Node> new_node(new Node(data));
  Node* new_tail = new_node.get();
  Node* old_tail = tail_.load();

  if (head_.load() == nullptr) {
    head_.store(new_tail);
    tail_.store(new_tail);
  } else {
      old_tail->next_.store(new_tail);
      tail_.compare_exchange_weak(old_tail, new_tail);
  }
  new_node.release();
}

template <typename T>
std::shared_ptr<T> LockFreeQueue<T>::pop() {
  Node* old_head = head_.load();
    if (old_head == nullptr) {
      return std::shared_ptr<T>();
    } else {
      if (old_head->next_ != nullptr) {
          head_.compare_exchange_weak(old_head, old_head->next_);
      } else {
          head_.store(nullptr);
          tail_.store(nullptr);
          }
    std::shared_ptr<T> res(old_head->data_);
    delete old_head;
    return res;
    }
}

template class LockFreeQueue<int>;
