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
  Node* null_ptr = nullptr;

  while (head_.load() == nullptr && tail_.load() == nullptr) {
    tail_.compare_exchange_weak(null_ptr, new_tail);
    head_.compare_exchange_weak(null_ptr, new_tail);
  }

  while (true) {
    if (tail_.compare_exchange_weak(old_tail, new_tail)) {
      old_tail->next_.store(new_tail);
      break;
    }
    old_tail = tail_.load();
  }

  new_node.release();
}

template <typename T>
std::shared_ptr<T> LockFreeQueue<T>::pop() {
  while (true) {
    if (head_.load() != nullptr) {
      Node* old_head = head_.load();

      if (old_head->next_ != nullptr) {
        Node* next_node = old_head->next_.load();

        if (head_.compare_exchange_weak(old_head, next_node)) {
          std::shared_ptr<T> res(old_head->data_);
          delete old_head;
          return res;
        }
        old_head = head_.load();

      } else {
          if (head_.compare_exchange_weak(old_head, nullptr)) {
            tail_.compare_exchange_weak(old_head, nullptr);
            std::shared_ptr<T> res(old_head->data_);
            delete old_head;
            return res;
          }
          old_head = head_.load();
      }

    } else { return std::shared_ptr<T>(); }
  }
}

template class LockFreeQueue<int>;