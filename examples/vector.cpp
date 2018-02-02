#include <stdio.h>
#include "vector.h"

template<typename T>
void print(vector<T>& arr) {
    for (int i = 0; i < arr.len(); ++i) {
        printf("%.2f ", (float)arr[i]);
    }
    printf("\n");
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    print(v);
    v[2] = 10;
    print(v);

    v.get_item(3) = 123;
    printf("%d\n", v.get_item(3));

    v.back() = 321;
    printf("%d\n", v.back());
    v.front() = 234;
    printf("%d\n", v.front());

    vector<double> v2;
    v2.push_back(1.12);
    v2.push_back(2.34);
    v2.push_back(3.56);
    v2.push_back(4.78);
    print(v2);
    v2[2] = 10;
    print(v2);

    return 0;
}
