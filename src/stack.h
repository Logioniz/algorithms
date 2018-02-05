#ifndef __STACK_H_INCLUDED__
#define __STACK_H_INCLUDED__

#include <assert.h>
#include "chunked_vector.h"

template<typename T, typename Seq = chunked_vector<T> >
class stack {
public:
    explicit stack(Seq* c = new Seq()) : container(c) { }

    ~stack() {
        delete this->container;
    }

    void push(const T& elem) {
        this->container->push_back(elem);
    }

    T pop() {
        return this->container->pop_back();
    }

    T& top() const {
        return this->container->back();
    }

    bool is_empty() const {
        return this->container->is_empty();
    }

protected:
    Seq* container;
};

#endif
