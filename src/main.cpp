#include "base/Thread.h"
#include "co_context/generator.h"
#include "co_context/Task.h"
#include <coroutine>
#include <iostream>

Task<int> hello2() {
  std::cout << "Hello, World! func2" << std::endl;

  co_return 100;
}

Task<int> hello() {
    auto ans = co_await hello2();

  co_return ans;
}

int main() {
  std::cout << "Hello, World!" << std::endl;

  auto mytask = hello();

  mytask.then([](int i){
    std::cout << "the res is " << i << std::endl;
  });

  auto res = mytask.get_result();
    std::cout << "the res is " << res << std::endl;


  return 0;
}