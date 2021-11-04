import sort.merge_sort;

int main(void) {
  int data[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  merge_sort(data, 0, (sizeof(data) / sizeof(int)) - 1);

  int i = 0;
  return 0;
}