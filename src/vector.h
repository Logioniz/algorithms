#ifndef __VECTOR_H_INCLUDED__
#define __VECTOR_H_INCLUDED__

#include <assert.h>

template<typename T>
class vector {
public:
    vector() {
        this->data = new T[4];
        this->size = 0;
        this->capacity = 4;
    }

    ~vector() {
        delete[] this->data;
    }

    int len() const {
        return this->size;
    }

    T operator[] (const int idx) const {
        assert(idx >= 0 && idx < this->size && this->data != 0);
        return this->data[idx];
    }

    T& operator[] (const int idx) {
        assert(idx >= 0 && idx < this->size && this->data != 0);
        return this->data[idx];
    }

    void push_back(const T& elem) {
        if (this->size >= this->capacity) {
            this->reallocate();
        }
        assert(this->size < this->capacity && this->data != 0);
        this->data[this->size++] = elem;
    }

    T pop_back() {
        assert(this->size > 0);
        return this->data[--this->size];
    }

    T& get_item(const int idx) const {
        assert(idx >= 0 && idx < this->size);
        return this->data[idx];
    }

    T& back() const {
        assert(this->size > 0);
        return this->data[this->size - 1];
    }

    T& front() const {
        assert(this->size > 0);
        return this->data[0];
    }

private:
    T* data;
    int size;
    int capacity;

    void reallocate() {
        assert(this->capacity > 0);
        T* new_data = new T[this->capacity << 1];
        for (int i = 0; i < this->size; ++i) {
            new_data[i] = this->data[i];
        }
        delete[] this->data;
        this->data = new_data;
        this->capacity <<= 1;
    }
};

#endif
