//WeightedList.h - class definitions for a weighted list

#ifndef _WEIGHTEDLIST_H_
#define _WEIGHTEDLIST_H_

#include <iostream>

template<typename T>

class WeightedList {
    struct Node {
        T data;
        Node *next;

        explicit Node(const T &_data) {
            data = _data;
            next = nullptr;
        }
    };

    Node *front;
    int count{};
public:
    class iterator {
        friend class WeightedList;
        Node* current;

        explicit iterator(Node* node) : current(node) {}

    public:
        iterator& operator++() {
            current = current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator temp(current);
            current = current->next;
            return temp;
        }

        bool operator==(const iterator& rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const iterator& rhs) const {
            return current != rhs.current;
        }

        T& operator*() {
            return current->data;
        }
    };

    WeightedList() : front(nullptr), count(0) {}

    WeightedList(const WeightedList& rhs) : front(nullptr), count(0) {
        Node* temp = rhs.front;
        while (temp) {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    WeightedList& operator=(const WeightedList& rhs) {
        if (this == &rhs) {
            return *this;
        }

        clear();
        Node* temp = rhs.front;
        while (temp) {
            push_back(temp->data);
            temp = temp->next;
        }

        return *this;
    }

    WeightedList(WeightedList&& rhs) noexcept : front(rhs.front), count(rhs.count) {
        rhs.front = nullptr;
        rhs.count = 0;
    }

    WeightedList& operator=(WeightedList&& rhs) noexcept {
        if (this == &rhs) {
            return *this;
        }

        clear();
        front = rhs.front;
        count = rhs.count;
        rhs.front = nullptr;
        rhs.count = 0;

        return *this;
    }

    iterator begin() {
        return iterator(front);
    }

    iterator end() {
        return iterator(nullptr);
    }

    void push_back(const T& data) {
        Node* newNode = new Node(data);
        if (!front) {
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    }

    iterator search(const T& data) {
        Node* prev = nullptr;
        Node* cur = front;
        Node* prePrev = nullptr;

        while (cur) {
            if (cur->data == data) {
                if (prev && prePrev) {
                    prePrev->next = cur;
                    prev->next = cur->next;
                    cur->next = prev;
                } else if (prev) {
                    front = cur;
                    prev->next = cur->next;
                    cur->next = prev;
                }
                return iterator(cur);
            }
            prePrev = prev;
            prev = cur;
            cur = cur->next;
        }

        return end();
    }

    iterator erase(iterator it) {
        if (it == end()) {
            throw std::runtime_error("Cannot erase end iterator");
        }

        Node* prev = nullptr;
        Node* cur = front;

        while (cur) {
            if (cur == it.current) {
                if (prev) {
                    prev->next = cur->next;
                } else {
                    front = cur->next;
                }
                delete cur;
                count--;
                return iterator(prev ? prev->next : front);
            }
            prev = cur;
            cur = cur->next;
        }

        return end();
    }

    iterator erase(iterator begin, iterator end) {
        iterator it = begin;
        while (it != end) {
            it = erase(it);
        }
        return end;
    }

    bool empty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    ~WeightedList() {
        clear();
    }

private:
    void clear() {
        Node* temp = front;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        front = nullptr;
        count = 0;
    }
};
#endif// _WEIGHTEDLIST_H_