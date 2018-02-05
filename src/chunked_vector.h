#ifndef __CHUNKED_VECTOR_H_INCLUDED__
#define __CHUNKED_VECTOR_H_INCLUDED__

#include <assert.h>
#include <stdio.h>

template<typename T>
class chunk_node {
public:
    chunk_node<T>* next;
    chunk_node<T>* prev;
    T* data;

    chunk_node(int capacity, int is_end) {
        this->next = this->prev = 0;
        this->data = new T[capacity];
        this->tail = is_end ? capacity - 1 : -1;
        this->head = is_end ? capacity : 0;
        this->capacity = capacity;
    }

    ~chunk_node() {
        delete[] this->data;
    }

    void push_back(const T& elem) {
        assert(this->tail + 1 < capacity && this->data != 0);
        this->data[++this->tail] = elem;
    }

    void push_front(const T& elem) {
        assert(this->head > 0 && this->data != 0);
        this->data[--this->head] = elem;
    }

    T pop_back() {
        assert(this->head <= this->tail && this->data != 0);
        return this->data[this->tail--];
    }

    T pop_front() {
        assert(this->head <= this->tail && this->data != 0);
        return this->data[this->head++];
    }

    T& back() {
        assert(this->tail < this->capacity);
        return this->data[this->tail];
    }

    T& front() {
        assert(this->head >= 0);
        return this->data[this->head];
    }

    bool is_tail_max() {
        return this->tail >= capacity - 1;
    }

    bool is_head_min() {
        return this->head <= 0;
    }

    bool is_empty() {
        return this->head > this->tail;
    }

private:
    int head;
    int tail;
    int capacity;
};

template<typename T>
class chunked_vector {
public:
    chunked_vector() : head(0), tail(0), chunk_capacity(1024) { }
    chunked_vector(int _chunk_capacity) : head(0), tail(0), chunk_capacity(_chunk_capacity) { }

    ~chunked_vector() {
        if (head == 0 && tail == 0) {
            return;
        }

        chunk_node<T>* cur = this->head;
        chunk_node<T>* prev = cur->prev;
        while (cur) {
            chunk_node<T>* next = cur->next;
            delete cur;
            cur = next;
        }

        cur = prev;
        while (cur) {
            chunk_node<T>* prev = cur->prev;
            delete cur;
            cur = prev;
        }
    }

    void push_back(const T& elem) {
        if (this->tail == 0) {
            assert(this->head == 0);
            this->tail = this->head = new chunk_node<T>(this->chunk_capacity, 0);
            this->tail->push_back(elem);
            return;
        }

        assert(this->head != 0);

        if (this->tail->is_tail_max()) {
            chunk_node<T>* chunk;
            if (this->tail->next == 0) {
                chunk = new chunk_node<T>(this->chunk_capacity, 0);
            } else {
                chunk = this->tail->next;
            }
            chunk->push_back(elem);
            chunk->prev = this->tail;
            this->tail->next = chunk;
            this->tail = chunk;
            return;
        }

        this->tail->push_back(elem);
    }

    void push_front(const T& elem) {
        if (this->head == 0) {
            assert(this->tail == 0);
            this->tail = this->head = new chunk_node<T>(this->chunk_capacity, 1);
            this->tail->push_front(elem);
            return;
        }

        assert(this->tail != 0);

        if (this->head->is_head_min()) {
            chunk_node<T>* chunk;
            if (this->head->prev == 0) {
                chunk = new chunk_node<T>(this->chunk_capacity, 1);
            } else {
                chunk = this->head->prev;
            }
            chunk->push_front(elem);
            chunk->next = this->head;
            this->head->prev = chunk;
            this->head = chunk;
            return;
        }

        this->head->push_front(elem);
    }

    T pop_back() {
        assert(this->tail != 0 && !this->tail->is_empty());

        T val = this->tail->pop_back();

        if (this->tail->is_empty() && this->tail != this->head) {
            if (this->tail->next) {
                delete this->tail->next;
                this->tail->next = 0;
            }
            this->tail = this->tail->prev;
        }

        return val;
    }

    T pop_front() {
        assert(this->head != 0 && !this->head->is_empty());

        T val = this->head->pop_front();

        if (this->head->is_empty() && this->tail != this->head) {
            if (this->head->prev) {
                delete this->head->prev;
                this->head->prev = 0;
            }
            this->head = this->head->next;
        }


        return val;
    }

    T& back() {
        assert(this->tail != 0 && !this->tail->is_empty());
        return this->tail->back();
    }

    T& front() {
        assert(this->head != 0 && !this->head->is_empty());
        return this->head->front();
    }

    bool is_empty() {
        if (this->head == 0) {
            return true;
        }
        if (this->head == this->tail && this->head->is_empty()) {
            return true;
        }
        return false;
    }

private:
    chunk_node<T>* head;
    chunk_node<T>* tail;
    int chunk_capacity;
};

#endif
