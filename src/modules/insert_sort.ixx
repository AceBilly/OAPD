export module sort.insert_sort;
import utility;

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
