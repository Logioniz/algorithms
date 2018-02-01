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
