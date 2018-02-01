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
        assert(idx >= 0 && idx < this->capacity && this->data != NULL);
        return this->data[idx];
    }

    T& operator[] (const int idx) {
        return this->data[idx];
    }

    void push_back(T elem) {
        if (this->size >= this->capacity) {
            this->reallocate();
        }
        assert(this->size < this->capacity && this->data != NULL);
        this->data[this->size++] = elem;
    }

    T pop_back() {
        assert(this->size > 0);
        return this->data[--this->size];
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
