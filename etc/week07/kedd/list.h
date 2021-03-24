#ifndef __LIST_H__
#define __LIST_H__

template <typename T>
struct Node {
    Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
        : m_data(data), m_prev(prev), m_next(next){};

    T     m_data;
    Node* m_prev;
    Node* m_next;
};

template <typename T>
class List {
public:
    typedef T                 value_type;
    typedef value_type&       reference;
    typedef const value_type& const_reference;

    class iterator;

public:
    List() : m_head(nullptr) {}
    ~List() {
        while (m_head != nullptr) {
            auto tmp = m_head;
            m_head   = m_head->m_next;
            delete tmp;

            // Alternatív mód
            // auto tmp = m_head->m_next;
            // delete m_head;
            // m_head = tmp;
        }
    }

    void push_back(const_reference data) {
        if (m_head == nullptr) {
            // ugyanez
            // m_head = new Node<value_type>(data, nullptr, nullptr);
            m_head = new Node<value_type>(data);

            return;
        } else {
            Node<value_type>* tmp = m_head;

            while (tmp->m_next != nullptr)
                tmp = tmp->m_next;

            tmp->m_next = new Node<value_type>(data, tmp, nullptr);
            return;
        }
    }
    void push_front(const_reference data) {
        if (m_head == nullptr) {
            // ugyanez
            // m_head = new Node<value_type>(data, nullptr, nullptr);
            m_head = new Node<value_type>(data);

            return;
        } else {
            auto tmp       = new Node<value_type>(data, nullptr, m_head);
            m_head->m_prev = tmp;
            m_head         = tmp;

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
    iterator(Node<T>* var) : elem(var) {}

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
    Node<T>* ptr() {
        return elem;
    }
    bool operator==(const iterator& other) const {
        return elem == other.elem;
    }
    bool operator!=(const iterator& other) const {
        return elem != other.elem;
    }

private:
    Node<T>* elem;
};

#endif  // __LIST_H__