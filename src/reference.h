#ifndef __REFERENCE_H_INCLUDED__
#define __REFERENCE_H_INCLUDED__

#include <assert.h>

class reference {
public:
    reference() {
        this->count = 0;
    }

    void increase() {
        ++this->count;
    }

    void decrease() {
        assert(this->count > 0);
        --this->count;
    }

    int value() {
        return this->count;
    }

protected:
    int count;
};

#endif
