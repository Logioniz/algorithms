#ifndef __SMART_POINTER_H_INCLUDED__
#define __SMART_POINTER_H_INCLUDED__

#include "reference.h"

template<typename T>
class smart_pointer {
public:
    smart_pointer() {
        this->data = 0;
        this->ref = new reference();
        this->ref->increase();
    }

    explicit smart_pointer(T* data) {
        this->data = data;
        this->ref = new reference();
        this->ref->increase();
    }

    smart_pointer(const smart_pointer<T>& sp) {
        this->data = sp.data;
        this->ref = sp.ref;
        ref->increase();
    }

    ~smart_pointer() {
        this->ref->decrease();
        if (this->ref->value() == 0) {
            delete this->data;
            delete this->ref;
        }
    }

    T& operator* () const {
        return *this->data;
    }

    T* operator-> () const {
        return this->data;
    }

    smart_pointer<T>& operator= (const smart_pointer<T>& sp) {
        if (this != &sp) {
            this->ref->decrease();
            if (this->ref->value() == 0) {
                delete this->data;
                delete this->ref;
            }
            this->data = sp.data;
            this->ref = sp.ref;
            ref->increase();
        }
        return *this;
    }

protected:
    T* data;
    reference* ref;
};

#endif
