#ifndef LINKEDLISTQUEUE_LINKEDLIST_H
#define LINKEDLISTQUEUE_LINKEDLIST_H

#include<cstddef>

template <typename T>
class LinkedList {
 private:
   struct Node
   {
     Node* next_;
     Node* prev_;
     T data_;
   };

 public:
    LinkedList();
    ~LinkedList();

    void Append(const T& value);
    void Prepend(const T& value);
    void Insert(Node* prev_node, const T& value);
    void Delete();
    void Clear();
    void GetList() const;
    const T& GetHead() const;
    const T& GetTail() const;
    bool GetEmpty() const;
    std::size_t GetSize() const;
    Node* GetPosition(const T& value) const;

 private:
    Node* head_;
    Node* tail_;
    std::size_t size_;
};

#endif