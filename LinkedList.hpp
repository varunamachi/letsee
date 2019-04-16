#pragma once

#include <memory>

namespace letsee {

template <typename ValueType,
          typename = typename std::enable_if<
              std::is_default_constructible_v<ValueType>>::value>
class LinkedList {

public:
  using SizeType = std::size_t;

private:
  template <typename V> struct Node {

    V m_value;

    Node<V> *m_next;

    Node<V> *m_prev;

    Node<V> *m_head;
  };

  std::unique_ptr<Node<ValueType>> m_head;

  void add(const ValueType &value) {}

  void insert(SizeType index, const ValueType &value) {}

  void remove(SizeType index) {}

  const ValueType &get() const {}
};

} // namespace letsee