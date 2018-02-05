#include <stdio.h>
#include "stack.h"
#include "vector.h"

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    printf("%d\n", s.is_empty());
    printf("%d\n", s.pop());
    printf("%d\n", s.pop());
    printf("%d\n", s.pop());
    printf("%d\n", s.is_empty());

    stack<int, vector<int> > s2;

    printf("%d\n", s2.is_empty());
    s2.push(10);
    s2.push(11);
    s2.push(12);
    printf("%d\n", s2.pop());
    printf("%d\n", s2.pop());
    printf("%d\n", s2.pop());
    printf("%d\n", s2.is_empty());

    return 0;
}
