#include <stdio.h>
#include <assert.h>

template<typename T>
class vector {
private:
    T* data;
    int size;
    int capacity;

    void reallocate() {
        T* new_data = new T[this->capacity << 1];
        for (int i = 0; i < this->size; ++i)
            new_data[i] = this->data[i];
        delete[] this->data;
        this->data = new_data;
        this->capacity <<= 1;
    }

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
};

template<typename T>
void print(vector<T>& arr) {
    for (int i = 0; i < arr.len(); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    print(v);
    v[4] = 10;
    print(v);
    return 0;
}
