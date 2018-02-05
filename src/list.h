#ifndef __LIST_H_INCLUDED__
#define __LIST_H_INCLUDED__

#include <assert.h>

template<typename T>
class node {
public:
    node<T>* next;
    node<T>* prev;
    T data;

    explicit node(const T& elem) : next(0), prev(0), data(elem) { }
};

template<typename T>
class list {
public:
    list() : head(0), tail(0) { }

    ~list() {
        node<T>* cur = head;
        while (cur) {
            node<T>* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    void push_back(const T& elem) {
        if (this->tail == 0) {
            assert(this->head == 0);
            this->tail = this->head = new node<T>(elem);
            return;
        }
        assert(this->head != 0);
        node<T>* last = new node<T>(elem);
        last->prev = this->tail;
        this->tail->next = last;
        this->tail = last;
    }

    T pop_back() {
        assert(this->tail != 0);
        if (this->tail->prev == 0) {
            assert(this->tail == this->head);
            T data = this->tail->data;
            delete this->tail;
            this->tail = 0;
            this->head = 0;
            return data;
        }
        node<T>* prev = this->tail->prev;
        T data = this->tail->data;
        delete this->tail;
        this->tail = prev;
        this->tail->next = 0;
        return data;
    }

    void push_front(const T& elem) {
        if (this->head == 0) {
            assert(this->tail == 0);
            this->tail = this->head = new node<T>(elem);
            return;
        }
        assert(this->tail != 0);
        node<T>* first = new node<T>(elem);
        first->next = this->head;
        this->head->prev = first;
        this->head = first;
    }

    T pop_front() {
        assert(this->head != 0);
        if (this->head->next == 0) {
            assert(this->head == this->tail);
            T data = this->head->data;
            delete this->head;
            this->tail = 0;
            this->head = 0;
            return data;
        }
        node<T>* next = this->head->next;
        T data = this->head->data;
        delete this->head;
        this->head = next;
        this->head->prev = 0;
        return data;
    }

    bool is_empty() const {
        return this->head == 0;
    }

    T& back() {
        assert(this->tail != 0);
        return this->tail->data;
    }

    T& front() {
        assert(this->head != 0);
        return this->head->data;
    }

private:
    node<T>* head;
    node<T>* tail;
};

#endif
