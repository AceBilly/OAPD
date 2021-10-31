module;

#include <cmath>
#include <vector>
#include <limits>

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

export template<Comparable T, size_t  N>
void merge_sort(T (&data)[N], unsigned int begin, unsigned int end) {
  if (begin < end) {
    unsigned int middle = std::round((begin + end) / 2.0);
    merge_sort(data, begin, middle);
    merge_sort(data, middle + 1, end);
    merge(data, begin, middle, end);
  } else {
    return;
  }
}
template<Comparable T, size_t N>
void merge(T(&data)[N], unsigned int begin, unsigned int mid,
    unsigned int end) {
  int index_left = begin;
  int index_right = mid;

  std::vector<T> temp;
  temp.reserve(end - begin);
  std::fill(temp.begin(), temp.end(), std::numeric_limits<double>::infinity());
  int index_temp = 0;

  while (index_left <= mid - 1 && index_right <= end) {
    temp[index_temp++] = (data[index_left] < data[index_right]) ? data[index_left++] : data[index_right++];
  }
  while (index_left <= mid - 1) {
    temp[index_temp++] = data[index_left++];
  }
  while (index_right <= end) {
    temp[index_temp++] = data[index_right++];
  }

  index_temp = 0;
  while (begin < end) {
    data[begin++] = temp[index_temp++];
  }
}