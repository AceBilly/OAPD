module;

#include <cmath>
#include <vector>
#include <limits>

#include <array>

export module sort;


//-------------------------------------------------
// 此地方都为concepts 最终提交版本都将替换为 import utility.ixx;
export template <typename T>
concept Comparable = requires(T a, T b) {
  a > b;
  a < b; 
  a == b;
  a <= b;
  a >= b;
};
//-------------------------------------------------

export template <Comparable T, size_t N>
void insert_sort(T (&data)[N]) {
  for (int i = 1; i < N; ++i) {
    T key = data[i];
    int j = i - 1;
    while (j >= 0 && data[j] > key) {
      data[j + 1] = data[j];
      --j;
    }
    data[j + 1] = key;
  }
}

template<Comparable T, size_t N>
void merge(T(&data)[N], unsigned int begin, unsigned int mid,
    unsigned int end) {
  int index_left = begin;
  int index_right = mid;

  int index_temp = 0;
  /*std::vector<int> temp{};
  const int length = end - begin;
  temp.resize(length);
  std::fill(temp.begin(), temp.end(), 0);*/
  T* temp = new (T[end + 1 - begin]);

  while (index_left < mid && index_right <= end) {
    *(temp + (index_temp++)) = (data[index_left] <= data[index_right]) ? data[index_left++]
                                                 : data[index_right++];
  }
  while (index_left < mid) {
    *(temp + (index_temp++)) = data[index_left++];
  }
  while (index_right <= end) {
    *(temp + (index_temp++)) = data[index_right++];
  }

  index_temp = 0;
  while (begin <= end) {
    data[begin++] = *(temp + (index_temp++));
  }
  delete[] temp;
}
export template <Comparable T, size_t N>
void merge_sort(T (&data)[N], unsigned int begin, unsigned int end) {
  if (begin < end) {
    unsigned int middle = std::trunc((begin + end) / 2.0);
    merge_sort(data, begin, middle);
    merge_sort(data, middle + 1, end);
    merge(data, begin, middle + 1, end);
  } else {
    return;
  }
}