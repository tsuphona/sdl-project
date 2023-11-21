#include <list>
#include <vector>

#include "module_1.hpp"
#include "module_2.hpp"

int main() {
  module_1();
  module_2();

  // Test stuff.
  std::list<int> l = {1, 2, 3, 4, 5, 6};
  std::vector<int> v = {7, 8, 9, 10, 11, 12};

  // Test prints.
  print_list(&l);
  print_vector(&v);

  // Test binary search.
  bool found;
  found = binary_search(&v, 22);
  std::cout << found << std::endl;

  return 0;
}
