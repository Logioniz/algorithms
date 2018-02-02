#include <stdio.h>
#include "list.h"

int main() {
    list<int> v;

    v.push_back(1);
    printf("%d\n", v.back());

    v.push_front(2);
    printf("%d\n", v.front());

    printf("%d\n", v.empty());

    printf("%d\n", v.pop_back());
    printf("%d\n", v.pop_front());

    printf("%d\n", v.empty());

    // test on memory leak
    {
        for (int attempt = 0; attempt < 4; ++attempt) {
            if (attempt) {
                printf("Check memory and press enter");
                getchar();
            }

            list<int> v;
            for (int i = 0; i < 10000000; ++i) {
                if (i % 2) {
                    v.push_front(i);
                } else {
                    v.push_back(i);
                }
            }
        }

        printf("Check memory and press enter");
        getchar();

        for (int i = 0; i < 10000000; ++i) {
            if (i % 2) {
                v.push_front(i);
            } else {
                v.push_back(i);
            }
        }

        for (int i = 0; i < 10000000; ++i) {
            if (i % 2) {
                v.pop_front();
            } else {
                v.pop_back();
            }
        }
    }

    printf("Check memory and press enter");
    getchar();

    return 0;
}
