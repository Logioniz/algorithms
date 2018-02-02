#include <stdio.h>
#include "vector.h"
#include "smart_pointer.h"

// test on memory leak
int main() {
    for (int attempt = 0; attempt < 10; ++attempt) {
        smart_pointer<vector<smart_pointer<int> > > v(new vector<smart_pointer<int> >());
        for (int i = 0; i < 10000000; ++i) {
            v->push_back(smart_pointer<int>(new int(5)));
        }
        printf("Number of elements %d\n", v->len());
        // printf("Press enter");
        // getchar();
    }

    return 0;
}
