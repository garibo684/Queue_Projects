#include "LinkedList.h"
#include <iostream>

int main() {
  LinkedList<int> list;

  std::cout << "-Is Empty: " << list.GetEmpty() << std::endl;

  list.Append(15);
  std::cout << "\n---Append(15)" << std::endl;
  list.Prepend(5);
  std::cout << "---Prepend(5)" << std::endl;
  list.Insert(list.GetPosition(5), 10);
  std::cout << "---Insert(10) After Head" << std::endl;

  std::cout << "-Size: " << list.GetSize() << "  Head Value: " << list.GetHead() << "  Tail Value: " << list.GetTail() << std::endl;

  list.Delete();
  std::cout << "\n---Delete" << std::endl;
  std::cout << "-Tail Value: " << list.GetTail() << std::endl;

  list.Delete();
  std::cout << "\n---Delete" << std::endl;
  std::cout << "-Size: " << list.GetSize() << "  Tail Value: " << list.GetTail() << std::endl;

 list.Append(50);
  std::cout << "\n---Append(50)" << std::endl;
  std::cout << "-Is Empty: " << list.GetEmpty() << std::endl;

  list.Clear();
  std::cout << "\n---Clear" << std::endl;
  std::cout << "-Is Empty: " << list.GetEmpty() << std::endl;

  return 0;
}