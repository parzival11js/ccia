#include "threadsafe_stack.h"

#include <iostream>
#include <thread>

ccia::ThreadSafeStack<int32_t> my_stack;

void Produce() {
  std::cout << "my stack push 1" << std::endl;
  my_stack.Push(1);
}

void Consume() {
  try {
    std::cout << "my_stack pop: " << *(my_stack.Pop().get()) << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "my_stack pop exception: " << e.what() << std::endl;
  }
}

int main() {
  std::thread tp(Produce);
  std::thread tc(Consume);
  tp.join();
  tc.join();

  return 0;
}