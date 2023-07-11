#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
  Clear();
}

template <typename T>
void LinkedList<T>::Clear() {
  Node* current = head_;
  while (current != nullptr) {
    Node* next_node = current->next_;
    delete current;
    current = next_node;
  }
  head_ = nullptr;
  tail_ = nullptr;
  size_ = 0;
}

template <typename T>
void LinkedList<T>::Append(const T& value) {
  Node* new_node = new Node{nullptr, nullptr, value};
  if (head_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->prev_ = tail_;
    tail_->next_ = new_node;
    tail_ = new_node;
  }
  size_++;
}

template <typename T>
void LinkedList<T>::Prepend(const T& value) {
  Node* new_node = new Node{nullptr, nullptr, value};
  if (head_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->next_ = head_;
    head_->prev_ = new_node;
    head_ = new_node;
  }
  size_++;
}

template <typename T>
void LinkedList<T>::Insert(Node* prev_node, const T& value) {
  Node* new_node = new Node{nullptr, nullptr, value};
  if (head_ == nullptr) {
    head_ = new_node;
    tail_ = new_node;
  } else {
    new_node->next_ = prev_node->next_;
    prev_node->next_ = new_node;
    new_node->prev_ = prev_node;
    if (new_node->next_ != nullptr) {
      new_node->next_->prev_ = new_node;
    }
  }
  size_++;
}

template <typename T> 
void LinkedList<T>::Delete() {
  if (size_ != 0) {
    if (size_ == 1) {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
      size_ = 0;
    } 
    else if (size_ > 1) {
      tail_ = tail_->prev_;
      delete tail_->next_;
      tail_->next_ = nullptr;
      size_--;
    }
    else {return;}
  }
}

template <typename T>
const T& LinkedList<T>::GetHead() const {
  return head_->data_;
}

template <typename T>
const T& LinkedList<T>::GetTail() const {
  return tail_->data_;
}

template <typename T>
bool LinkedList<T>::GetEmpty() const {
  return size_ == 0;
}

template <typename T>
std::size_t LinkedList<T>::GetSize() const {
  return size_;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetHeadPtr() const {
  return head_;
}

template class LinkedList<int>;