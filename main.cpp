#include "History.hpp"

#include <chrono>
#include <future>
#include <iostream>

using namespace std::chrono_literals;

int main() {

  auto h = history_t {1};

  current(h).emplace_back(0);
  current(h).emplace_back("hello");

  draw(current(h), std::cout, 0);
  std::cout << "----------------" << std::endl;

  commit(h);

  auto saving = std::async([document = current(h)]() {
    std::this_thread::sleep_for(30ms);
    std::cout << "saved-----------" << std::endl;
    draw(document, std::cout, 0);
    std::cout << "----------------" << std::endl;
  });

  current(h).emplace_back(1.38817f);
  current(h).emplace_back(current(h));

  current(h)[0] = object_t {'x'};

  draw(current(h), std::cout, 0);
  std::cout << "----------------" << std::endl;

  undo(h);

  draw(current(h), std::cout, 0);
  std::cout << "----------------" << std::endl;

  saving.wait();

}