#ifndef __LIST_H__
#define __LIST_H__

template <typename T>
struct Node {
    Node(T data, Node* next = nullptr, Node* prev = nullptr)
        : m_data(data), m_next(next), m_prev(prev) {}

    T     m_data;
    Node* m_next;
    Node* m_prev;
};

template <typename T>
class List {
public:
    typedef T        value_type;
    typedef T&       reference_tpye;
    typedef const T& const_reference_type;

    class iterator;

public:
    List() : m_head(nullptr) {}
    ~List() {
        while (m_head != nullptr) {
            auto tmp = m_head->m_next;
            delete m_head;
            m_head = tmp;

            // auto tmp = m_head;
            // m_head   = m_head->m_next;
            // delete tmp;
        }
    }

    void push_back(const_reference_type data) {
        if (m_head == nullptr) {
            m_head = new Node<T>(data);
            return;
        } else {
            auto tmp = m_head;
            while (tmp->m_next != nullptr)
                tmp = tmp->m_next;

            tmp->m_next = new Node<T>(data, nullptr, tmp);
            return;
        }
    }
    void push_front(const_reference_type data) {
        if (m_head == nullptr) {
            m_head = new Node<T>(data);
            return;
        } else {
            auto tmp       = new Node<T>(data, m_head, nullptr);
            m_head->m_prev = tmp;
            m_head         = tmp;

            // m_head->m_prev = new Node<T>(data, m_head);
            // m_head         = m_head->m_prev;
            return;
        }
    }
    iterator begin() {
        return iterator(m_head);
    }
    iterator end() {
        return iterator(nullptr);
    }

private:
    Node<value_type>* m_head;
};

template <typename T>
class List<T>::iterator {
public:
    iterator(Node<T>* p) : m_elem(p) {}

    iterator& operator++() {
        m_elem = m_elem->m_next;
        return *this;
    }
    iterator& operator--() {
        m_elem = m_elem->m_prev;
        return *this;
    }

    T& operator*() {
        return m_elem->m_data;
    }
    Node<T>* operator->() {
        return m_elem;
    }

    bool operator==(const iterator& rhs) const {
        return m_elem == rhs.m_elem;
    }
    bool operator!=(const iterator& rhs) const {
        return m_elem != rhs.m_elem;
    }

private:
    Node<T>* m_elem;
};

#endif  // __LIST_H__