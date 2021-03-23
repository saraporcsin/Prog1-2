#ifndef __LIST_H__
#define __LIST_H__

#include <cstddef>
template <typename T>
struct Node {
public:
    Node(const T& data, Node* next = nullptr, Node* prev = nullptr)
        : m_data(data), m_next(next), m_prev(prev) {}

    T     m_data;
    Node* m_next;
    Node* m_prev;
};
template <typename T>
class List {
public:
    typedef T                 value_type;
    typedef value_type&       reference_type;
    typedef const value_type& const_reference_type;
    typedef value_type*       pointer_type;
    typedef size_t            size_type;
    typedef ptrdiff_t         difference_type;

    class iterator;

public:
    List() : m_head(nullptr) {}
    ~List() {
        while (m_head != nullptr) {
            auto tmp = m_head->m_next;
            delete m_head;
            m_head = tmp;
        }
    }

    void push_back(const_reference_type data) {
        if (m_head == nullptr) {
            m_head = new Node<value_type>(data);
        } else {
            Node<value_type>* tmp = m_head;

            while (tmp->m_next != nullptr)
                tmp = m_head->m_next;

            tmp->m_next = new Node<value_type>(data, nullptr, tmp);
        }
    }
    void push_front(const_reference_type data) {
        if (m_head == nullptr) {
            m_head = new Node<value_type>(data, m_head, nullptr);
        } else {
            Node<value_type>* tmp = new Node<value_type>(data, m_head, nullptr);
            m_head->m_prev        = tmp;
            m_head                = tmp;
        }
    }

    iterator begin() {
        return iterator(m_head);
    }
    iterator end() {
        return iterator(nullptr);
    }

private:
    Node<T>* m_head;
};

template <typename T>
class List<T>::iterator {
public:
    iterator(Node<T>* p) : elem(p) {}

    iterator& operator++() {
        elem = elem->m_next;
        return *this;
    }

    iterator& operator--() {
        elem = elem->m_prev;
        return *this;
    }

    T& operator*() {
        return elem->m_data;
    }

    Node<T>* operator->() {
        return elem;
    }

    Node<T>* ptr() const {
        return elem;
    }

    bool operator==(const iterator& b) const {
        return elem == b.elem;
    }

    bool operator!=(const iterator& b) const {
        return elem != b.elem;
    }

private:
    Node<T>* elem;
};

#endif  // __LIST_H__