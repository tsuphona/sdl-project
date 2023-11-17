#include <iostream>
#include <list>
#include <vector>

int module_1() {
  std::cout << "This is module 1!" << std::endl;
  return 0;
}

int print_list(const std::list<int> *lst_ptr) {

  std::list<int> lst;
  lst = *lst_ptr;

  std::cout << "[ ";
  for (int element : lst) {
    std::cout << element << " ";
  }
  std::cout << "]" << std::endl;

  return 0;
}

int print_vector(const std::vector<int> *vec_ptr) {

  std::vector<int> vec;
  vec = *vec_ptr;

  std::cout << "[ ";
  for (int element : vec) {
    std::cout << element << " ";
  }
  std::cout << "]" << std::endl;

  return 0;
}

bool binary_search(const std::vector<int> *vec_ptr, int num) {

  int size = vec_ptr->size();
  int left_ind = 0;
  int right_ind = size - 1;
  int mid_ind;

  while (left_ind <= right_ind) {

    mid_ind = left_ind + (right_ind - left_ind) / 2;

    if (vec_ptr->at(mid_ind) == num) {
      return true;
    } else if (vec_ptr->at(mid_ind) < num) {
      left_ind = mid_ind + 1;
    } else {
      right_ind = mid_ind - 1;
    }
  }
  return false;
}
