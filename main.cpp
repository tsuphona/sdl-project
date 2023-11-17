#include "modules/module_1/include/module_1.hpp"
#include "modules/module_2/include/module_2.hpp"
#include <list>
#include <vector>

int main() {
  module_1();
  module_2();

  // Test stuff.
  std::list<int> l = {1, 2, 3, 4, 5, 6};
  std::vector<int> v = {7, 8, 9, 10, 11, 12};

  std::cout << "[ ";
  for (int element : l) {
    std::cout << element << " ";
  }
  std::cout << "]" << std::endl;

  std::cout << "[ ";
  for (int element : v) {
    std::cout << element << " ";
  }
  std::cout << "]" << std::endl;

  return 0;
}
