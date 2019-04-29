#pragma once

#include <memory>
#include <type_traits>

namespace letsee {

template <typename V> struct Node {

  V m_value;

  Node<V> *m_next;

  Node<V> *m_prev;

  Node<V> *m_head;
};

template <typename ValueType> class LinkedList {

public:
  using SizeType = std::size_t;

  LinkedList() {
    // init head
    // assign last to head
  }

  void add(const ValueType &value) {
    auto node = new Node<ValueType>(value);
    auto temp = m_last;
    temp->m_next = node;
  }

  void insert(SizeType index, const ValueType &value) {}

  void remove(SizeType index) {}

  const ValueType &get() const {}

  void print() {}

private:
  std::unique_ptr<Node<ValueType>> m_head;

  Node<ValueType> *m_last;
};

} // namespace letsee
