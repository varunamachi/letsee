#pragma once

#include <memory>
#include <type_traits>

namespace letsee {

template <typename ValueType,
          typename = typename std::enable_if<
              std::is_default_constructible<ValueType>::value>::value>
class LinkedList {

private:
    template <typename V>
    struct Node {


        V m_value;

        Node<V> *m_next;

        Node<V> *m_prev;

        Node<V> *m_head;
  };

  std::unique_ptr<LinkedList::Node<ValueType>> m_head;

  LinkedList::Node<ValueType> *m_last;

public:
    using SizeType = std::size_t;

    LinkedList() {
        //init head
        //assign last to head
    }

    void add(const ValueType &value) {
//        auto node = new Node(value);
//        auto temp = m_last;
//        temp->m_next = node;
    }

    void insert(SizeType index, const ValueType &value) {}

    void remove(SizeType index) {}

    const ValueType &get() const {}
};

} // namespace letsee
