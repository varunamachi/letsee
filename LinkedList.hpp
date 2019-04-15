#pragma once

namespace letsee {


template<typename ValueType>
class LinkedList {

public:

private:
    struct Node {
        ValueType *m_value;

        Node<ValueType> *m_next;

        Node<ValueType> *m_prev;

        Node <ValueType> *m_head;
    }

};

}