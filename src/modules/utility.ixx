export module utility;
// TODO: <=> not right;
export template <typename T>
concept Comparable = requires(T a, T b) {
  a > b;
  a < b;
  a == b;
  a <= b;
  a >= b;
};
export {
  template <typename T, size_t>
  struct remove_arrayref {
    using type = T;
  };
  template <typename T, size_t N>
  struct remove_arrayref<T(&)[N], N> {
    using type = T;
  };
}